#include "plat/windows/d2d_app.hpp"


bool moob::D2dApp::CreateMainWindow() {
    d2d_.setHwnd(hwnd_);
    return WinApp::CreateMainWindow();
}

LRESULT moob::D2dApp::HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CREATE:
        return d2d_.OnCreatFactory() ? 0 : -1;
    case WM_DESTROY:
        d2d_.OnDestory();
        return 0;

    case WM_PAINT:
        d2d_.OnPaint();
        return 0;

    case WM_SIZE:
        d2d_.OnResize();
        return 0;
    case WM_NCCREATE:
        return true;
    }
    return DefWindowProc(hwnd_, msg, wParam, lParam);
}