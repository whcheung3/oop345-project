/*------------------------------------------------------------------------------------------
Project Milestone 3
--------------------------------------------------------------------------------------------
Name   : Wing Ho Cheung
Email  : whcheung3@myseneca.ca
ID     : 158387209
Section: ZAA
Date   : 7 Aug 2022
--------------------------------------------------------------------------------------------
Module:   LineManager
Filename: LineManager.cpp
--------------------------------------------------------------------------------------------
I confirm that I am the only author of this file and the content was created entirely by me.
------------------------------------------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Station.h"
#include "Utilities.h"
#include "LineManager.h"
using namespace std;
namespace sdds
{
	LineManager::LineManager(const string &file, const vector<Workstation *> &stations)
	{
		try
		{
			ifstream in(file);
			m_cntCustomerOrder = g_pending.size(); // update the total number of orders
			while (in)
			{
				Utilities ut;
				bool more{true};
				size_t pos{};
				string str{};
				string first{};
				string next{};

				getline(in, str);
				first = ut.extractToken(str, pos, more);
				if (more)
					next = ut.extractToken(str, pos, more);

				for_each(stations.begin(), stations.end(), [&](Workstation *firstWorkstation)
						 {
						if (firstWorkstation->getItemName() == first)
						{
							for_each(stations.begin(), stations.end(), [&](Workstation* nextWorkstation)
								{
									if (nextWorkstation->getItemName() == next)
										firstWorkstation->setNextStation(nextWorkstation);
								});
							m_activeLine.push_back(firstWorkstation); // the first station in the assembly line
						} });

				m_firstStation = m_activeLine.front();
			}
		}
		catch (...) // report error if something goes wrong
		{
			throw "ERROR: LineManager Constructor";
		}
	}

	void LineManager::reorderStations()
	{
		vector<Workstation *> tempVec;
		Workstation *tempWorkstation{nullptr};
		size_t cnt{};
		while (cnt < m_activeLine.size())
		{
			for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation *workstation)
					 { if (workstation->getNextStation() == tempWorkstation)
						{
						tempVec.push_back(workstation);
						tempWorkstation = workstation;
						cnt++;
					} });
		}
		reverse(tempVec.begin(), tempVec.end()); // reorder the workstations
		m_firstStation = tempVec[0];
		m_activeLine = tempVec; // store the reordered collection
	}

	bool LineManager::run(ostream &os)
	{
		bool result{true};
		static size_t cnt{};
		os << "Line Manager Iteration: " << ++cnt << endl;

		if (!g_pending.empty()) // move only one order to the line
		{
			*m_firstStation += move(g_pending.front());
			g_pending.pop_front();
		}

		for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation *workstation)
				 { workstation->fill(os); }); // one fill operation

		for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation *workstation)
				 { workstation->attemptToMoveOrder(); }); // move an order down the line

		for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation *workstation)
				 { if (!workstation->empty())  
				 	result = false; });

		return result; // true if all customer orders have been filled or cannot be filled
	}

	void LineManager::display(ostream &os) const
	{
		for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation *workstation)
				 { workstation->display(os); });
	}
}