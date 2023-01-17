#include "plat/linux/linux_base.hpp"


int moob::LinuxApp::Init()
{

}
void moob::LinuxApp::Tick()
{

}
void moob::LinuxApp::CreateMainWindow()
{

   display_ = X11::XOpenDisplay(NULL);
 
   screen_ = DefaultScreen(display_);
   window_ = X11::XCreateSimpleWindow(display_, RootWindow(display_, screen_), 10, 10, 100, 100, 1,
                           BlackPixel(display_, screen_), WhitePixel(display_, screen_));
   X11::XSelectInput(display_, window_, ExposureMask | KeyPressMask);
   X11::XMapWindow(display_, window_);
 
   while (1) {
   }
 
   X11::XCloseDisplay(display_);
}