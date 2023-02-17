
#include "common/config.hpp"
#include "plat/plat_app.hpp"

int main(int argc, char **argv) {
    int ret;

    moob::AppCfg config;
    moob::PlatApp app(config);

    ret = app.Init();
    app.CreateMainWindow();

    std::thread it = app.MainThread();
    app.PlatTick();
    
    it.join();

    return ret;
}