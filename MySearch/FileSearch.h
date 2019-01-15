#pragma once

#include <string>
#include <memory>
#include "ObjectSearch.h"
#include "FileInfo.h"

namespace MySearch
{

    class FileSearch : public ObjectSearch
    {
    public:
        FileSearch(const std::string &);
        ~FileSearch();
        virtual bool search(const std::string &) ;
    private:
        bool checkFile();
        bool regexSearch(const std::string &regex);
        std::shared_ptr<FileInfo> mFileInfo;
        std::string mFileName;
    };

}

