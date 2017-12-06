#pragma once

#include <memory>
#include "SConfiguration.h"

namespace MySearch
{

    class Search
    {
    public:
        Search();
        ~Search();

        void execute(const std::string &regex, const std::string &fileName);
    private:
    };


}

