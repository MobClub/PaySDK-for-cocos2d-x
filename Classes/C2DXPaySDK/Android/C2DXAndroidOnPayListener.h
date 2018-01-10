#ifndef __C2DXPAYSDKBRIDGE__C2DXANDROIDONPAYLISTENER__
#define __C2DXPAYSDKBRIDGE__C2DXANDROIDONPAYLISTENER__

#include "C2DXCxxJavaObject.h"
#include "C2DXPaySDK.h"

using namespace mob::paysdk;

namespace mob
{
    namespace paysdk
    {
        template
        class C2DXAndroidOnPayListener : C2DXCxxJavaObject {
        public:
            CREATE_INSTANCE_FUNC(C2DXAndroidOnPayListener);
        public:
            C2DXAndroidOnPayListener();

        public:
            void setOnPayListener(C2DXOnPayListener* callback);



//            void onWillPay(String ticketId, O* order, API* api);
//            void onPayEnd(C2DXPayResult* payResult, O* order, API* api);

        private:
            C2DXOnPayListener* onPayListener;
        public:
            virtual ~C2DXAndroidAliApi();
        };
    }
}

#endif