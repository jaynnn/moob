#pragma once

#include "frame/interface/render_interface.hpp"

namespace moob {
    class BaseMgr : public MgrInterface
    {
    private:
    public:
        virtual int Init();
        virtual void Tick();
    };
}