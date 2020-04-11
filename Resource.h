#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include "ResourceType.h"

namespace SoftUni
{

	
	    using SoftUni::ResourceType;
	    
	    class Resource
	    {
		public:
		    int s32Id;
		    enum ResourceType eResourceType;
		    std::string strLink;
		    
	     //   public:
		    Resource(){};
		    Resource(int id, enum ResourceType type, std::string link):s32Id(id),eResourceType(type), strLink(link){};
		    
		    enum ResourceType getType() const
		    {
			return(this->eResourceType);
		    }

		    bool operator< (const Resource& other) const
		    {
			    return(this->s32Id < other.s32Id);
		    }


		    

	    };
	    
	    std::istream& operator>> (std::istream& in, Resource& res)
	    {
		std::istream_iterator<std::string> isit(in);
		std::stringstream oss0(*isit);
		std::stringstream oss1(*(++isit));
		std::stringstream oss2(*(++isit));

		oss0 >> res.s32Id;
	//	oss1 >> res.eResourceType;
		oss2 >> res.strLink;

#if 1 
		if(oss1.str() == "Presentation")
		{
			res.eResourceType = PRESENTATION;
		}
		else if(oss1.str() == "Demo")
		{
			res.eResourceType = DEMO;
		}
		else if(oss1.str() == "Video")
		{
			res.eResourceType = VIDEO;
		}
		else
		{
			std::cout << "wrong resource type" << std::endl;
		}
#endif		
		return(in);
	    }		    
	   
	    std::ostream& operator<< (std::ostream& out, const Resource& res) 
	    {
		out << res.s32Id << ' ' << res.eResourceType << ' ' << res.strLink;
		
		return(out);
	    }		    
 // end of namspace Resource
}//end of namespace SoftUni

#endif // !RESOURCE_H 
