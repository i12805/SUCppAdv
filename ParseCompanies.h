/*
 * ParseCompanies.h
 *
 *  Created on: 6.12.2019 ?.
 *      Author: DnDUser
 */

#ifndef PARSECOMPANIES_H_
#define PARSECOMPANIES_H_

#include <sstream>
#include <string.h>
#include <memory>
#include <map>
#include "Company.h"

Company* parseUniqueCompanies(std::string str, int &count, std::string (*pfParseFn)(const Company& c))
{
	std::vector<Company> compVec; // = new std::vector<Company*>; 
	std::map<std::string, Company> aMap;
	std::string companyDelimiter = "\n";
	auto startPos = 0u;
	auto endPos = str.find(companyDelimiter);
	while(endPos != std::string::npos)
	{
		std::string compStr = str.substr(startPos, endPos - startPos);
		std::string attrDelimiter = " ";
		auto start = 0;
		auto end = compStr.find(attrDelimiter);
		int id;
		std::string name;
		
		std::stringstream ss;
		ss << compStr.substr(start, end - start);
		ss >> id;
		start = end + attrDelimiter.length();
		end = compStr.find(attrDelimiter, start);
		name = compStr.substr(start, end - start);

		Company* shit = new Company(id, name);
		std::string sss = pfParseFn(*shit);
		std::cout << "Parse ret.: " << sss << std::endl;
		aMap.insert(sss, shit);
		
		startPos = endPos + companyDelimiter.length();
		endPos = str.find(companyDelimiter, startPos);
	}
	count = compVec.size();
	std::cout << "bye; count:" << count << std::endl;

	std::map<std::string, Company>::iterator it = aMap.begin();
	while(it != aMap.end())
	{
		std::cout << it->first << ":" << (it->second).toString() << std::endl;
		it++;
	}

	return(nullptr);
}



#endif /* PARSECOMPANIES_H_ */
