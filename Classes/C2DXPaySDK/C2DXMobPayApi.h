#ifndef __C2DXPAYSDKBRIDGE__C2DXMOBPAYAPI__
#define __C2DXPAYSDKBRIDGE__C2DXMOBPAYAPI__

#include "C2DXOrder.h"
#include "C2DXOnPayListener.h"

#define CREATE_INSTANCE_FUNC(__TYPE__) \
static __TYPE__* create()

using namespace mob::paysdk;

namespace mob
{
    namespace paysdk
    {
        class C2DXMobPayApi {
        private:
            C2DXMobPayApi();
        public:
            virtual void pay(C2DXPayOrder* order, C2DXOnPayListener* callback) = 0;
        public:
            virtual ~C2DXMobPayApi();
        };
		
		
		
		class C2DXAliPayApi : C2DXMobPayApi {
        private:
            C2DXAliPayApi();
        public:
            CREATE_INSTANCE_FUNC(C2DXAliPayApi);
            virtual void pay(C2DXPayOrder* order, C2DXOnPayListener* callback);

        public:
            virtual ~C2DXAliPayApi();
        };
		
		
		class C2DXWxPayApi : C2DXMobPayApi {
        private:
            C2DXWxPayApi();
        public:
            CREATE_INSTANCE_FUNC(C2DXWxPayApi);
            void pay(C2DXPayOrder* order, C2DXOnPayListener* callback);

        public:
            virtual ~C2DXWxPayApi();
        };
    }
}

#endif
