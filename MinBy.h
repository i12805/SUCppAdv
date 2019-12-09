/*
 * MinBy.h
 *
 *  Created on: 4.12.2019 ?.
 *      Author: DnDUser
 */

#ifndef MINBY_H_
#define MINBY_H_

#include <vector>
#include <string>

std::string minBy(std::vector<std::string> vals, bool (*compareTwo)(const std::string& a, const std::string& b))
{
	std::string retVal = vals[0];

	if(vals.size() == 1)
	{
		return(retVal);
	}
//	for(std::vector<std::string>::iterator it = vals.begin(); it != vals.end(); ++it)
	{
//		std::cout << *it << " ";
	}

//	std::cout << std::endl;
	
	for(unsigned int i=1; i< vals.size(); i+=1)
	{
//		std::cout << "compare " << retVal << " and " << vals[i] << "; wins ";
		if(compareTwo(retVal, vals[i]))
		{
//			retVal = vals[i];
		}
		else
		{
			retVal = vals[i];
		}
//		std::cout << retVal << std::endl;
	}

//	std::cout << retVal << std::endl;
	return(retVal);
}

#endif /* MINBY_H_ */
