#pragma once

#include "frame/interface/mgr_interface.hpp"
#include "frame/base/pixel.hpp"

namespace moob {
    class RenderMgrInterface : public MgrInterface
    {
    private:
        
    public:
        virtual ~RenderMgrInterface() = default;
        virtual void Init() = 0;
        virtual void Tick() = 0;
        virtual void Draw(int32_t x, int32_t, Pixel pixel) = 0;
    };
    
}