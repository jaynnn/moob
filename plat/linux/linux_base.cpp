#include "plat/linux/linux_base.hpp"


int moob::LinuxApp::Init() {
   return 0;
}
void moob::LinuxApp::Tick() {

}
bool moob::LinuxApp::CreateMainWindow() {

   display_ = XOpenDisplay(NULL);
 
   screen_ = DefaultScreen(display_);
   window_ = XCreateSimpleWindow(display_, RootWindow(display_, screen_), 10, 10, 100, 100, 1,
                           BlackPixel(display_, screen_), WhitePixel(display_, screen_));
   XSelectInput(display_, window_, ExposureMask | KeyPressMask);
   XMapWindow(display_, window_);
 
   while (1) {
      XNextEvent(display_, &event_);
      if (event_.type == Expose) {
         XFillRectangle(display_, window_, DefaultGC(display_, screen_), 20, 20, 10, 10);
         XDrawString(display_, window_, DefaultGC(display_, screen_), 10, 50, msg_, strlen(msg_));
      }
      if (event_.type == KeyPress)
         break;
   }
 
   XCloseDisplay(display_);
}