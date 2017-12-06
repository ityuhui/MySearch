#pragma once
#include <string>
#include <memory>

namespace MySearch
{
    extern void log_error(const std::string &msg);
    extern void log_warning(const std::string &msg);
    extern void log_notify(const std::string &msg);
    extern void log_info(const std::string &msg);
    extern void log_debug(const std::string &msg);

    class log
    {
    public:
        ~log();
        static std::shared_ptr<log> getInstance();

        typedef int LogLevelInt;
        enum class LogLevel {
            LOG_ERROR ,
            LOG_WARNING,
            LOG_NOTIFY,
            LOG_INFO,
            LOG_DEBUG
        };

        void setLogLevel(LogLevel glvl);
        void print(LogLevel glvl, const std::string &msg);
        void print(LogLevel glvl, const char *msg);

    private:
        log();
        
        LogLevelInt transLevelID2Int(LogLevel glvl);
        LogLevelInt mCurrentLogLevel;

    };


}

