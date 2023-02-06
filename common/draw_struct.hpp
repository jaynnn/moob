#pragma once

#include <iostream>
#include <vector>

#include "common/pos_struct.hpp"

namespace moob {
    enum DrawI {
        PIXEL,
        LINE,
        TRANGLE,
    };

    struct DrawInfo
    {
        uint32_t i = DrawI::PIXEL;      //instruction
        std::vector<moob::Pos> v = {};  //positions
    };
}
