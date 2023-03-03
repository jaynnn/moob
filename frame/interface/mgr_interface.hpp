#pragma once

#include <iostream>
#include <functional>

class MgrInterface
{
private:
    
public:
    virtual ~MgrInterface() = default;
    virtual void Init() = 0;
};