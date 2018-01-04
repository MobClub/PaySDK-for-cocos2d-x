#ifndef __C2DXPAYSDKBRIDGE__C2DXWXPAYAPI__
#define __C2DXPAYSDKBRIDGE__C2DXWXPAYAPI__

#include "C2DXMobPayApi.h"

namespace mob
{
    namespace paysdk
    {
        class C2DXWxPayApi : C2DXMobPayApi {
        private:
            C2DXWxPayApi();
        public:
            CREATE_FUNC(C2DXWxPayApi);
            void pay(C2DXPayOrder* order, C2DXOnPayListener* callback);

        public:
            virtual ~C2DXWxPayApi();
        };
    }
}

#endif
