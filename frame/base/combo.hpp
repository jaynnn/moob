#pragma once

#include <functional>

#include "common/draw_struct.hpp"
#include "frame/base/camera.hpp"
#include "frame/base/canvas.hpp"
#include "frame/util/pipe.hpp"

namespace moob
{
    class Combo
    {
    private:
        Pipe<std::function<void()>> tasks_;
        Pipe<DrawInfo> draw_flow_;
    public:
        Combo();
        ~Combo();
    };
}