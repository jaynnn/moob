#pragma once

#include <d2d1.h>

#include "plat/windows/win_base.hpp"

namespace moob 
{
    class D2dApp : public WinApp
    {
    using WinApp::WinApp;

    private:
        ID2D1Factory            *pFactory_;
        ID2D1HwndRenderTarget   *pRender_target_;
        ID2D1SolidColorBrush    *pBrush_;
        D2D1_ELLIPSE            ellipse_;
        void CalculateLayout();
        HRESULT CreateGraphicsResources();
        void DiscardGraphicsResources();
        void OnPaint();
        void Resize();
        LRESULT HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam);
        
    public:
        bool CreateMainWindow() final;
    };
}
