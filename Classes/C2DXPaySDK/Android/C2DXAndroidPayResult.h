#ifndef __C2DXPAYSDKBRIDGE__C2DXALIPAYAPI__
#define __C2DXPAYSDKBRIDGE__C2DXALIPAYAPI__

#include "C2DXMobPayApi.h"

using namespace mob::paysdk;

namespace mob
{
    namespace paysdk
    {
        class C2DXAliPayApi : C2DXMobPayApi {
        private:
            C2DXAliPayApi();
        public:
            CREATE_INSTANCE_FUNC(C2DXAliPayApi);
            virtual void pay(C2DXPayOrder* order, C2DXOnPayListener* callback);

        public:
            virtual ~C2DXAliPayApi();
        };
    }
}

#endif
