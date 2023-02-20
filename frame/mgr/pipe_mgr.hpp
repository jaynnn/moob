#pragma once

#include <map>

#include "frame/interface/mgr_interface.hpp"
#include "frame/util/pipe.hpp"

namespace moob {
    class PipeMgr : public MgrInterface
    {
    private:
        template <typename T>
        std::map<uint32_t, Pipe<T>> piles_; 
    public:
        PipeMgr();
        PipeMgr(uint32_t count);
        ~PipeMgr();
        virtual int Init();
    };
}