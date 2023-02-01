#pragma once

#include <iostream>

class Sprite
{
private:
    uint32_t x;
    uint32_t y;
public:
    Sprite();
    Sprite(uint32_t x, uint32_t y);
    virtual void Tick() = 0;
    virtual ~Sprite() = default;
};