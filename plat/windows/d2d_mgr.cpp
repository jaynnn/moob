#include "plat/windows/d2d_mgr.hpp"

template <class T> void SafeRelease(T **ppT) {
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = nullptr;
    }
}

void moob::D2dMgr::DiscardGraphicsResources() {
    SafeRelease(&pRender_target_);
    SafeRelease(&pBrush_);
}

void moob::D2dMgr::CalculateLayout() {
    if (pRender_target_ != nullptr)
    {
        D2D1_SIZE_F size = pRender_target_->GetSize();
        const float x = size.width / 2;
        const float y = size.height / 2;
        const float radius = min(x, y);
        ellipse_ = D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius);
    }
}

HRESULT moob::D2dMgr::CreateGraphicsResources() {
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

            if (SUCCEEDED(hr))
            {
                const D2D1_COLOR_F color1 = D2D1::ColorF(0.0f, 0.0f, 0);
                hr = pRender_target_->CreateSolidColorBrush(color1, &pStroke_);
                CalculateLayout();
            }
        }
    }
    return hr;
}

void moob::D2dMgr::DrawClockHand(float fHandLength, float fAngle, float fStrokeWidth) {
    pRender_target_->SetTransform(
        D2D1::Matrix3x2F::Rotation(fAngle, ellipse_.point)
            );

    // endPoint defines one end of the hand.
    D2D_POINT_2F endPoint = D2D1::Point2F(
        ellipse_.point.x,
        ellipse_.point.y - (ellipse_.radiusY * fHandLength)
        );

    // Draw a line from the center of the ellipse to endPoint.
    pRender_target_->DrawLine(
        ellipse_.point, endPoint, pStroke_, fStrokeWidth);
}

void moob::D2dMgr::RenderScene() {
    pRender_target_->Clear(D2D1::ColorF(D2D1::ColorF::SkyBlue));

    pRender_target_->FillEllipse(ellipse_, pBrush_);
    pRender_target_->DrawEllipse(ellipse_, pBrush_);

    // Draw hands
    SYSTEMTIME time;
    GetLocalTime(&time);

    // 60 minutes = 30 degrees, 1 minute = 0.5 degree
    const float fHourAngle = (360.0f / 12) * (time.wHour) + (time.wMinute * 0.5f);
    const float fMinuteAngle =(360.0f / 60) * (time.wMinute);

    DrawClockHand(0.6f,  fHourAngle,   6);
    DrawClockHand(0.85f, fMinuteAngle, 4);

    // Restore the identity transformation.
    pRender_target_->SetTransform( D2D1::Matrix3x2F::Identity() );
}

bool moob::D2dMgr::OnCreatFactory() {
    HRESULT ret = D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, &pFactory_);
    if (FAILED(ret))
        return false;
    return true;
}

void moob::D2dMgr::OnDestory() {
    DiscardGraphicsResources();
    SafeRelease(&pFactory_);
    PostQuitMessage(0);
}

void moob::D2dMgr::OnPaint() {
    HRESULT hr = CreateGraphicsResources();
    HWND hwnd = GetHwnd();
    if (SUCCEEDED(hr))
    {
        PAINTSTRUCT ps;
        BeginPaint(hwnd, &ps);
     
        pRender_target_->BeginDraw();

        RenderScene();

        hr = pRender_target_->EndDraw();
        if (FAILED(hr) || hr == D2DERR_RECREATE_TARGET)
        {
            DiscardGraphicsResources();
        }
        EndPaint(hwnd, &ps);
    }
}

void moob::D2dMgr::OnResize() {
    HWND hwnd = GetHwnd();
    if (pRender_target_ != nullptr)
    {
        RECT rc;
        GetClientRect(hwnd, &rc);

        D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);

        pRender_target_->Resize(size);
        CalculateLayout();
        InvalidateRect(hwnd, nullptr, FALSE);
    }
}

void moob::D2dMgr::Draw(int32_t x, int32_t, moob::Pixel pixel) {

}