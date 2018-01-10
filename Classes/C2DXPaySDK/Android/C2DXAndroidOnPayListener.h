#ifndef __C2DXPAYSDKBRIDGE__C2DXANDROIDONPAYLISTENER__
#define __C2DXPAYSDKBRIDGE__C2DXANDROIDONPAYLISTENER__

#include "C2DXCxxJavaObject.h"
#include "C2DXPaySDK.h"

using namespace mob::paysdk;

namespace mob
{
    namespace paysdk
    {
        class C2DXAndroidOnPayListener : public C2DXCxxJavaObject {
        public:
            CREATE_INSTANCE_FUNC(C2DXAndroidOnPayListener);
        public:
            C2DXAndroidOnPayListener();

        public:
            template <typename O, typename API>
            void setOnPayListener(C2DXOnPayListener<O, API>* callback)
            {
                onPayListener = callback;
            }



//            void onWillPay(C2DXString ticketId, O* order, API* api);
//            void onPayEnd(C2DXPayResult* payResult, O* order, API* api);

        private:
            void* onPayListener;
        public:
            virtual ~C2DXAndroidOnPayListener();
        };
    }
}

#endif