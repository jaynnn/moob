#pragma once

//#include <OpenGL/gl.h>

#include "frame/base/base_app.hpp"
#include "third/windows/include/glad/glad.h"
#include "third/windows/include/glfw/glfw3.h"

namespace moob  {
    class GlApp
    {
    private:
        
    public:
        virtual bool CreateMainWindow();
        virtual void Init() final;
    };
}
