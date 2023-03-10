#include "frame/base/base_app.hpp"

using namespace moob;

BaseApp::~BaseApp() 
{
}

void BaseApp::Init() 
{
    // regist mgr
    RegistMgrT<PixelMgr>(&pixelMgr_);

    BaseApp::EngineModeCb(moob::EngineMode::CLIENT,
        [this]() -> void
        {
            auto func = [=] () -> RenderMgrInterface* 
            {
                return (RenderMgrInterface*)GetRenderer();
            };
            for (auto it = begin(mgrs_); it != end(mgrs_); it++) 
            {
                (*it)->SetRenderFunc(func);
            }
        }
    );
}

void BaseApp::Doing()
{
    BaseApp::EngineModeCb(moob::EngineMode::CLIENT,
        [this]() -> void
        {
            thread_mgr_.AddTask([this]()-> void
            {
                ReanderLoop();
            }, 1);
        }
    );
    thread_mgr_.AddTask([this]()-> void
    {
        ThreadLoop();
    }, 2);
    thread_mgr_.Start();
}

void BaseApp::Final()
{
    thread_mgr_.Wait();
}

bool BaseApp::IsQuit() const 
{
    return is_quit_;
}

void BaseApp::ThreadLoop()
{
    if (!ThreadStart()) return;
    while (!IsQuit()) 
    {
        Tick();
    }
    ThreadEnd();
}

void BaseApp::ReanderLoop()
{
    while (!IsQuit()) 
    {
        renderer_->Tick();
    }
}

void BaseApp::Tick() 
{
    for (auto it = begin(mgrs_); it != end(mgrs_); it++) 
    {
        (*it)->Tick();
    }
}

bool BaseApp::ThreadStart() 
{
    return true;
}

void BaseApp::ThreadEnd() 
{
    
}

template <typename T>
void BaseApp::RegistMgrT(T *mgr) 
{
    mgrs_.push_back(mgr);
}

void BaseApp::SetRenderer(RenderMgrInterface *renderer_mgr) 
{
    renderer_ = renderer_mgr;
}

RenderMgrInterface* BaseApp::GetRenderer() 
{
    return renderer_;
}

/* ============== config start ============== */
int32_t BaseApp::ScreenWidth() 
{
    return app_config_.screen_w_;
}

int32_t BaseApp::ScreenHeight() 
{
    return app_config_.screen_h_;
}

void BaseApp::EngineModeCb(uint32_t mode, std::function<void()> cb)
{
    if (app_config_.engine_mode_ & mode)
    {
        cb();
    }
}

void BaseApp::EngineModeRelease(uint32_t mode, std::function<void()> cb)
{
    if (!(app_config_.engine_mode_ & mode))
    {
        cb();
    }
}
/* ============== config end  ============== */