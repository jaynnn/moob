#pragma once

#include "plat/windows/win_base.hpp"
#include "plat/windows/d2d_mgr.hpp"

namespace moob  {
    class D2dApp : public WinApp
    {
    using WinApp::WinApp;

    private:
        D2dMgr d2d_;
        LRESULT HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam);
        
    public:
        virtual bool CreateMainWindow() final;
        virtual void Init() final;
        virtual void Doing() final;
    };
}
