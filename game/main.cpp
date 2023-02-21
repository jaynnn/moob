
#include "common/config.hpp"
#include "plat/plat_app.hpp"
#include "frame/mgr/thread_mgr.hpp"

int main(int argc, char **argv) {
    int ret;

    moob::AppCfg config;
    moob::PlatApp app(config);
    moob::ThreadMgr threadMgr;
    threadMgr.AddTask([&app]()-> void {
        app.ReanderLoop();
    });
    threadMgr.AddTask([&app]()-> void {
        app.ThreadLoop();
    });
    threadMgr.Start(1);

    ret = app.Init();
    app.CreateMainWindow();
    app.PlatTick();
    
    threadMgr.Wait();

    return ret;
}