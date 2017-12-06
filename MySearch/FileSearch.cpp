#include "stdafx.h"
#include "FileSearch.h"
#include "SConfiguration.h"
#include "log.h"
#include <fstream>
#include <iostream>
#include <boost/regex.hpp>


using namespace MySearch;

FileSearch::FileSearch(const std::string &fileName):
    mFileName(fileName),
    mFileInfo(std::make_shared<FileInfo>(fileName))
{
}


FileSearch::~FileSearch()
{
}

bool
FileSearch::checkFile()
{
    bool rc = true;
    if (mFileInfo->getFileSize() > SConfiguration::getInstance()->getMaxSizeOfFile() ) {
        rc = false;
        log_error("FileOp::checkFile: the size of file execeeds the max size that is supported.");
    }
    return rc;
}

bool
FileSearch::search(const std::string &regex)
{
    std::string func = "FileOp::search";
    log_debug(func + ": File: " + mFileName + " Regex: " + regex);
    bool rc = false;

    if (checkFile()) {
        rc = regexSearch(regex);
    }
    return rc;
}

bool
FileSearch::regexSearch(const std::string &regexp)
{
    std::ifstream f(mFileName);
    std::string line;

    boost::regex reg(regexp);

    int lineNum = 1;
    while (std::getline(f, line)) {
        if (boost::regex_search(line, reg)) {
            std::cout << "Line " << lineNum << ", in file " << mFileName << ", " << line << std::endl;
        }
        lineNum++;
    }

    f.close();

    return true;
}