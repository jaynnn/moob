#pragma once



#include "frame/base/base_app.hpp"


namespace moob {
    struct WindowCfg {
        int32_t window_w;
        int32_t window_h;
        int32_t pixel_w;
        int32_t pixel_h;
    };

    class Engine
    {
    private:
        WindowCfg cfg{1920, 1080, 4, 4};
        uint8_t is_quit_ = false;
        std::string app_name = "default";
    public:
        Engine();
        Engine(WindowCfg cfg, std::string app_name);
        int Init();
        virtual bool IsQuit();
        void Tick();
        virtual ~Engine();
    };
}
