#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "plat/windows/win_base.hpp"

namespace moob  {
    class GlApp
    {
    private:
        LRESULT HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam);
        
    public:
        virtual bool CreateMainWindow();
        virtual int Init() final;
    };
}
