#include "frame/base/base_app.hpp"

using namespace moob;

BaseApp::~BaseApp() 
{
}

int BaseApp::Init() 
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

    return 0;
}

bool BaseApp::IsQuit() const 
{
    return is_quit_;
}


std::thread BaseApp::MainThread()
{
    std::thread t = std::thread(&BaseApp::ThreadLoop, this);
    return t;
}

std::thread BaseApp::RenderThread()
{
    std::thread t = std::thread(&BaseApp::ReanderLoop, this);
    return t;
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