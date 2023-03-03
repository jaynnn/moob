#pragma once

#include <map>

#include "frame/interface/mgr_interface.hpp"
#include "frame/util/pipe.hpp"

namespace moob {
    template <typename T>
    class PipeMgr : public MgrInterface
    {
    private:
    public:
        PipeMgr();
        ~PipeMgr();
        virtual void Init();
    };
}