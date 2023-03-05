#pragma once

#include <X11/X.h>
#include <X11/Xlib.h>

#include "frame/base/base_app.hpp"

namespace moob 
{
    class LinuxApp : public BaseApp
    {
    private:
		Display*                    display_ = nullptr;
		Window					    window_root_;
		Window					    window_;
		Colormap                    color_map_;
		XSetWindowAttributes        set_window_attr_;
        XEvent                      event_;
        int                         screen_;
        const char                  *msg_ = "linux window";
        
    public:
        using BaseApp::BaseApp;
        void Init() override;
        void Tick() override;
        bool CreateMainWindow() override;
    };
}

