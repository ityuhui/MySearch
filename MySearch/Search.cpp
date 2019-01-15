#include "stdafx.h"
#include "Search.h"
#include "log.h"
#include "ObjectOp.h"

using namespace MySearch;

Search::Search()
{
}


Search::~Search()
{
}

void
Search::execute(const std::string &regex, const std::string &path)
{
    try {
        ObjectOp oo(path);
        oo.search(regex);
    }
    catch (...) {

    }
}

