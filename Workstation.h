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
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <iostream>
#include <string>
#include <deque>
#include "Station.h"
#include "CustomerOrder.h"
namespace sdds
{
	extern std::deque<CustomerOrder> g_pending;
	extern std::deque<CustomerOrder> g_completed;
	extern std::deque<CustomerOrder> g_incomplete;

	class Workstation : public Station
	{
		std::deque<CustomerOrder> m_orders{};
		Workstation *m_pNextStation{nullptr};

	public:
		Workstation(const std::string &str);
		Workstation(const Workstation &workstation) = delete;
		Workstation &operator=(const Workstation &workstation) = delete;
		Workstation(Workstation &&workstation) = delete;
		Workstation &operator=(Workstation &&workstation) = delete;
		void fill(std::ostream &os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation *station = nullptr);
		Workstation *getNextStation() const;
		void display(std::ostream &os) const;
		Workstation &operator+=(CustomerOrder &&newOrder);
		bool empty() const;
	};
}
#endif // !SDDS_WORKSTATION_H