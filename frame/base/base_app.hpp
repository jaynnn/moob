#pragma once

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

namespace moob {
    constexpr uint8_t kMouseBtn = 5;
    constexpr size_t kMaxVertex = 128;

    enum kRet {
        fail = 0,
        succ = 1,
    };

    class BaseApp
    {
    private:
        
    public:
        BaseApp();
        ~BaseApp();
    };
    
    BaseApp::BaseApp()
    {
    }
    
    BaseApp::~BaseApp()
    {
    }
}