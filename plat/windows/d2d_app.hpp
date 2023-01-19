#pragma once

#include <d2d1.h>

#include "plat/windows/win_base.hpp"

namespace moob 
{
    class D2dApp : public WinApp
    {
    using WinApp::WinApp;

    private:
        ID2D1Factory            *pFactory;
        ID2D1HwndRenderTarget   *pRenderTarget;
        ID2D1SolidColorBrush    *pBrush;
        D2D1_ELLIPSE            ellipse;
        
    public:

        void CreateMainWindow() final;
    };
}