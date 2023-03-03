#include "frame/mgr/thread_mgr.hpp"

using namespace moob;

//向线程池添加任务 
void ThreadMgr::AddTask(std::function<void()> task, int group, int threa_num)
{ 
    std::unique_lock<std::mutex> lock(mutex_); 
    group2tasks_[group].push_back(task);
    group2thread_num_[group] = threa_num;
}

//启动线程池，开始执行任务
void ThreadMgr::Start()
{
    for (const auto& [group, threa_num] : group2thread_num_) {
        for (int i = 0; i <threa_num; i++)
            threads_.push_back(std::thread(&ThreadMgr::Run, this, group));
    }
}

//等待所有线程完成任务
void ThreadMgr::Wait()
{
    for (auto &t : threads_)
        t.join();
}

//每个线程都执行的任务 
void ThreadMgr::Run(int group)
{
    while (true)
    { 
        task_t task;
        std::unique_lock<std::mutex> lock(mutex_);
        if (group2tasks_[group].empty()) return;
        task = group2tasks_[group].back();
        group2tasks_[group].pop_back();
        task();
    } 
}

void ThreadMgr::Init()
{
}