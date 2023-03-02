
#include <tchar.h>

#include "plat/windows/win_base.hpp"

using namespace moob;

void WinApp::Doing()
{
    BaseApp::Doing();
    PlatTick();
}

void WinApp::PlatTick() 
{
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0) > 0) 
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

bool WinApp::CreateMainWindow() 
{
    hInstance_ = GetModuleHandle(nullptr);

    WNDCLASSEX wcex = {0};
    wcex.cbSize         = sizeof(WNDCLASSEX);
    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WindowProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance_;
    // wcex.hIcon          = LoadIcon(hInstance_, MAKEINTRESOURCE(IDI_APPLICATION));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);  
    wcex.lpszMenuName   = nullptr;
    wcex.lpszClassName  = "MoobEngine";
    // wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

    RegisterClassEx(&wcex);

    hwnd_ = CreateWindowEx(
        0, "MoobEngine", app_config_.appname_,
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        app_config_.screen_w_, app_config_.screen_h_, nullptr,
        nullptr, hInstance_, this);
    
    ShowWindow(hwnd_, SW_SHOWDEFAULT);
	UpdateWindow(hwnd_);

    return (hwnd_ ? true : false);
}

HWND WinApp::Window() const 
{
    return hwnd_; 
}

void WinApp::OnSize(HWND hwnd, UINT flag, int width, int height) 
{

}

LRESULT CALLBACK WinApp::WindowProc(HWND hwnd, UINT msg,
                                    WPARAM wParam, LPARAM lParam) 
{
    WinApp* pThis = nullptr;
    if (msg == WM_NCCREATE) 
    {
        CREATESTRUCT *pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
        pThis = reinterpret_cast<WinApp*>(pCreate->lpCreateParams);
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pThis);
        pThis->hwnd_ = hwnd;
    } else 
    {
        pThis = reinterpret_cast<WinApp*>(
            GetWindowLongPtr(hwnd, GWLP_USERDATA));
    }

    if (pThis) 
    {
        return pThis->HandleMessage(msg, wParam, lParam);
    } else 
    {
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
}

LRESULT WinApp::HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam) 
{
    switch (msg) 
    {
    case WM_SIZE: 
        {
            int width = LOWORD(lParam);
            int height = HIWORD(lParam);
            OnSize(hwnd_, (UINT)wParam, width, height);
        }
        break;
    case WM_PAINT: 
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd_, &ps);
            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+10));
            EndPaint(hwnd_, &ps);
        }
        break;
    case WM_CLOSE:
        if (MessageBox(hwnd_, "Really quit?", "My application", MB_OKCANCEL) == IDOK) 
        {
            DestroyWindow(hwnd_);
        }
        return 0;
        break;
    case WM_KEYDOWN:
        break;
    case WM_KEYUP:
        break;
    }

    return DefWindowProc(hwnd_, msg, wParam, lParam);
}