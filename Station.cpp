/*------------------------------------------------------------------------------------------
Project Milestone 3
--------------------------------------------------------------------------------------------
Name   : Wing Ho Cheung
Email  : whcheung3@myseneca.ca
ID     : 158387209
Section: ZAA
Date   : 7 Aug 2022
--------------------------------------------------------------------------------------------
Module:   Station
Filename: Station.cpp
--------------------------------------------------------------------------------------------
I confirm that I am the only author of this file and the content was created entirely by me.
------------------------------------------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"
using namespace std;
namespace sdds
{
	size_t Station::m_widthField{};

	int Station::id_generator{};

	Station::Station(const std::string &str)
	{
		Utilities ut;
		bool more{true};
		size_t pos{};

		m_stationID = ++id_generator; // store current value of id_generator in m_stationID and then increment id_generator
		m_itemName = ut.extractToken(str, pos, more);
		m_nextSerialNum = stoi(ut.extractToken(str, pos, more));
		m_numItems = stoi(ut.extractToken(str, pos, more));

		if (m_widthField < ut.getFieldWidth()) // update m_widthField to the maximum field width
			m_widthField = ut.getFieldWidth();

		m_desc = ut.extractToken(str, pos, more);
	}

	const string &Station::getItemName() const { return m_itemName; }

	size_t Station::getNextSerialNumber() { return m_nextSerialNum++; }

	size_t Station::getQuantity() const { return m_numItems; }

	void Station::updateQuantity()
	{
		if (m_numItems > 0)
			m_numItems--;
	}

	void Station::display(ostream &os, bool full) const
	{
		os << right << setw(3) << setfill('0') << m_stationID << " | "
		   << left << setw(m_widthField + 1) << setfill(' ') << m_itemName << " | "
		   << right << setw(6) << setfill('0') << m_nextSerialNum << " | ";

		if (full)
			os << right << setw(4) << setfill(' ') << m_numItems << " | "
			   << m_desc;

		os << endl;
	}
}