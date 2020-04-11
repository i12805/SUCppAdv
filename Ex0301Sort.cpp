//============================================================================
// Name        : Ex0301Sort.cpp
// Author      : Muncho
// Version     :
// Copyright   : GPL
// Description : Ex0301Sort in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Company.h"

using namespace std;

bool lessById(const Company& a, const Company& b) {
	return a.getId() < b.getId();
}

bool lessByName(const Company& a, const Company& b) {
	return a.getName() < b.getName();
}

int main() {
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);

	std::ostringstream input;

	std::string line;
	std::getline(std::cin, line);
	while (line != "end") {
		input << line << std::endl;
		std::getline(std::cin, line);
	}

	std::string strCriteria;
	std::cin >> strCriteria;
	while( (strCriteria != "id") && (strCriteria != "name") )
	{
		std::cout << strCriteria << " not valid criteria." << std::endl;
		std::cin >> strCriteria;
	}

	std::vector<Company> asCompanies;
	std::string companyDelimiter = "\n";
	size_t startPos = 0u;
	size_t endPos = input.str().find(companyDelimiter);

	while(endPos != std::string::npos)
	{
		std::string compStr = input.str().substr(startPos, endPos - startPos);
		std::string attrDelimiter = " ";
		size_t start = 0;
		size_t end = compStr.find(attrDelimiter);
		int id;
		std::string name;

		name = compStr.substr(start, end - start);

		start = end + attrDelimiter.length();
		end = compStr.find(attrDelimiter, start);

		std::stringstream ss;
		ss << compStr.substr(start, end - start);
		ss >> id;

		Company aCompany = Company(id, name);
		asCompanies.push_back(aCompany);

		startPos = endPos + companyDelimiter.length();
		endPos = input.str().find(companyDelimiter, startPos);
	}
#if defined(DEBUG)
	for(Company c : asCompanies)
	{
		std::cout << c.toString() << std::endl;
	}
#endif
	if(strCriteria == "id")
	{
//		std::cout << "Criteria: " << strCriteria << std::endl;
		std::sort(asCompanies.begin(), asCompanies.end(), lessById);
	}
	else if(strCriteria == "name")
	{
//		std::cout << "Criteria: " << strCriteria << std::endl;
		std::sort(asCompanies.begin(), asCompanies.end(), lessByName);
	}
	else
	{
		std::cout << "No valid criteria." << std::endl;
	}

	for(std::vector<Company>::iterator it = asCompanies.begin(); it != asCompanies.end(); ++it)
	{
		cout << it->toString() << endl; // prints Sorted
	}

	return 0;
}
