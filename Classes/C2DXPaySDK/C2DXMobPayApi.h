#ifndef __C2DXPAYSDKBRIDGE__C2DXMOBPAYAPI__
#define __C2DXPAYSDKBRIDGE__C2DXMOBPAYAPI__

#include "C2DXPayOrder.h"
#include "C2DXOnPayListener.h"

#define CREATE_FUNC(__TYPE__) \
static __TYPE__* create()

using namespace mob::paysdk;

namespace mob
{
    namespace paysdk
    {
        virtual class C2DXMobPayApi {
        private:
            C2DXMobPayApi();
        public:
            virtual void pay(C2DXPayOrder* order, C2DXOnPayListener* callback) = 0;
        public:
            virtual ~C2DXMobPayApi();
        };
    }
}

#endif
