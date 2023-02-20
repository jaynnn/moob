#include "frame/mgr/thread_mgr.hpp"

using namespace moob;

//向线程池添加任务 
void ThreadMgr::AddTask(std::function<void()> task)
{ 
    std::unique_lockstd::mutex lock(mutex_); 
    task_.push_back(task); 
}

//启动线程池，开始执行任务
void ThreadMgr::Start(int num)
{
    for (int i = 0; i < num; i++)
        threads_.push_back(std::thread(&ThreadManager::Run, this));
}

//等待所有线程完成任务
void ThreadMgr::Wait()
{
    for (auto &t : threads_)
        t.join();
}

//每个线程都执行的任务 
void ThreadMgr::Run() 
{ 
    while (true) 
    { 
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