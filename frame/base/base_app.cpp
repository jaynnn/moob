#include "frame/base/base_app.hpp"

moob::BaseApp::~BaseApp() {
}

int moob::BaseApp::Init() {
    return 0;
}

void moob::BaseApp::Tick() {

}

bool moob::BaseApp::IsQuit() const
{
    return is_quit_;
}

std::thread moob::BaseApp::MainThread()
{
    std::thread t = std::thread(&moob::BaseApp::ThreadLoop, this);
    return t;
}

void moob::BaseApp::ThreadLoop()
{
    if (!ThreadStart()) return;
    while (!IsQuit()) {
        Tick();
    }
    ThreadEnd();
}

bool moob::BaseApp::ThreadStart()
{
    return true;
}

void moob::BaseApp::ThreadEnd()
{
    
}