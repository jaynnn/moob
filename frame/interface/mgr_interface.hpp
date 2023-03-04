#pragma once

#include <iostream>
#include <functional>

namespace moob
{
    class MgrInterface
    {
    private:
        
    public:
        virtual ~MgrInterface() = default;
        virtual void Init() = 0;
    };
}