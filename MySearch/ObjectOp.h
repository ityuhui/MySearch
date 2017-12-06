#pragma once

#include <string>
#include "ObjectSearch.h"
#include <memory>

namespace MySearch
{

    class ObjectOp
    {
    public:
        ObjectOp(const std::string &path);
        ~ObjectOp();
        bool search(const std::string &);
    private:
        void checkObject(const std::string &path);
        std::shared_ptr<ObjectSearch> mOSearch;
    };

}