
#include "common/config.hpp"
#include "plat/linux/linux_base.hpp"

int main(int argc, char **argv)
{
    int ret;

    moob::AppCfg config(1920);
    moob::LinuxApp app(config);
    app.CreateMainWindow();
    ret = app.Init();
    
    while (!app.IsQuit()) {
        app.Tick();
    }
    
    return ret;
}