#include "frame/mgr/combo_mgr.hpp"

using namespace moob;


    
ComboMgr::ComboMgr()
{
}

ComboMgr::~ComboMgr()
{
}

ComboMgr::ComboMgr(int type, const Combo &combo)
{
    type2Combos_[type].push_back(combo);
    switch (type)
    {
    case 1:
        
        break;
    
    default:
        break;
    }
}