
#include "common/config.hpp"
#include "plat/plat_app.hpp"
#include "frame/mgr/thread_mgr.hpp"

#ifdef MOOB_LOG_LEVEL
    #include "common/logger.hpp"
#else
    #define MLOG.Log(x) ((void)x)
    #define MLOG.SetLogLevel(x) ((void)x)
#endif

int main(int argc, char **argv) {
    // MLOG->SetLogLevel(MOOB_LOG_LEVEL);
    // MLOG->Log(1, "hello");
    MLOG::GetInstance()->Log(1, "hi");
    
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