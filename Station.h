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
Filename: Station.h
--------------------------------------------------------------------------------------------
I confirm that I am the only author of this file and the content was created entirely by me.
------------------------------------------------------------------------------------------*/
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>
#include <string>
namespace sdds
{
	class Station
	{
		int m_stationID{};
		std::string m_itemName{};
		std::string m_desc{};
		size_t m_nextSerialNum{};
		size_t m_numItems{};
		static size_t m_widthField;
		static int id_generator;

	public:
		Station(const std::string &str);
		const std::string &getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream &os, bool full) const;
	};
}
#endif // !SDDS_STATION_H