#pragma once

#include <d2d1.h>

#include <functional>

namespace moob {
    class D2dApi
    {
    private:
        ID2D1Factory            *pFactory_;
        ID2D1HwndRenderTarget   *pRender_target_;
        ID2D1SolidColorBrush    *pBrush_;
        D2D1_ELLIPSE            ellipse_ = {0};

        std::function<HWND()>   pHwndFunc_;
        HWND GetHwnd() { return pHwndFunc_(); };

        void CalculateLayout();
        HRESULT CreateGraphicsResources();
        void DiscardGraphicsResources();
    public:
        D2dApi() : pFactory_(NULL), pRender_target_(NULL), pBrush_(NULL) {};
        ~D2dApi() {};

        void SetGetHwndFunc(std::function<HWND()> func) { pHwndFunc_ = func; };

        bool OnCreatFactory();
        void OnDestory();
        void OnPaint();
        void OnResize();
        
    };
    
}