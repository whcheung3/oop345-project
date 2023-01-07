/*------------------------------------------------------------------------------------------
Project Milestone 3
--------------------------------------------------------------------------------------------
Name   : Wing Ho Cheung
Email  : whcheung3@myseneca.ca
ID     : 158387209
Section: ZAA
Date   : 7 Aug 2022
--------------------------------------------------------------------------------------------
Module:   Utilities
Filename: Utilities.cpp
--------------------------------------------------------------------------------------------
I confirm that I am the only author of this file and the content was created entirely by me.
------------------------------------------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Utilities.h"
using namespace std;
namespace sdds
{
	char Utilities::m_delimiter{};

	void Utilities::setFieldWidth(size_t newWidth) { m_widthField = newWidth; }

	size_t Utilities::getFieldWidth() const { return m_widthField; }

	string Utilities::extractToken(const string &str, size_t &next_pos, bool &more)
	{
		string result{};
		size_t delimPos{};

		if (str[next_pos] == m_delimiter) // report an exception if a delimiter is found at next_pos
		{
			more = false;
			throw "ERROR: No token.";
		}

		result = str.substr(next_pos);					// extract the token from next_pos to the end first
		delimPos = result.find(m_delimiter);			// find the delimiter position in the token
		result = str.substr(next_pos, delimPos);		// extract the token from next_pos to the delimiter position
		result.erase(0, result.find_first_not_of(" ")); // erase spaces at the beginning
		result.erase(result.find_last_not_of(" ") + 1); // erase spaces at the end
		next_pos += delimPos + 1;						// update next_pos as the next token position

		if (delimPos == string::npos) // end extract if no more delimiter found
			more = false;

		if (m_widthField < result.length()) // update m_widthField if less than the token size
			m_widthField = result.length();

		return result;
	}

	void Utilities::setDelimiter(char newDelimiter) { m_delimiter = newDelimiter; }

	char Utilities::getDelimiter() { return m_delimiter; }
}
