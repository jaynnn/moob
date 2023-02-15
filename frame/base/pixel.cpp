

#include "pixel.hpp"

using namespace moob;

Pixel::Pixel(Pos pos, uint8_t r, uint8_t g, uint8_t b, uint8_t a) 
{
    rgba_ = kDefaultRgba;
    rgba_ = rgba_ | r | g << 8 | b << 16 | a << 24;
}

Pixel::~Pixel() 
{
}

void Pixel::Tick() 
{
    
}