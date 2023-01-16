#pragma once

#include "common/config.hpp"

namespace moob {
    class AppInterface
    {
    private:
        
    public:
        virtual ~AppInterface() = default;
        [[nodiscard]] virtual bool IsQuit() const = 0;
        virtual void CreateMainWindow() = 0;
    };
}