#include "logger.h"

#include <spdlog/spdlog.h>

Logger& Logger::instance()
{
    static Logger logger;
    return logger;
}

void Logger::info(const std::string& message)
{
    spdlog::info("{}", message);
}

void Logger::warning(const std::string& message)
{
    spdlog::warn("{}", message);
}

void Logger::error(const std::string& message)
{
    spdlog::error("{}", message);
}