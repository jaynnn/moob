
#include <tchar.h>

#include "plat/windows/win_base.hpp"

int moob::PlatApp::Init()
{
    return 0;
}

void moob::PlatApp::Tick()
{

}

void moob::PlatApp::CreateMainWindow()
{
    hInstance_ = GetModuleHandle(NULL);

    WNDCLASSEX wc = {};

    ZeroMemory(&wc, sizeof(WNDCLASSEX));

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance_;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = _T("MoobEngine");

    RegisterClassEx(&wc);

    int height_adjust =
        (GetSystemMetrics(SM_CYFRAME) + GetSystemMetrics(SM_CYCAPTION) +
         GetSystemMetrics(SM_CXPADDEDBORDER));
    int width_adjust =
        (GetSystemMetrics(SM_CXFRAME) + GetSystemMetrics(SM_CXPADDEDBORDER));

    hwnd_ = CreateWindowEx(
        0,
        _T("MoobEngine"),
        app_config_.appname_, //TODO
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        app_config_.screen_w_ + width_adjust,
        app_config_.screen_h_ + height_adjust,
        NULL,
        NULL,
        hInstance_,
        this);

    ShowWindow(hwnd_, SW_SHOW);

}


LRESULT CALLBACK moob::PlatApp::WindowProc(HWND hWnd, UINT message,
                                    WPARAM wParam, LPARAM lParam) {
    LRESULT ret = 0;
    return ret;
}