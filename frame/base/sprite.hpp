#pragma once

#include <iostream>

namespace moob {
    struct Pos
    {
        uint32_t x;
        uint32_t y;
    };

    class Sprite {
    protected:
        Pos pos_ = {0};
    public:
        Sprite();
        Sprite(Pos pos);
        virtual void Tick() = 0;
        virtual ~Sprite() = default;
    };
}