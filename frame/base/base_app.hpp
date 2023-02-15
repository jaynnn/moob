#pragma once

#include <iostream>
#include <cmath>
#include <cstdint>
#include <string>
#include <streambuf>
#include <sstream>
#include <chrono>
#include <vector>
#include <list>
#include <thread>
#include <atomic>
#include <fstream>
#include <map>
#include <functional>
#include <algorithm>
#include <array>
#include <cstring>
#include <filesystem>

#include "common/draw_struct.hpp"
#include "frame/interface/app_interface.hpp"
#include "frame/interface/mgr_interface.hpp"
#include "frame/interface/render_interface.hpp"

namespace moob {
    constexpr uint8_t kMouseBtn = 5;
    constexpr size_t kMaxVertex = 128;
    constexpr int FAIL = 0;
    constexpr int SUCC = 1;

    class BaseApp : public AppInterface
    {
    public:
        BaseApp() = default;
        BaseApp(AppCfg& cfg) : app_config_(cfg) {}
        virtual ~BaseApp();
        
        [[nodiscard]] bool IsQuit() const override;

        bool CreateMainWindow() override { return true; };
        virtual int Init();
        virtual void Tick();
        virtual void PlatTick() = 0;
        std::thread MainThread();

        int32_t ScreenWidth();
        int32_t ScreenHeight();

    protected:
        AppCfg app_config_;
        void RegistMgr(RenderMgrInterface *renderer);
        std::vector<moob::DrawInfo>  DrawFlow_;
    private:
        void ThreadLoop();
        bool ThreadStart();
        void ThreadEnd();

        bool is_quit_ = false;

        template <typename T>
        void RegistMgrT(T *mgr);
        std::vector<MgrInterface *> mgrs = {};
    };
}