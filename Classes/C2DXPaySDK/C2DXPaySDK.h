#ifndef __C2DXPAYSDKBRIDGE__C2DXPAYSDK__
#define __C2DXPAYSDKBRIDGE__C2DXPAYSDK__

#include "C2DXOrder.h"
#include "C2DXPayResult.h"


#define CREATE_INSTANCE_FUNC(__TYPE__) \
static __TYPE__* create()

namespace mob
{
    namespace paysdk
    {

        class C2DXPaySDK
        {
        public:
            template <typename T> static T* createMobPayAPI() {
                return T::create();
            }
        };

        template <class O, class API>
        class C2DXOnPayListener
        {
        public:
            virtual bool onWillPay(String ticketId, O* order, API* api) = 0;
            virtual void onPayEnd(C2DXPayResult* payResult, O* order, API* api) = 0;
        };
        
    }
};

#endif
