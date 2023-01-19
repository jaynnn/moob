#pragma once

#include <Windows.h>

#include "frame/base/base_app.hpp"

namespace moob 
{
    class WinApp : public BaseApp
    {
    private:
        static LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg,
            WPARAM wParam, LPARAM lParam);
        void OnSize(HWND hwnd, UINT flag, int width, int height);
        
    public:
        using BaseApp::BaseApp;
        void Tick() override;
        void CreateMainWindow() override;

        
    protected:
        HINSTANCE hInstance_ = NULL;
        HWND hwnd_ = NULL;
    };
    
}