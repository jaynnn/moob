#pragma once

#include <vector>
#include <mutex>
#include <map>

#include "frame/interface/mgr_interface.hpp"

//线程管理类
namespace moob {
    class ThreadMgr : MgrInterface
    { 
        public: 
            ThreadMgr() {}; 
            ~ThreadMgr(){}; 
            void AddTask(std::function<void()> task, int group = 1, int threa_num = 1);
            void Start();
            void Wait();
            int Init();
        private: 
            void Run(int group);
        private: 
            using task_t = std::function<void()>;
            std::vector<std::thread> threads_;
            std::map<int, std::vector<std::function<void()>>> group2tasks_;
            std::map<int, int> group2thread_num_;
            std::mutex mutex_;
    };
}