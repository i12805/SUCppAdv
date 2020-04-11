/*
 * StringConcatenator.cpp
 *
 *  Created on: 15.03.2020 ã.
 *      Author: xxx
 */

#include <iostream>
#include <sstream>
#include <string>
#include "StringConcatenator.h"
#include "Defines.h"

StringConcatenator::StringConcatenator(){};
StringConcatenator::~StringConcatenator(){};

std::string StringConcatenator::concatenate(const ConcatenateStrategy strategy,
								const char * 			  left,
								const size_t 			  leftSize,
								const char * 			  right,
								const size_t 		      rightSize) const
{
	std::stringstream result;
	size_t i, j;

	if(strategy == ConcatenateStrategy::LEFT_1_RIGHT_1)
	{
		for(i = 0; i < leftSize; i++)
		{
			if(i < rightSize)
			{
				result << left[i] << right[i];
			}
			else
			{
				result << left[i];
			}
		}

		for(j = i; j < rightSize; j++) // add the rest of right if longer
		{
			result << right[j];
		}

	}
	else if(strategy == ConcatenateStrategy::LEFT_1_RIGHT_2)
	{
		j = 0;
		for(i = 0; i < leftSize; i++)
		{
			if(j < rightSize)
			{
				result << left[i] << right[j++] << right[j++];
			}
			else
			{
				result << left[i];
			}
		}

		for(; j < rightSize; j++) // add the rest of right if longer
		{
			result << right[j];
		}
	}
	else if((strategy == ConcatenateStrategy::LEFT_2_RIGHT_1))
	{
		j = 0;
		for(i = 0; i < rightSize; i++)
		{
			if(j < leftSize)
			{
				result << left[j++] << left[j++] << right[i];
			}
			else
			{
				result << left[i];
			}
		}

		for(; j < leftSize; j++) // add the rest of right if longer
		{
			result << left[j];
		}
	}
	else
	{
		std::cout << "Strategy not valid." << std::endl;
	}

	return(result.str());
}


