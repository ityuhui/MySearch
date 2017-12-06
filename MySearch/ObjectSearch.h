#ifndef _OBJECTSEARCH_H 
#define _OBJECTSEARCH_H


#include <string>

namespace MySearch
{
    class ObjectSearch
    {
    public:
        virtual bool search(const std::string &) = 0 ;
    };

}

#endif