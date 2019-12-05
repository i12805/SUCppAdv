/*
 * MakeCompany.h
 *
 *  Created on: 6.12.2019 ?.
 *      Author: DnDUser
 */

#ifndef MAKECOMPANY_H_
#define MAKECOMPANY_H_

#include <string>
#include <sstream>
#include <iostream>
#include <memory>
#include "Company.h"

std::shared_ptr<Company> makeCompany(std::vector<std::string> properties)
{
	std::stringstream ss;
	ss << properties[0];
	int s32propSize = properties.size();
	int id = 0;
	ss >> id;
	std::string name = properties[1];
	std::pair<char, char> employee;
	std::vector<std::pair<char, char> > emplyees; // = {{'', ''}, {'', ''}};

	if(s32propSize > 2)
	{

		for(int i = 2; i < s32propSize; i++)
		{
			//char* chVec = (char*)(&properties[i]);
			employee.first = properties[i][0];
			employee.second = properties[i][1];
			emplyees.push_back(employee);
		}
	}

	//Company* newCompany = new Company(id, name, emplyees); // new makes explicitly type of: Company*, not shared!
	return(std::make_shared<Company>(id, name, emplyees));
}


#endif /* MAKECOMPANY_H_ */
