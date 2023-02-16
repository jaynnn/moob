
#include "common/config.hpp"
#include "plat/plat_app.hpp"

int main(int argc, char **argv) {
    int ret;

    moob::AppCfg config;
    moob::PlatApp app(config);

    ret = app.Init();
    app.CreateMainWindow();

    std::thread t = app.MainThread();
    app.PlatTick();
    t.join();

    return ret;
}