#pragma once

#include <mutex>

namespace moob 
{
    template <typename T>
    class Singleton
    {
    public:

        static T* GetInstance()
        {
            if(nullptr == instance_)
            {
                std::lock_guard<std::mutex> lock(mutex_); 
                if (nullptr == instance_) 
                { 
                    instance_ = new T;
                }
            }
            return instance_;
        }

    private:
        Singleton() {};
        ~Singleton() {};
        static T* instance_;
        static std::mutex mutex_;
    };
    template <typename T>
    T* Singleton<T>::instance_ = nullptr;
}