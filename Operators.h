#ifndef OPERATORS_H
#define OPERATORS_H

#include <ostream>
#include <vector>
#include <string>
#include <sstream>

#include <iterator>

std::ostream& operator<< (std::ostream& out, std::vector<std::string>& str) 
{
	std::ostringstream os;
	std::copy(str.begin(), str.end(), std::ostream_iterator<std::string>(os));
	out << os.str();
	return(out);
}

std::vector<std::string>& operator<< (std::vector<std::string>& out, std::string& str)
{
	out.push_back(str+'\n');
	return(out);
}

std::string& operator+ (const std::string& str, const int& in)
{
	std::ostringstream sout;
	sout << str << in;
	std::string* s = new std::string(sout.str());
	
	return(*s);
}

#endif // !OPERATORS_H
