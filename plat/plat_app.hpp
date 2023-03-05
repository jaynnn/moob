#pragma once

#include "common/config.hpp"
#include "plat/windows/d2d_app.hpp"

#define MOOB_LOG_LEVEL 1
namespace moob 
{
    using PlatApp = D2dApp;
    using RendererMgr = D2dMgr;
}
