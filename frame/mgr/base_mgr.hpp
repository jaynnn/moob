#pragma once


#include "frame/interface/render_interface.hpp"

namespace moob 
{
    class BaseMgr : public MgrInterface
    {
    private:
        std::function<RenderMgrInterface* ()> renderFunc_;
    public:
        virtual void Init();
        virtual void Tick();
        virtual void SetRenderFunc(std::function<RenderMgrInterface* ()> func) 
        {
            renderFunc_ = func;
        };
    };
}