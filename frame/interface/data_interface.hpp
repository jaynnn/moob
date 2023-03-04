#pragma once

namespace moob
{
    template <typename T>
    class DataInterface
    {
    private:
        
    public:
        virtual ~DataInterface() = default;
        virtual T Pop() = 0;
        virtual void Push(T data) = 0;
    };

}