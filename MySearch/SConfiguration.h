#pragma once

#include <vector>
#include <string>
#include <memory>

namespace MySearch
{

    class SConfiguration
    {
    public:
        static std::shared_ptr<SConfiguration> getInstance();
        ~SConfiguration();
        long long getMaxSizeOfFile();
    private:
        SConfiguration();
        void init();
        std::vector<std::string> mSupportFiles;
        long long mMaxSizeOfFile; // the unit is kb

    };

} // namespace MySearch

