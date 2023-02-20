#pragma once

#include "frame/interface/mgr_interface.hpp"

//线程管理类
class ThreadMgr : MgrInterface
{ 
    public: 
        ThreadMgr() {}; 
        ~ThreadMgr(){}; 
    private: 
        void AddTask(std::function<void()> task);
        void Start(int num);
        void Wait();
        void Run();
    private: 
        using task_t = std::function<void()>; 
        std::vectorstd::thread threads_; 
        std::vector task_; 
        std::mutex mutex_; 
};