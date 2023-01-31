
#include "common/config.hpp"
#include "plat/plat_app.hpp"

int main(int argc, char **argv) {

    moob::AppCfg config(1920);
    moob::PlatApp app(config);

    app.CreateMainWindow();
    ret = app.Init();

    std::thread t = app.MainThread();
    
    app.PlatTick();

    t.join();

    return ret;
}