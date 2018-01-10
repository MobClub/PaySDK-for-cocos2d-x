#ifndef __C2DXPAYSDKBRIDGE__C2DXMOBPAYAPI__
#define __C2DXPAYSDKBRIDGE__C2DXMOBPAYAPI__

#include "C2DXOrder.h"
#include "C2DXPaySDK.h"

using namespace mob::paysdk;

namespace mob
{
    namespace paysdk
    {

        template <class O> class C2DXAliPayApi {
        private:
            C2DXAliPayApi();
        public:
            CREATE_INSTANCE_FUNC(C2DXAliPayApi);
            virtual void pay(O* order, C2DXOnPayListener<O, C2DXAliPayApi>* callback);
//            virtual void pay(C2DXTicketOrder* order, C2DXOnPayListener* callback);
        public:
            virtual ~C2DXAliPayApi();
        };


        template <class O> class C2DXWxPayApi {
        private:
            C2DXWxPayApi();
        public:
            CREATE_INSTANCE_FUNC(C2DXWxPayApi);
            virtual void pay(O* order, C2DXOnPayListener<O, C2DXWxPayApi>* callback);
//            virtual void pay(C2DXTicketOrder* order, C2DXOnPayListener* callback);

        public:
            virtual ~C2DXWxPayApi();
        };
    }
}

#endif
