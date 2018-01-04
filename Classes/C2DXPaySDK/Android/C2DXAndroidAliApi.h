#ifndef __C2DXPAYSDKBRIDGE__C2DXANDROIDALIAPI__
#define __C2DXPAYSDKBRIDGE__C2DXANDROIDALIAPI__



#include "C2DXAliPayApi.h"

using namespace mob::paysdk;

namespace mob
{
    namespace paysdk
    {
        class C2DXAndroidAliApi : C2DXAliPayApi {
        private:
            C2DXAndroidAliApi();
        public:
            CREATE_FUNC(C2DXAndroidAliApi);
            virtual void pay(C2DXPayOrder* order, C2DXOnPayListener* callback);

        public:
            virtual ~C2DXAndroidAliApi();
        };
    }
}

#endif