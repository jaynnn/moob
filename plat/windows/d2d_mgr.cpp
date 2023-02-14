#include "plat/windows/d2d_mgr.hpp"

using namespace moob;

template <class T> void SafeRelease(T **ppT) {
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = nullptr;
    }
}

void D2dMgr::DiscardGraphicsResources() {
    SafeRelease(&pRender_target_);
    SafeRelease(&pBrush_);
}

void D2dMgr::OnDestory() {
    DiscardGraphicsResources();
    SafeRelease(&pFactory_);
    PostQuitMessage(0);
}

bool D2dMgr::OnCreatFactory() {
    HRESULT ret = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pFactory_);
    if (FAILED(ret))
        return false;
    return true;
}

HRESULT D2dMgr::CreateGraphicsResources() {
    HWND hwnd = GetHwnd();
    HRESULT hr = S_OK;
    if (pRender_target_ == nullptr)
    {
        RECT rc;
        GetClientRect(hwnd, &rc);

        D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);

        hr = pFactory_->CreateHwndRenderTarget(
            D2D1::RenderTargetProperties(),
            D2D1::HwndRenderTargetProperties(hwnd, size),
            &pRender_target_);

        if (SUCCEEDED(hr))
        {
            const D2D1_COLOR_F color = D2D1::ColorF(1.0f, 1.0f, 0);
            hr = pRender_target_->CreateSolidColorBrush(color, &pBrush_);
            const D2D1_COLOR_F color1 = D2D1::ColorF(0.5f, 0.5f, 0);
            hr = pRender_target_->CreateSolidColorBrush(color1, &pStroke_);
        }
    }
    return hr;
}

void D2dMgr::OnResize() {
}

void D2dMgr::Draw(int32_t x, int32_t, Pixel pixel) {

}

int D2dMgr::Init() {
    return 1;
}

void D2dMgr::Tick() {
    if (pFactory_ != nullptr) {
        HRESULT hr = CreateGraphicsResources();
        HWND hwnd = GetHwnd();
        if (SUCCEEDED(hr))
        {
            PAINTSTRUCT ps;
            BeginPaint(hwnd, &ps);

            pRender_target_->BeginDraw();

            ExplanDrawFlow();

            hr = pRender_target_->EndDraw();
            if (FAILED(hr) || hr == D2DERR_RECREATE_TARGET)
            {
                DiscardGraphicsResources();
            }
            EndPaint(hwnd, &ps);
        }
    }
}

void D2dMgr::ExplanDrawFlow() {
    D2D1_RECT_F rectangle = D2D1::Rect(438.0f, 301.5f, 498.0f, 361.5f);
    pRender_target_->DrawRectangle(rectangle, pBrush_, 1.0f);
    pRender_target_->FillRectangle(rectangle, pStroke_);
    // for (auto it = begin(flow); it != end(flow); it++) {
    //     switch(it->i) {
    //         case DrawI::PIXEL: {
    //             break;
    //         default:
    //             break;
    //         }
    //     }
    // }
}

