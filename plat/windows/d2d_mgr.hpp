#pragma once

#include <d2d1.h>
#include <functional>
#include <vector>

#include "frame/base/pixel.hpp"
#include "frame/interface/render_interface.hpp"
#include "common/draw_struct.hpp"

namespace moob {
    class D2dMgr : public RenderMgrInterface
    {
    private:
        ID2D1Factory            *pFactory_;
        ID2D1HwndRenderTarget   *pRender_target_;
        ID2D1SolidColorBrush    *pBrush_;
        ID2D1SolidColorBrush    *pStroke_;
        D2D1_ELLIPSE            ellipse_ = {0};

        std::function<HWND()>   pHwndFunc_;
        HWND GetHwnd() { return pHwndFunc_(); };

        void CalculateLayout();
        HRESULT CreateGraphicsResources();
        void DiscardGraphicsResources();
        void DrawClockHand(float fHandLength, float fAngle, float fStrokeWidth);
        void RenderScene();

        std::vector<moob::DrawInfo>  DrawFlows_;
        void ExplanDrawFlow(std::vector<moob::DrawInfo> flows);
    public:
        D2dMgr() : pFactory_(nullptr), pRender_target_(nullptr), pBrush_(nullptr), pStroke_(nullptr) {} ;
        ~D2dMgr() {};

        void SetGetHwndFunc(std::function<HWND()> func) { pHwndFunc_ = func; };

        bool OnCreatFactory();
        void OnDestory();
        void OnPaint();
        void OnResize();

        // virtual void CreatDevice() final;
        virtual int Init() final;
        virtual void Tick() final;
        virtual void Draw(int32_t x, int32_t, Pixel pixel) final;
        
    };
    
}