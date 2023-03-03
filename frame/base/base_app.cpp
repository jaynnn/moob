#include "frame/base/base_app.hpp"

using namespace moob;

BaseApp::~BaseApp() 
{
}

void BaseApp::Init() 
{
    // regist mgr
    RegistMgrT<PixelMgr>(&pixelMgr_);

    auto func = [this] () -> RenderMgrInterface* 
    {
        return (RenderMgrInterface*)GetRenderer();
    };
    for (auto it = begin(mgrs_); it != end(mgrs_); it++) 
    {
        (*it)->SetRenderFunc(func);
    }
}

void BaseApp::Doing()
{
    thread_mgr_.AddTask([this]()-> void {
        ReanderLoop();
    }, 1);
    thread_mgr_.AddTask([this]()-> void {
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

int32_t BaseApp::ScreenWidth() 
{
    return app_config_.screen_w_;
}

int32_t BaseApp::ScreenHeight() 
{
    return app_config_.screen_h_;
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