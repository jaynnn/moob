#pragma once

#include <sstream>

namespace moob 
{
    enum LogLevel { DEBUG = 0, INFO, WARN, ERROR };

    class Loging 
    {
        public: 
        Loging(LogLevel logLevel = INFO) : logLevel_(logLevel) {}
        Loging(int logLevel = LogLevel::INFO) : logLevel_(static_cast<LogLevel>(logLevel)) {}
        ~Loging() {}
        void SetLogLevel(LogLevel logLevel)
        {
            logLevel_ = logLevel;
        }

        template<typename T>
        void PrintLog(LogLevel logLevel, T& t)
        {
            if (logLevel < logLevel_)
            {
                return;
            }
            std::ostringstream oss;
            oss << t;
            std::cout << oss.str() << std::endl;
        }
        private: LogLevel logLevel_; 
    };
}