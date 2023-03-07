#pragma once

#include <iostream>

namespace moob 
{
    class AppCfg
    {
    public:
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

        // 1.(client combo)
        // 2.(root server combo)
        // 4.(pixel logic commbo)
        // (client combo) + (root server combo) + (pixel logic commbo) = 7
        uint32_t engine_mode_ = 0;

        void CollectArgs(int argc, char** argv)
        {
            for (int i = 1; argv[i] != nullptr; i++) {
                if (argv[i][0] != '-')
                    return;
                switch (argv[i][1])
                {
                    case 'm':
                        if (argv[i][2] == '\0' ||
                                argv[i][2] < 48 || argv[i][2] > 57)
                            return;
                    engine_mode_ = (argv[i][2] - '0') | engine_mode_;
                    std::cout << "engine mode: " <<  engine_mode_ << std::endl;
                }
            }
        }
    };
}
