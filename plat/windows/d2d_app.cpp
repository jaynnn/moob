#include "plat/windows/d2d_app.hpp"

using namespace moob;

bool D2dApp::CreateMainWindow() 
{
    auto func = [this]() -> HWND 
    {
        return (HWND)GetHwnd();
    };
    d2d_.SetGetHwndFunc(func);

    bool ret = WinApp::CreateMainWindow();
    
    return ret;
}

void D2dApp::Init()
{
    BaseApp::Init();
    BaseApp::EngineModeCb(moob::EngineMode::CLIENT,
        [this]() -> void
        {
            CreateMainWindow();
            SetRenderer(&d2d_);
        }
    );

    BaseApp::EngineModeRelease(moob::EngineMode::CLIENT,
        [this]() -> void
        {
            delete &d2d_;
        }
    );
}

void D2dApp::Doing()
{
    WinApp::Doing();
}

LRESULT D2dApp::HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam) 
{
    switch (msg)
    {
    case WM_CREATE:
        if (!d2d_.OnCreatFactory())
            return -1;
        return 0;
    case WM_PAINT:
         return 0;
    case WM_SIZE:
        d2d_.OnResize();
        return 0;
    case WM_DESTROY:
        d2d_.OnDestory();
        return 0;
    case WM_LBUTTONDOWN:	//左按钮向下
        return 0;
    case WM_LBUTTONUP:	//左按钮向上
        return 0;
    case WM_MBUTTONDOWN:	//中间按钮向下
        return 0;
    case WM_MBUTTONUP:	//中间按钮向上
        return 0;
    case WM_RBUTTONDOWN:	//右键向下键
        return 0;
    case WM_RBUTTONUP:	//向上按钮
        return 0;
    case WM_XBUTTONDOWN:	//XBUTTON1 或 XBUTTON2 关闭
        return 0;
    case WM_XBUTTONUP:	//XBUTTON1 或 XBUTTON2 向上
        return 0;
    default:
        return DefWindowProc(hwnd_, msg, wParam, lParam);
    }
}