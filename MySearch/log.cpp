#include "stdafx.h"
#include "log.h"

#include <iostream>

using namespace MySearch;

log::log():
    mCurrentLogLevel(transLevelID2Int(LogLevel::LOG_NOTIFY))
{
}


log::~log()
{
}

std::shared_ptr<MySearch::log>
log::getInstance()
{
    static std::shared_ptr<log> instance = std::shared_ptr<log>(new log());
    return instance;
}

void
log::setLogLevel(log::LogLevel glvl)
{
    mCurrentLogLevel = transLevelID2Int(glvl);
}

log::LogLevelInt
log::transLevelID2Int(LogLevel glvl)
{
    LogLevelInt lvl = 3; // LOG_NOTIFY;

    if ( LogLevel::LOG_ERROR == glvl) {
        lvl = 1;
    } else if ( LogLevel::LOG_WARNING == glvl) {
        lvl = 2;
    } else if ( LogLevel::LOG_NOTIFY == glvl) {
        lvl = 3;
    } else if ( LogLevel::LOG_INFO == glvl) {
        lvl = 4;
    } else if ( LogLevel::LOG_DEBUG == glvl) {
        lvl = 5;
    }

    return lvl;
}

void
log::print(LogLevel glvl, const std::string & msg)
{
    if (transLevelID2Int(glvl) <= mCurrentLogLevel) {
        std::cout << msg << std::endl;
    }
}


void
log::print(LogLevel glvl, const char *msg)
{
    if (transLevelID2Int(glvl) <= mCurrentLogLevel) {
        std::cout << msg << std::endl;
    }
}

void MySearch::log_error(const std::string & msg)
{
    log::getInstance()->print(log::LogLevel::LOG_ERROR, msg);
}

void MySearch::log_warning(const std::string & msg)
{
    log::getInstance()->print(log::LogLevel::LOG_WARNING, msg);
}

void MySearch::log_notify(const std::string & msg)
{
    log::getInstance()->print(log::LogLevel::LOG_NOTIFY, msg);
}

void MySearch::log_info(const std::string & msg)
{
    log::getInstance()->print(log::LogLevel::LOG_INFO, msg);
}

void MySearch::log_debug(const std::string & msg)
{
    log::getInstance()->print(log::LogLevel::LOG_DEBUG, msg);
}
