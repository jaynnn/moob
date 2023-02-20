#pragma once

#include <queue>

namespace moob {
    template <typename T>
    class Pipe {
        virtual ~Pipe() = default;
    public:
        void Push(const T x);
        T Pop();
        T Peek();
        bool Empty();
        void Clear();
        size_t Size();
    private:
        std::queue<T> pipe_;
    };
}