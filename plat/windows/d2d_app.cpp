#include "plat/windows/d2d_app.hpp"


template <class T> void SafeRelease(T **ppT)
{
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = NULL;
    }
}

bool moob::D2dApp::CreateMainWindow() {
    return WinApp::CreateMainWindow();
}

void moob::D2dApp::CalculateLayout()
{
    if (pRender_target_ != NULL)
    {
        D2D1_SIZE_F size = pRender_target_->GetSize();
        const float x = size.width / 2;
        const float y = size.height / 2;
        const float radius = min(x, y);
        ellipse_ = D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius);
    }
}

HRESULT moob::D2dApp::CreateGraphicsResources()
{
    HRESULT hr = S_OK;
    if (pRender_target_ == NULL)
    {
        RECT rc;
        GetClientRect(hwnd_, &rc);

        D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);

        hr = pFactory_->CreateHwndRenderTarget(
            D2D1::RenderTargetProperties(),
            D2D1::HwndRenderTargetProperties(hwnd_, size),
            &pRender_target_);

        if (SUCCEEDED(hr))
        {
            const D2D1_COLOR_F color = D2D1::ColorF(1.0f, 1.0f, 0);
            hr = pRender_target_->CreateSolidColorBrush(color, &pBrush_);

            if (SUCCEEDED(hr))
            {
                CalculateLayout();
            }
        }
    }
    return hr;
}

void moob::D2dApp::DiscardGraphicsResources()
{
    SafeRelease(&pRender_target_);
    SafeRelease(&pBrush_);
}

void moob::D2dApp::OnPaint()
{
    HRESULT hr = CreateGraphicsResources();
    if (SUCCEEDED(hr))
    {
        PAINTSTRUCT ps;
        BeginPaint(hwnd_, &ps);
     
        pRender_target_->BeginDraw();

        pRender_target_->Clear( D2D1::ColorF(D2D1::ColorF::SkyBlue) );
        pRender_target_->FillEllipse(ellipse_, pBrush_);

        hr = pRender_target_->EndDraw();
        if (FAILED(hr) || hr == D2DERR_RECREATE_TARGET)
        {
            DiscardGraphicsResources();
        }
        EndPaint(hwnd_, &ps);
    }
}

void moob::D2dApp::Resize()
{
    if (pRender_target_ != NULL)
    {
        RECT rc;
        GetClientRect(hwnd_, &rc);

        D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);

        pRender_target_->Resize(size);
        CalculateLayout();
        InvalidateRect(hwnd_, NULL, FALSE);
    }
}

LRESULT moob::D2dApp::HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CREATE:
        if (FAILED(D2D1CreateFactory(
                D2D1_FACTORY_TYPE_SINGLE_THREADED, &pFactory_)))
        {
            return -1;  // Fail CreateWindowEx.
        }
        return 0;

    case WM_DESTROY:
        DiscardGraphicsResources();
        SafeRelease(&pFactory_);
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        OnPaint();
        return 0;

    case WM_SIZE:
        Resize();
        return 0;
    }
    return DefWindowProc(hwnd_, msg, wParam, lParam);
}