#ifndef __C2DXPAYSDKBRIDGE__C2DXANDROIDALIAPI__
#define __C2DXPAYSDKBRIDGE__C2DXANDROIDALIAPI__

#include "C2DXCxxJavaObject.h"
#include "C2DXPaySDK.h"
#include "C2DXAndroidOrder.h"
#include "C2DXAndroidTypeDef.h"

using namespace mob::paysdk;

namespace mob
{
    namespace paysdk
    {
        class C2DXAndroidAliApi : public C2DXCxxJavaObject {
        private:
            C2DXAndroidAliApi();
        public:
            CREATE_INSTANCE_FUNC(C2DXAndroidAliApi);
            virtual void pay(C2DXAndroidPayOrder* order, C2DXOnPayListener* callback);
            virtual void pay(C2DXAndroidTicketOrder* order, C2DXOnPayListener* callback);
        public:
            virtual ~C2DXAndroidAliApi();
        };

        class C2DXAndroidWxApi : public C2DXCxxJavaObject {
        private:
            C2DXAndroidWxApi();
        public:
            CREATE_INSTANCE_FUNC(C2DXAndroidWxApi);
            virtual void pay(C2DXAndroidPayOrder* order, C2DXOnPayListener* callback);
            virtual void pay(C2DXAndroidTicketOrder* order, C2DXOnPayListener* callback);
        public:
            virtual ~C2DXAndroidWxApi();
        };
    }
}

#endif