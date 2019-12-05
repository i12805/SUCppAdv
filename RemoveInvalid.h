/*
 * RemoveInvalid.h
 *
 *  Created on: 4.12.2019 ?.
 *      Author: DnDUser
 */

#ifndef REMOVEINVALID_H_
#define REMOVEINVALID_H_

#include "Company.h"

void removeInvalid(std::list<Company*>& comp)
{
	std::cout << "size at start: " << comp.size() << std::endl;
	std::list<Company*>::iterator it = comp.begin();
	while(it != comp.end())
	{
		if((*it)->getId() < 0)
		{
			std::cout << "neg: " << (*it)->toString() << " ";
			delete *it;
			it = comp.erase(it);
		}
		else
		{
			it++;
		}
	}
	std::cout << "bye" << std::endl;
	std::cout << "size at the end: " << comp.size() << std::endl;
	for(Company* c : comp)
	{
		std::cout << c->toString() << std::endl << std::endl;
	}
}

#endif /* REMOVEINVALID_H_ */
