#pragma once

#include "frame/interface/mgr_interface.hpp"

//线程管理类
class ThreadMgr : MgrInterface
{ 
    public: ThreadMgr() {}; 
    ~ThreadMgr(){}; 
    //向线程池添加任务 
    void AddTask(std::function<void()> task) { 
        std::unique_lockstd::mutex lock(mutex_); 
        task_.push_back(task); 
    }

    //启动线程池，开始执行任务
    void Start(int num)
    {
        for (int i = 0; i < num; i++)
            threads_.push_back(std::thread(&ThreadMgr::Run, this));
    }

    //等待所有线程完成任务
    void Wait()
    {
        for (auto &t : threads_)
            t.join();
    }
    private: 
    //每个线程都执行的任务 
    void Run() { 
        while (true) { 
            task_t task; 
            { 
                std::unique_lockstd::mutex lock(mutex_); 
                if (task_.empty()) return; 
                task = task_.back(); 
                task_.pop_back(); 
            } 
            task(); 
        } 
    }

    private: 
        using task_t = std::function<void()>; 
        std::vectorstd::thread threads_; 
        std::vector task_; 
        std::mutex mutex_; 
};