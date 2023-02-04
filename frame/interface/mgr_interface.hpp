#pragma once

class MgrInterface
{
private:
    
public:
    virtual ~MgrInterface() = default;
    virtual int Init() = 0;
    virtual void Tick() = 0;
};