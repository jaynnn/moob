#pragma once

class BaseMgr
{
private:
    
public:
    virtual ~BaseMgr() = default;
    virtual void Tick() = 0;
};