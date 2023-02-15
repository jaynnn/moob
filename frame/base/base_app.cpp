#include "frame/base/base_app.hpp"
#include "frame/mgr/pixel_mgr.hpp"

using namespace moob;

BaseApp::~BaseApp() 
{
}

int BaseApp::Init() 
{
    // regist renderer
    

    // regist mgr
    PixelMgr pixelMgr;
    RegistMgrT<PixelMgr>(&pixelMgr);

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

void BaseApp::Tick() 
{
    for (auto it = begin(mgrs); it != end(mgrs); it++) 
    {
        (*it)->Tick();
    }
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
    mgrs.push_back(mgr);
}

void BaseApp::RegistMgr(RenderMgrInterface *renderer_mgr) 
{
    mgrs.push_back(renderer_mgr);
}