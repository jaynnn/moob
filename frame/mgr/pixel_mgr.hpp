#pragma once

#include "frame/interface/mgr_interface.hpp"
#include "frame/base/pixel.hpp"
#include "common/draw_struct.hpp"

namespace moob {
    class PixelMgr : public MgrInterface
    {
    private:
        
    public:
        virtual void Tick() final;
        virtual int Init() final;
        void Draw(Pixel p);
    };
}
