#pragma once

#include <vector>

#include "common/pos_struct.hpp"

namespace moob 
{
    class Camera
    {
    private:
        Pos pos_;
        size_t width_;
        size_t height_;
        uint32_t canvas_id_;
    public:
        Camera();
        Camera(Pos pos, int w, int h) : pos_(pos), width_(w), height_(h) {};
        void SetCanvas(uint32_t id);
        virtual ~Camera();
    };
}
