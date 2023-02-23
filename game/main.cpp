
#include "common/config.hpp"
#include "common/loging.hpp"
#include "plat/plat_app.hpp"
#include "frame/mgr/thread_mgr.hpp"

#ifdef MOOB_LOG_LEVEL
    moob::Loging loging(MOOB_LOG_LEVEL);
    #define MLOG(s) loging.PrintLog(MOOB_LOG_LEVEL, (s))
#endif

int main(int argc, char **argv) {
    // MLOG("11111111111");
    int ret;

    moob::AppCfg config;
    moob::PlatApp app(config);
    ret = app.Init();
    app.CreateMainWindow();
    moob::ThreadMgr threadMgr;
    threadMgr.AddTask([&app]()-> void {
        app.ReanderLoop();
    });
    threadMgr.AddTask([&app]()-> void {
        app.ThreadLoop();
    });
    threadMgr.Start(1);

    app.PlatTick();
    
    threadMgr.Wait();

    return ret;
}