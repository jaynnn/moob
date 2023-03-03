#pragma once

#include "frame/mgr/pixel_mgr.hpp"

using namespace moob;

void PixelMgr::Tick() 
{
    Pos pos{0, 0};
    Pixel p(pos, 255, 99, 71, 0);
    Draw(p);
}

void PixelMgr::Init() 
{
}

void PixelMgr::Draw(Pixel p)
{

}
