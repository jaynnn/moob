#pragma once

#include "frame/interface/mgr_interface.hpp"
#include "frame/base/pixel.hpp"

namespace moob {
    class PixelMgr : public MgrInterface
    {
    private:
        
    public:
        virtual void Tick() final;
        virtual int Init() final;
    };
}
