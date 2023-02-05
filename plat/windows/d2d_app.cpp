#include "plat/windows/d2d_app.hpp"

bool moob::D2dApp::CreateMainWindow() {

    auto func = [this]() -> HWND {
        return (HWND)GetHwnd();
    };
    d2d_.SetGetHwndFunc(func);

    bool ret = WinApp::CreateMainWindow();
    
    return ret;
}

int moob::D2dApp::Init() {
    // moob::BaseApp::RegistRenderer<D2dMgr>(&d2d_);
    return 1;
}

LRESULT moob::D2dApp::HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg)
    {
    case WM_CREATE:
        if (!d2d_.OnCreatFactory())
            return -1;
        return 0;
    case WM_PAINT:
         d2d_.OnPaint();
         return 0;
    case WM_SIZE:
        d2d_.OnResize();
        return 0;
    case WM_DESTROY:
        d2d_.OnDestory();
        return 0;

    default:
        return DefWindowProc(hwnd_, msg, wParam, lParam);
    }
}