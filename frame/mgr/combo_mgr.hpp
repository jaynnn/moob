#pragma once

#include <vector>
#include <map>

#include "frame/base/combo.hpp"

namespace moob 
{
    class ComboMgr
    {
    private:
        std::map<int, std::vector<Combo>> type2Combos_;
    public:
        ComboMgr();
        ComboMgr(int type, const Combo &combo);
        ~ComboMgr();
    };
    
}