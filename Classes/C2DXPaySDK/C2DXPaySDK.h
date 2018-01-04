#ifndef __C2DXPAYSDKBRIDGE__C2DXPAYSDK__
#define __C2DXPAYSDKBRIDGE__C2DXPAYSDK__

#include "C2DXPayOrder.h"


namespace mob
{
    namespace paysdk
    {

        class C2DXPaySDK
        {
        public:
            template <typename T> static T* createMobPayAPI() {
                return T::create();
            }
        };
        
    }
};

#endif
