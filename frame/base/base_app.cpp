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