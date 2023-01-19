#include "frame/base/engine.hpp"

moob::Engine::Engine() {
}

moob::Engine::Engine(WindowCfg cfg, std::string app_name) {
    cfg = cfg;
    app_name = app_name;
}

moob::Engine::~Engine() {
}

int moob::Engine::Init() {
}
bool moob::Engine::IsQuit() {
    return is_quit_;
}
void moob::Engine::Tick() {
}