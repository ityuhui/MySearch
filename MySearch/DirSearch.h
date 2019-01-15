#pragma once

#include "ObjectSearch.h"

namespace MySearch
{

    class DirSearch : public ObjectSearch
    {
    public:
        DirSearch(const std::string &);
        ~DirSearch();
        virtual bool search(const std::string &) ;
    private:
        std::string mDirName;
    };

}

