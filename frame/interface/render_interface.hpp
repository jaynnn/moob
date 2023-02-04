#pragma once

#include "frame/base/pixel.hpp"

namespace moob {
    class RenderInterface
    {
    private:
        
    public:
        virtual ~RenderInterface() = default;
        virtual void Draw(int32_t x, int32_t, Pixel pixel) = 0;
    };
    
}