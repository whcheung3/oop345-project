/*------------------------------------------------------------------------------------------
Project Milestone 3
--------------------------------------------------------------------------------------------
Name   : Wing Ho Cheung
Email  : whcheung3@myseneca.ca
ID     : 158387209
Section: ZAA
Date   : 7 Aug 2022
--------------------------------------------------------------------------------------------
Module:   CustomerOrder
Filename: CustomerOrder.h
--------------------------------------------------------------------------------------------
I confirm that I am the only author of this file and the content was created entirely by me.
------------------------------------------------------------------------------------------*/
#ifndef SDDS_CUSTOMER_ORDER_H
#define SDDS_CUSTOMER_ORDER_H
#include <iostream>
#include <string>
#include "Station.h"
namespace sdds
{
	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder
	{
		std::string m_name{};
		std::string m_product{};
		size_t m_cntItem{};
		Item** m_lstItem{};
		static size_t m_widthField;

	public:
		CustomerOrder();
		CustomerOrder(const std::string &str);
		CustomerOrder(const CustomerOrder& customerOrder);
		CustomerOrder& operator=(const CustomerOrder& customerOrder) = delete;
		CustomerOrder(CustomerOrder&& customerOrder) noexcept;
		CustomerOrder& operator=(CustomerOrder&& customerOrder) noexcept;
		~CustomerOrder();
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif // !SDDS_CUSTOMER_ORDER_H