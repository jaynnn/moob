
#include "common/config.hpp"
#include "plat/plat_app.hpp"
#include "common/logger.hpp"
#include "frame/mgr/thread_mgr.hpp"

int main(int argc, char **argv) {
#ifdef MOOB_LOG_LEVEL
    moob::Logger::GetInstance().SetLogLevel(MOOB_LOG_LEVEL);
    // using MLOG = moob::Logger;
    auto &MLOG = moob::Logger::GetInstance();
#else
    #define MLOG.Log(x) ((void)x)
    #define MLOG.SetLogLevel(x) ((void)x)
#endif
    MLOG.Log(1, "llllllllllllll");
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