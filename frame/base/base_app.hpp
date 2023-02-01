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

#include "frame/interface/app_interface.hpp"

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
        virtual int Init();
        virtual void Tick();
        [[nodiscard]] bool IsQuit() const override;
        virtual void PlatTick() = 0;
        bool CreateMainWindow() override { return true; };
    protected:
        AppCfg app_config_;
    private:
        bool is_quit_ = false;
    };
}