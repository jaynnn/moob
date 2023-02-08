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
    D2D1_SIZE_F rtSize = pRender_target_->GetSize();
    // Draw a grid background.
    int width = static_cast<int>(rtSize.width);
    int height = static_cast<int>(rtSize.height);

    for (int x = 0; x < width; x += 10)
    {
        pRender_target_->DrawLine(
            D2D1::Point2F(static_cast<FLOAT>(x), 0.0f),
            D2D1::Point2F(static_cast<FLOAT>(x), rtSize.height),
            pBrush_,
            0.5f
            );
    }

    for (int y = 0; y < height; y += 10)
    {
        pRender_target_->DrawLine(
            D2D1::Point2F(0.0f, static_cast<FLOAT>(y)),
            D2D1::Point2F(rtSize.width, static_cast<FLOAT>(y)),
            pBrush_,
            0.5f
            );
    }
    // Draw two rectangles.
    D2D1_RECT_F rectangle1 = D2D1::RectF(
        rtSize.width/2 - 50.0f,
        rtSize.height/2 - 50.0f,
        rtSize.width/2 + 50.0f,
        rtSize.height/2 + 50.0f
        );

    D2D1_RECT_F rectangle2 = D2D1::RectF(
        rtSize.width/2 - 100.0f,
        rtSize.height/2 - 100.0f,
        rtSize.width/2 + 100.0f,
        rtSize.height/2 + 100.0f
        );
    pRender_target_->FillRectangle(&rectangle1, pBrush_);
    pRender_target_->DrawRectangle(&rectangle2, pStroke_);
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
        
        ExplanDrawFlow(DrawFlow_);

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

int moob::D2dMgr::Init() {
    return 1;
}

void moob::D2dMgr::Tick() {
}


void moob::D2dMgr::ExplanDrawFlow(std::vector<moob::DrawInfo> flow) {
    for (auto it = begin(flow); it != end(flow); it++) {
        switch(it->i) {
            case DrawI::PIXEL: {
                    RenderScene();
                break;
            default:
                break;
            }
        }
    }
}

