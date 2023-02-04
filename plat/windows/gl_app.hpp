#include "plat/windows/win_base.hpp"


namespace moob  {
    class GlApp
    {
    private:
        
    public:
        GlApp();
        ~GlApp();
        virtual int Init();
        virtual void Tick();
    };
}
