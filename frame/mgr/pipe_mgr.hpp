#pragma once

#include <map>

#include "frame/interface/mgr_interface.hpp"
#include "frame/util/pipe.hpp"

namespace moob 
{
    class PipeMgr : public MgrInterface
    {
    private:
    public:
        PipeMgr();
        ~PipeMgr();
        int CreateDrawI();
        virtual void Init();
    };
}