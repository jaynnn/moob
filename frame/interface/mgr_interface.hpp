#pragma once

#include <iostream>
#include <functional>

class MgrInterface
{
private:
    
public:
    virtual ~MgrInterface() = default;
    virtual int Init() = 0;
};