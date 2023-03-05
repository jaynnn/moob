#pragma once

#include <iostream>

#include "frame/base/sprite.hpp"
#include "common/pos_struct.hpp"

namespace moob 
{
    constexpr uint32_t kDefaultAlpha = 0xFF;
    constexpr uint32_t kDefaultRgba = (kDefaultAlpha << 24);

    class Pixel : public Sprite
    {
    private:
        uint32_t rgba_;
        Pos pos_;
    public:
        Pixel(Pos pos, uint32_t rgba) : pos_(pos), rgba_(rgba) {};
        Pixel(Pos pos, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
        virtual ~Pixel();

        virtual void Tick() final;
    };
}