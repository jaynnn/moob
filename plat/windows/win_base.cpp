
#include <tchar.h>

#include "plat/windows/win_base.hpp"

int moob::PlatApp::Init()
{
    return 0;
}

void moob::PlatApp::Tick()
{
    MSG msg;
    if (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
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

    hwnd_ = CreateWindowEx(
        0, _T("MoobEngine"), app_config_.appname_, //TODO
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        app_config_.screen_w_, app_config_.screen_h_, NULL,
        NULL, hInstance_, this);

    ShowWindow(hwnd_, SW_SHOW);

}

void moob::PlatApp::OnSize(HWND hwnd, UINT flag, int width, int height)
{

}

LRESULT CALLBACK moob::PlatApp::WindowProc(HWND hwnd, UINT msg,
                                    WPARAM wParam, LPARAM lParam) {
    LRESULT result = 0;

    PlatApp* pThis = NULL;
    if (msg == WM_NCCREATE) {
        CREATESTRUCT *pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
        pThis = reinterpret_cast<PlatApp*>(pCreate->lpCreateParams);
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pThis);
    } else {
        pThis = reinterpret_cast<PlatApp*>(
            GetWindowLongPtr(hwnd, GWLP_USERDATA));
    }

    if (pThis) {
        switch (msg) {
        case WM_SIZE: {
                int width = LOWORD(lParam);
                int height = HIWORD(lParam);

                pThis->OnSize(hwnd, (UINT)wParam, width, height);
            }
            break;
        case WM_PAINT: {
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hwnd, &ps);
                FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+10));

                EndPaint(hwnd, &ps);
            }
        case WM_CLOSE:
            if (MessageBox(hwnd, "Really quit?", "My application", MB_OKCANCEL) == IDOK) {
                DestroyWindow(hwnd);
            }
            return 0;
        }
    } else {
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return result;
}