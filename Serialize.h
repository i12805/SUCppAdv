/*
 * Serialize.h
 *
 *  Created on: 9.12.2019 ?.
 *      Author: DnDUser
 */

#ifndef SERIALIZE_H_
#define SERIALIZE_H_

#include <memory>
#include "Company.h"

byte* serializeToMemory(std::string comps, size_t &nums)
{
	std::vector<byte>* byteArray = new std::vector<byte>;
	byteArray->push_back(0);
	std::istringstream companiesIS(comps);
	Company aCompany;
	while(companiesIS >> aCompany)
	{
		byteArray->push_back( (byte)aCompany.getId() );

		for(char c : aCompany.getName())
		{
			byteArray->push_back(c);
		}
		byteArray->push_back('\0');
		byteArray->push_back( (byte)aCompany.getEmployees().size() );
		for(size_t idx = 0; idx < aCompany.getEmployees().size(); idx++)
		{
			byteArray->push_back( aCompany.getEmployees()[idx].first );
		        byteArray->push_back( aCompany.getEmployees()[idx].second);
		}
		byteArray->at(0) += 1;
	}
	nums = byteArray->size();

	return(&(byteArray->front()));
}


#endif /* SERIALIZE_H_ */
