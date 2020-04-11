#ifndef LECTURE_H
#define LECTURE_H

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "ResourceType.h"
#include "Resource.h"

namespace SoftUni
{
	using SoftUni::Resource;
	using SoftUni::ResourceType;
    
    class Lecture
    {
        public:
            std::vector<Resource> vecRess;
	                
            Lecture(){}
            
            void vAddResource(Resource& res)
            {
		unsigned int i;
		unsigned int found = 0;
		for(i = 0; i < this->vecRess.size(); i++)
		{
			if(res.s32Id == vecRess[i].s32Id)
			{
				found = 1;
				this->vecRess[i].strLink = res.strLink;
				break;
			}
		}
		
		if(!found)
		{             
		     this->vecRess.push_back(res);
		}

		std::sort(this->vecRess.begin(), this->vecRess.end());
            }
            
            std::vector<Resource>::iterator begin()
            {
                return(this->vecRess.begin());
            }
            
            std::vector<Resource>::iterator end()
            {
                return(this->vecRess.end());
            }
            
            int operator[](enum ResourceType type)
            {
		    int count = 0;
		    unsigned int i;
		    for(i = 0; i < this->vecRess.size(); i++)
		    {
			    if(type == vecRess[i].getType())
			    {
				    count += 1;
			    }
		    }
                return(count);
            }
            

    }; // end of class Lecture
    
    Lecture operator<< (Lecture& lect, Resource& res)
    {
        lect.vAddResource(res);
	return(lect);
    }
    
    std::vector<ResourceType> operator<<(std::vector<ResourceType>& vrct, Lecture& lect)
    {
    	/*add resourse type to a ResourscType vector */
	unsigned int i;
	unsigned int found = 0; /* Video | Demo | Presentation */

    	for(i = 0; i < lect.vecRess.size(); i++)
    	{
	    if( (PRESENTATION == lect.vecRess[i].getType()) &&
			    !(found & 1) )
	    {
		vrct.push_back(PRESENTATION);
		found |= 1;
	    }
	    else if( (DEMO == lect.vecRess[i].getType()) &&
                    	    !(found & 2) )
	    {
		vrct.push_back(DEMO);
		found |= 2;

	    }
	    else if( (VIDEO == lect.vecRess[i].getType()) &&
                    	    !(found & 4) )
	    {
		vrct.push_back(VIDEO);
		found |= 4;

	    }

	    if(found == 7) break;
	}

	std::sort(vrct.begin(), vrct.end());

	return(vrct);
    }
} // end of SoftUni namespace
#endif /* LECTURE_H */
