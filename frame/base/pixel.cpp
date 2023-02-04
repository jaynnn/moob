

#include "pixel.hpp"

moob::Pixel::Pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    rgba_ = moob::kDefaultRgba;
    rgba_ = rgba_ | r | g << 8 | b << 16 | a << 24;
}

moob::Pixel::~Pixel() {
}

void moob::Pixel::Tick() {
    
}