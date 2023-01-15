#pragma once

#include <iostream>

namespace moob {
    constexpr uint32_t kDefaultRgba = 0xFFFFFFFF;
    constexpr uint32_t kDefaultRgb = (kDefaultRgba >> 8);
    constexpr uint8_t kDefaultAlpha = (kDefaultRgba << 24);

    class Pixel
    {
    private:
        uint32_t rgba_;
    public:
        Pixel(uint32_t rgba) : rgba_(rgba) {};
        Pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
        ~Pixel();
    };
}