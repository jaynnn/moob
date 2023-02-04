#include "frame/base/base_app.hpp"

moob::BaseApp::~BaseApp() {
}

int moob::BaseApp::Init() {
    return 0;
}
bool moob::BaseApp::IsQuit() const {
    return is_quit_;
}

std::thread moob::BaseApp::MainThread() {
    std::thread t = std::thread(&moob::BaseApp::ThreadLoop, this);
    return t;
}

void moob::BaseApp::Tick() {
    
}

void moob::BaseApp::ThreadLoop() {
    if (!ThreadStart()) return;
    while (!IsQuit()) {
        Tick();
    }
    ThreadEnd();
}

bool moob::BaseApp::ThreadStart() {
    return true;
}

void moob::BaseApp::ThreadEnd() {
    
}

int32_t moob::BaseApp::ScreenWidth() {
    return app_config_.screen_w_;
}

int32_t moob::BaseApp::ScreenHeight() {
    return app_config_.screen_h_;
}

template <typename T>
void moob::BaseApp::RegistMgr(T mgr) {
    
}
