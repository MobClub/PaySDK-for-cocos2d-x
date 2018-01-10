#ifndef __C2DXPAYSDKBRIDGE__C2DXANDROIDALIAPI__
#define __C2DXPAYSDKBRIDGE__C2DXANDROIDALIAPI__



#include "C2DXMobPayApi.h"
#include "C2DXCxxJavaObject.h"
#include "C2DXPaySDK.h"

using namespace mob::paysdk;

namespace mob
{
    namespace paysdk
    {
        class C2DXAndroidAliApi : C2DXAliPayApi, C2DXCxxJavaObject {
        private:
            C2DXAndroidAliApi();
        public:
            CREATE_INSTANCE_FUNC(C2DXAndroidAliApi);
            virtual void pay(C2DXPayOrder* order, C2DXOnPayListener* callback);
            virtual void pay(C2DXTicketOrder* order, C2DXOnPayListener* callback);
        public:
            virtual ~C2DXAndroidAliApi();
        };

        class C2DXAndroidWxApi : C2DXWxPayApi {
        private:
            C2DXAndroidWxApi();
        public:
            CREATE_INSTANCE_FUNC(C2DXAndroidWxApi);
            virtual void pay(C2DXPayOrder* order, C2DXOnPayListener* callback);
            virtual void pay(C2DXTicketOrder* order, C2DXOnPayListener* callback);
        public:
            virtual ~C2DXAndroidAliApi();
        };
    }
}

#endif