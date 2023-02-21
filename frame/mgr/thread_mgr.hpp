#pragma once

#include <vector>
#include <mutex>

#include "frame/interface/mgr_interface.hpp"

//线程管理类
namespace moob {
    class ThreadMgr : MgrInterface
    { 
        public: 
            ThreadMgr() {}; 
            ~ThreadMgr(){}; 
            void AddTask(std::function<void()> task);
            void Start(int num);
            void Wait();
            int Init();
        private: 
            void Run();
        private: 
            using task_t = std::function<void()>; 
            std::vector<std::thread> threads_; 
            std::vector<std::function<void()>> task_; 
            std::mutex mutex_;
    };
}