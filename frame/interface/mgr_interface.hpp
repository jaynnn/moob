#pragma once

#include <iostream>

class MgrInterface
{
private:
    
public:
    virtual ~MgrInterface() = default;
    virtual int Init() = 0;
};