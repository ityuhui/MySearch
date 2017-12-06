#include "stdafx.h"
#include "DirSearch.h"
#include "FileSearch.h"
#include <boost/filesystem.hpp>

using namespace MySearch;
namespace boostfs = boost::filesystem;

DirSearch::DirSearch(const std::string &path):
    mDirName(path)
{
}


DirSearch::~DirSearch()
{
}

bool
DirSearch::search(const std::string &reg)
{
    bool rc = false;
    boostfs::recursive_directory_iterator itEnd;
    for (boostfs::recursive_directory_iterator itor(mDirName.c_str()); itor != itEnd; ++itor) {
        if (boostfs::is_regular_file(itor->status())) {
            std::shared_ptr<FileSearch> fs = std::make_shared<FileSearch>(itor->path().string());
            rc = fs->search(reg);
        } 
        /*
        * because recursive_directory_iterator can retrive sub-directory, 
        * do not need call search recursively
        */
        /*else if(boostfs::is_directory(itor->status())){
            std::shared_ptr<DirSearch> ds = std::make_shared<DirSearch>(itor->path().string());
            rc = ds->search(reg);
        }*/ 
    }
    return rc;
}
