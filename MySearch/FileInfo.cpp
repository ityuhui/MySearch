#include "stdafx.h"
#include "FileInfo.h"

using namespace MySearch;

FileInfo::FileInfo(const std::string &filename)
{
    memset(&mInfo, 0, sizeof(mInfo));
    _stat(filename.c_str(), &mInfo);
}


FileInfo::~FileInfo()
{
}


long long
MySearch::FileInfo::getFileSize()
{
    return mInfo.st_size;
}
