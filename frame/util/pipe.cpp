#include "frame/util/pipe.hpp"

using namespace moob;

template <typename T>
void Pipe<T>::Push(const T x)
{
    pipe_.push(x);
}

template <typename T>
T Pipe<T>::Pop()
{
    T x = pipe_.front(); 
    pipe_.pop(); 
    return x;
}

template <typename T>
T Pipe<T>::Peek()
{
    return pipe_.front();
}

template <typename T>
bool Pipe<T>::Empty()
{
    return pipe_.empty();
}

template <typename T>
void Pipe<T>::Clear()
{
    while(!pipe_.empty()) 
    { 
        pipe_.pop(); 
    }
}

template <typename T>
size_t Pipe<T>::Size()
{
    return pipe_.size();
}