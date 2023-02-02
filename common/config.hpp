#pragma once

#include <iostream>

namespace moob {
    struct AppCfg
    {
        explicit AppCfg(
            uint32_t screen_w = 800, uint32_t screen_h = 600,
            uint32_t pixel_w = 4, uint32_t pixel_h = 4,
            uint32_t rgba = 0xFF000000,
            const char *appname = "MOOB"
            ) : 
        screen_w_(screen_w), 
        screen_h_(screen_h),
        pixel_w_(pixel_w),
        pixel_h_(pixel_h),
        rgba_(rgba),
        appname_(appname) {};

        uint32_t screen_w_;
        uint32_t screen_h_;
        uint32_t pixel_w_;
        uint32_t pixel_h_;
        uint32_t rgba_;
        const char *appname_;
    };
}
