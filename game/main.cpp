
#include "common/config.hpp"
#include "plat/plat_app.hpp"

#ifdef MOOB_LOG_LEVEL
    #include "common/logger.hpp"
#else
    #define MLOG.Log(x) ((void)x)
    #define MLOG.SetLogLevel(x) ((void)x)
#endif

int main(int argc, char** argv)
{
    // MLOG->SetLogLevel(MOOB_LOG_LEVEL);
    // MLOG->Log(1, "hello");
    // MLOG::GetInstance()->Log(1, "hi");
    
    int ret;
    moob::AppCfg config;
    config.CollectArgs(argc, argv);
    moob::PlatApp app(config);
    app.Init();
    app.Doing();
    app.Final();

    return ret;
}