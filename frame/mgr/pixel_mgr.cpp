#pragma once

#include "frame/mgr/pixel_mgr.hpp"

using namespace moob;

void PixelMgr::Tick() 
{
    Pos pos{0, 0};
    Pixel p(pos, 255, 99, 71, 0);
    Draw(p);
}

int PixelMgr::Init() 
{
	return 1;
}

void PixelMgr::Draw(Pixel p)
{

}
