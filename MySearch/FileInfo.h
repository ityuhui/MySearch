#pragma once
#include <string>
namespace MySearch
{

    class FileInfo
    {
    public:
        FileInfo(const std::string &filename);
        ~FileInfo();
        long long getFileSize();
    private:
        struct _stat mInfo;
    };

}

