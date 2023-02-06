#pragma once

#include <iostream>

#include "common/pos_struct.hpp"

namespace moob {
    class Sprite {
    protected:
        moob::Pos pos_ = {0};
    public:
        Sprite();
        Sprite(moob::Pos pos);
        virtual void Tick() = 0;
        virtual ~Sprite() = default;
    };
}