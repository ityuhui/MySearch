#include "stdafx.h"
#include "ObjectOp.h"
#include "FileSearch.h"
#include "DirSearch.h"
#include <boost/filesystem.hpp>
#include <boost/format.hpp>
#include "log.h"
using namespace MySearch;

namespace boostfs = boost::filesystem;

ObjectOp::ObjectOp(const std::string &path):
    mOSearch(nullptr)
{
    checkObject(path);
}


ObjectOp::~ObjectOp()
{
}

bool
ObjectOp::search(const std::string &regex)
{
    return mOSearch->search(regex);
}

void
ObjectOp::checkObject(const std::string &path)
{
    boostfs::path p(path);
    if (boostfs::exists(p)) {
        if (boostfs::is_regular_file(p)) {
            mOSearch = std::make_shared<FileSearch>(path);
        } else if (boostfs::is_directory(p)) {
            mOSearch = std::make_shared<DirSearch>(path);
        }
    } else {
        std::string msg = std::string(__FUNCTION__) + ": " + path + " does not exist.";
        log_notify(msg);
        throw std::runtime_error(msg);
    }
}