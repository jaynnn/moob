#pragma once

#include "frame/mgr/base_mgr.hpp"
#include "frame/base/pixel.hpp"
#include "common/draw_struct.hpp"

namespace moob {
    class PixelMgr : public BaseMgr
    {
    private:
    public:
        virtual void Tick() final;
        virtual int Init() final;
        void Draw(Pixel p);
    };
}
