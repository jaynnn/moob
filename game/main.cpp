
#include "common/config.hpp"
#include "plat/plat_app.hpp"

int main(int argc, char **argv)
{
    int ret;

    moob::AppCfg config(1920);
    PLAT_APP app(config);
    app.CreateMainWindow();
    ret = app.Init();
    
    while (!app.IsQuit()) {
        app.Tick();
    }
    
    return ret;
}