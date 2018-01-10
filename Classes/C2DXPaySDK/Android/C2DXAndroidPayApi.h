#ifndef __C2DXPAYSDKBRIDGE__C2DXANDROIDALIAPI__
#define __C2DXPAYSDKBRIDGE__C2DXANDROIDALIAPI__



#include "C2DXPayApi.h"
#include "C2DXCxxJavaObject.h"
#include "C2DXPaySDK.h"
#include "C2DXPayApi.h"

using namespace mob::paysdk;

namespace mob
{
    namespace paysdk
    {
        class C2DXAndroidAliApi : public C2DXAliPayApi, public C2DXCxxJavaObject {
        private:
            C2DXAndroidAliApi();
        public:
            CREATE_INSTANCE_FUNC(C2DXAndroidAliApi);
            virtual void pay(C2DXPayOrder* order, C2DXOnPayListener<C2DXPayOrder, C2DXAliPayApi>* callback);
            virtual void pay(C2DXTicketOrder* order, C2DXOnPayListener<C2DXTicketOrder, C2DXAliPayApi>* callback);
        public:
            virtual ~C2DXAndroidAliApi();
        };

        class C2DXAndroidWxApi : C2DXWxPayApi, public C2DXCxxJavaObject {
        private:
            C2DXAndroidWxApi();
        public:
            CREATE_INSTANCE_FUNC(C2DXAndroidWxApi);
            virtual void pay(C2DXPayOrder* order, C2DXOnPayListener<C2DXPayOrder, C2DXWxPayApi>* callback);
            virtual void pay(C2DXTicketOrder* order, C2DXOnPayListener<C2DXTicketOrder, C2DXWxPayApi>* callback);
        public:
            virtual ~C2DXAndroidWxApi();
        };
    }
}

#endif