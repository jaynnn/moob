#pragma once

#include <Windows.h>

#include "frame/base/base_app.hpp"

namespace moob {
    class WinApp : public BaseApp
    {
    private:
        static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message,
                                          WPARAM wParam, LPARAM lParam);
        
    public:
        using BaseApp::BaseApp;
        int Init() override;
        void Tick() override;
        void CreateMainWindow() override;

        
    protected:
        HINSTANCE hInstance_ = NULL;
        HWND hwnd_ = NULL;
    };
    
}