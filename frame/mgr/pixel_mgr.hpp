#pragma once

#include "frame/interface/mgr_interface.hpp"
#include "frame/base/pixel.hpp"

namespace moob {
    class PixelMgr : public BaseMgr
    {
    private:
        
    public:
        virtual void Tick() final;
    };
}
