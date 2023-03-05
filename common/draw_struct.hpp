#pragma once

#include <vector>

#include "common/pos_struct.hpp"

namespace moob 
{
    enum DrawI 
    {
        PIXEL,
        LINE,
        TRANGLE,
    };

    struct DrawInfo
    {
        uint32_t i;      //instruction
        std::vector<moob::Pos> v = {};  //positions
        DrawInfo(uint32_t i = DrawI::PIXEL, std::vector<moob::Pos> v = {Pos{0,0}}): i(i), v(v) {};
        virtual ~DrawInfo() = default;
    };
}
