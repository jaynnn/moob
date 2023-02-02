#pragma once

#include <Windows.h>

#include "frame/base/base_app.hpp"

namespace moob {
    class WinApp : public BaseApp
    {
    private:
        static LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg,
            WPARAM wParam, LPARAM lParam);
        void OnSize(HWND hwnd, UINT flag, int width, int height);
        
    public:
        using BaseApp::BaseApp;
        void PlatTick();
        bool CreateMainWindow() override;
        void* GetHwnd() { return hwnd_; };
        
    protected:
        virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
        HWND Window() const;
        HINSTANCE hInstance_ = NULL;
        HWND hwnd_ = NULL;
    };
    
}