#ifndef __C2DXPAYSDKBRIDGE__C2DXMOBPAYAPI__
#define __C2DXPAYSDKBRIDGE__C2DXMOBPAYAPI__

#include "C2DXOrder.h"
#include "C2DXPaySDK.h"

using namespace mob::paysdk;

namespace mob
{
    namespace paysdk
    {

        class C2DXAliPayApi {
        protected:
            C2DXAliPayApi();
        public:
            CREATE_INSTANCE_FUNC(C2DXAliPayApi);
            template <class O> void pay(O* order, C2DXOnPayListener<O, C2DXAliPayApi>* callback);
        public:
            virtual ~C2DXAliPayApi();
        };


        class C2DXWxPayApi {
        protected:
            C2DXWxPayApi();
        public:
            CREATE_INSTANCE_FUNC(C2DXWxPayApi);
            template <class O> void pay(O* order, C2DXOnPayListener<O, C2DXWxPayApi>* callback);
        public:
            virtual ~C2DXWxPayApi();
        };
    }
}

#endif
