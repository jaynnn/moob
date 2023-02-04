#pragma once

#include <iostream>

class Sprite {
protected:
    struct Pos
    {
        uint32_t x;
        uint32_t y;
    };
    
public:
    Sprite();
    Sprite(Pos pos);
    virtual void Tick() = 0;
    virtual ~Sprite() = default;
};