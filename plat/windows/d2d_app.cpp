#include "plat/windows/d2d_app.hpp"

bool moob::D2dApp::CreateMainWindow() {

    auto func = [this]() -> HWND {
        return (HWND)GetHwnd();
    };
    d2d_.SetGetHwndFunc(func);

    bool ret = WinApp::CreateMainWindow();
    return ret;
}

LRESULT moob::D2dApp::HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CREATE:
        if (FAILED(d2d_.OnCreatFactory()))
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

std::thread moob::D2dApp::MainThread()
{
    std::thread t = std::thread(&moob::D2dApp::ThreadLoop, this);
    return t;
}

void moob::D2dApp::ThreadLoop()
{
    if (!ThreadStart()) return;
    while (!IsQuit()) {
        Tick();
    }
    ThreadEnd();
}

bool moob::D2dApp::ThreadStart()
{
    return true;
}

void moob::D2dApp::ThreadEnd()
{
    
}