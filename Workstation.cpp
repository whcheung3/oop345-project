/*------------------------------------------------------------------------------------------
Project Milestone 3
--------------------------------------------------------------------------------------------
Name   : Wing Ho Cheung
Email  : whcheung3@myseneca.ca
ID     : 158387209
Section: ZAA
Date   : 7 Aug 2022
--------------------------------------------------------------------------------------------
Module:   Workstation
Filename: Workstation.h
--------------------------------------------------------------------------------------------
I confirm that I am the only author of this file and the content was created entirely by me.
------------------------------------------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <deque>
#include "Workstation.h"
#include "Station.h"
#include "CustomerOrder.h"
using namespace std;
namespace sdds
{
	deque<CustomerOrder> g_pending{};
	deque<CustomerOrder> g_completed{};
	deque<CustomerOrder> g_incomplete{};

	Workstation::Workstation(const string &str) : Station(str) {}

	void Workstation::fill(ostream &os)
	{
		if (!m_orders.empty())
			m_orders.front().fillItem(*this, os);
	}

	bool Workstation::attemptToMoveOrder()
	{
		bool result{false};
		if (!m_orders.empty())
		{
			if (m_orders.front().isItemFilled(getItemName()) || getQuantity() == 0)
			{
				if (m_pNextStation)
					*m_pNextStation += move(m_orders.front());

				else if (m_orders.front().isOrderFilled()) // no next station
					g_completed.push_back(move(m_orders.front()));

				else // no next station
					g_incomplete.push_back(move(m_orders.front()));

				m_orders.pop_front();
				result = true; // order has been moved
			}
		}
		return result;
	}

	void Workstation::setNextStation(Workstation *station) { m_pNextStation = station; }

	Workstation *Workstation::getNextStation() const { return m_pNextStation; }

	void Workstation::display(ostream &os) const
	{
		os << getItemName() << " --> ";
		if (m_pNextStation)
			os << m_pNextStation->getItemName() << endl;
		else
			os << "End of Line" << endl;
	}

	Workstation &Workstation::operator+=(CustomerOrder &&newOrder)
	{
		m_orders.push_back(move(newOrder));
		return *this;
	}

	bool Workstation::empty() const { return m_orders.empty(); }
}