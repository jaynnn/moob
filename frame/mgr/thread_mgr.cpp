#include "frame/mgr/thread_mgr.hpp"

using namespace moob;

//向线程池添加任务 
void AddTask(std::function<void()> task) { 
    std::unique_lockstd::mutex lock(m_mutex); 
    m_task.push_back(task); 
}

//启动线程池，开始执行任务
void Start(int num)
{
    for (int i = 0; i < num; i++)
        m_threads.push_back(std::thread(&ThreadManager::Run, this));
}

//等待所有线程完成任务
void Wait()
{
    for (auto &t : m_threads)
        t.join();
}