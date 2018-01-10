#ifndef __C2DXPAYSDKBRIDGE__C2DXPAYSDK__
#define __C2DXPAYSDKBRIDGE__C2DXPAYSDK__

#define CREATE_INSTANCE_FUNC(__TYPE__) \
static __TYPE__* create()

typedef std::string C2DXString;

#include "C2DXPayResult.h"
#include "string.h"



namespace mob
{
    namespace paysdk
    {
        class C2DXPaySDK
        {
        public:
            template <class API> static API* createMobPayAPI() {
                return API::create();
            }
        };

        template <class O, class API>
        class C2DXOnPayListener
        {
        public:
            virtual bool onWillPay(C2DXString ticketId, O* order, API* api) = 0;
            virtual void onPayEnd(C2DXPayResult* payResult, O* order, API* api) = 0;
        };
        
    }
};

#endif
