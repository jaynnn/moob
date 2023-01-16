
#include "common/config.hpp"
#include "plat/windows/win_base.hpp"

int main(int argc, char **argv)
{
    int ret;

    moob::AppCfg config(1920);
    moob::WinApp app(config);
    app.CreateMainWindow();
    ret = app.Init();
    
    while (!app.IsQuit()) {
        app.Tick();
    }
    
    return ret;
}