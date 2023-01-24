#pragma once

#include <d2d1.h>

namespace moob {
    class D2dApi
    {
    private:
        ID2D1Factory            *pFactory_;
        ID2D1HwndRenderTarget   *pRender_target_;
        ID2D1SolidColorBrush    *pBrush_;
        D2D1_ELLIPSE            ellipse_;

        HWND                    *pHwnd;
        HWND GetHwnd() { return *pHwnd; };

        void CalculateLayout();
        HRESULT CreateGraphicsResources();
        void DiscardGraphicsResources();
    public:
        D2dApi() : pFactory_(NULL), pRender_target_(NULL), pBrush_(NULL), pHwnd(NULL) {};
        ~D2dApi();

        void setHwnd(HWND hwnd) { pHwnd = &hwnd; };

        bool OnCreatFactory();
        void OnDestory();
        void OnPaint();
        void OnResize();
        
    };
    
}