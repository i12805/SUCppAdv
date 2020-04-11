#ifndef SUMOFVECTORS_H
#define SUMOFVECTORS_H

#include <string>
#include <vector>

std::vector<std::string> operator+ (const std::vector<std::string>& vec1, const std::vector<std::string>& vec2)
{
	std::vector<std::string>* pvec3 = new std::vector<std::string>();
	for(unsigned int i=0; i < vec2.size(); i++)
	{
		pvec3->push_back(vec1[i]+' '+vec2[i]);
	}

	return(*pvec3);
}

#endif // SUMOFVECTORS_H
