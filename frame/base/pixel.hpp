#pragma once

#include <iostream>

namespace moob {
    constexpr uint32_t kDefaultAlpha = 0xFF;
    constexpr uint32_t kDefaultRgba = (kDefaultAlpha << 24);

    class Pixel
    {
    private:
        uint32_t rgba_;
    public:
        Pixel(uint32_t rgba) : rgba_(rgba) {};
        Pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
        virtual ~Pixel();
    };
}