#include "plat/linux/linux_base.hpp"


int moob::LinuxApp::Init()
{

}
void moob::LinuxApp::Tick()
{

}
void moob::LinuxApp::CreateMainWindow()
{

   display_ = XOpenDisplay(NULL);
 
   s = DefaultScreen(display_);
   w = XCreateSimpleWindow(display_, RootWindow(display_, s), 10, 10, 100, 100, 1,
                           BlackPixel(display_, s), WhitePixel(display_, s));
   XSelectInput(display_, w, ExposureMask | KeyPressMask);
   XMapWindow(display_, w);
 
   while (1) {
      XNextEvent(display_, &e);
      if (e.type == Expose) {
         XFillRectangle(display_, w, DefaultGC(display_, s), 20, 20, 10, 10);
         XDrawString(display_, w, DefaultGC(display_, s), 10, 50, msg, strlen(msg));
      }
      if (e.type == KeyPress)
         break;
   }
 
   XCloseDisplay(display_);
}