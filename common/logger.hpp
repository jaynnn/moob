#pragma once

#include <mutex>
#include <iostream>
#include <vector>

// 日志等级 [0 1 2 3] == [debug info warning error]
namespace moob
{
    class Logger 
    {
        public: 
            static Logger& GetInstance() 
            { 
                static Logger instance; 
                return instance; 
            }

            template<typename... Args>
            void Log(int level, const Args&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                if (level < log_level_)
                    return;
                Print(args...);
                std::cout << std::endl;
            }

            void SetLogLevel(int level = 1)
            {
                log_level_ = level;
            }
        private: 
            Logger() { } 
            Logger(const Logger&) = delete; 
            Logger& operator=(const Logger&) = delete; 
            ~Logger() { }

            template<typename T, typename... Args>
            void Print(const T& arg, const Args&... args)
            {
                Print(args...);
            }

            // 结束递归
            template<typename T>
            void Print(const T& arg)
            {
                std::ostringstream oss;
                oss << arg;
                std::cout << oss.str() << std::endl;
            }
    private: 
        std::mutex mutex_; 
        int log_level_; 
    };
}