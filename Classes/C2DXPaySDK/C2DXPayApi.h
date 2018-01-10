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
            virtual void pay(C2DXPayOrder* order, C2DXOnPayListener<C2DXPayOrder, C2DXAliPayApi>* callback) = 0;
            virtual void pay(C2DXTicketOrder* order, C2DXOnPayListener<C2DXTicketOrder, C2DXAliPayApi>* callback) = 0;
        public:
            virtual ~C2DXAliPayApi();
        };


        class C2DXWxPayApi {
        protected:
            C2DXWxPayApi();
        public:
            CREATE_INSTANCE_FUNC(C2DXWxPayApi);
            virtual void pay(C2DXPayOrder* order, C2DXOnPayListener<C2DXPayOrder, C2DXWxPayApi>* callback) = 0;
            virtual void pay(C2DXTicketOrder* order, C2DXOnPayListener<C2DXTicketOrder, C2DXWxPayApi>* callback) = 0;
        public:
            virtual ~C2DXWxPayApi();
        };
    }
}

#endif
