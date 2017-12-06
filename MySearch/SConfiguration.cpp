#include "stdafx.h"
#include "SConfiguration.h"

using namespace MySearch;

#define DEFAULT_MAX_SIZE_OF_FILE 10*1024*1024 // The files that less than 10MB will be searched. 

SConfiguration::SConfiguration():
    mMaxSizeOfFile(DEFAULT_MAX_SIZE_OF_FILE)
{
    init();
}


std::shared_ptr<SConfiguration> MySearch::SConfiguration::getInstance()
{
    static std::shared_ptr<SConfiguration> mInstance = std::shared_ptr<SConfiguration>(new SConfiguration());
    
    return mInstance;
}

SConfiguration::~SConfiguration()
{
}

void
SConfiguration::init()
{
}

long long
SConfiguration::getMaxSizeOfFile()
{
    return mMaxSizeOfFile;
}

