#pragma once

#include "plat/windows/win_base.hpp"

namespace moob 
{
    class D2dApp : WinApp 
    {
    using WinApp::WinApp;

    private:
        
    public:

        void CreateMainWindow() final;
    };
}