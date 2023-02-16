#pragma once

#include "frame/interface/render_interface.hpp"
#include "frame/base/pixel.hpp"
#include "common/draw_struct.hpp"

namespace moob {
    class PixelMgr : public MgrInterface
    {
    private:
        std::function<RenderMgrInterface> renderFunc_;
    public:
        virtual void Tick() final;
        virtual int Init() final;
        void Draw(Pixel p);
    };
}
