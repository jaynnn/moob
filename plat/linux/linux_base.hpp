#pragma once

#include "frame/base/base_app.hpp"

namespace X11
{
    #include <X11/X.h>
    #include <X11/Xlib.h>
}

namespace moob {
    class LinuxApp : public BaseApp
    {
    private:
		X11::Display*                display_ = nullptr;
		X11::Window					 window_root_;
		X11::Window					 window_;
		X11::Colormap                color_map_;
		X11::XSetWindowAttributes    set_window_attr_;
        X11::XEvent                  event_;
        int                          screen_;
        const char                   *msg_ = "linux window";
        
    public:
        using BaseApp::BaseApp;
        int Init() override;
        void Tick() override;
        void CreateMainWindow() override;
    };
}

