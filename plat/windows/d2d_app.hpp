#pragma once

#include "plat/windows/win_base.hpp"
#include "renderer/d2d_api.hpp"

namespace moob 
{
    class D2dApp : public WinApp
    {
    using WinApp::WinApp;

    private:
        D2dApi d2d_;
        LRESULT HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam);
        void ThreadLoop();
        bool ThreadStart();
        void ThreadEnd();
        
    public:
        bool CreateMainWindow() final;
        virtual std::thread MainThread();
    };
}
