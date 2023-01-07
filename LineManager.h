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
Filename: LineManager.h
--------------------------------------------------------------------------------------------
I confirm that I am the only author of this file and the content was created entirely by me.
------------------------------------------------------------------------------------------*/
#ifndef SDDS_LINE_MANAGER_H
#define SDDS_LINE_MANAGER_H
#include <iostream>
#include <string>
#include <vector>
#include "Workstation.h"
namespace sdds
{
	class LineManager
	{
		std::vector<Workstation *> m_activeLine{};
		size_t m_cntCustomerOrder{};
		Workstation *m_firstStation{nullptr};

	public:
		LineManager(const std::string &file, const std::vector<Workstation *> &stations);
		void reorderStations();
		bool run(std::ostream &os);
		void display(std::ostream &os) const;
	};
}
#endif // !SDDS_LINE_MANAGER_H