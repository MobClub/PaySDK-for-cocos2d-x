
#ifndef __C2DXPAYSDKBRIDGE__C2DXANDROIDONPAYSDK__
#define __C2DXPAYSDKBRIDGE__C2DXANDROIDONPAYSDK__

#include <stdio.h>
#include "cocos2d.h"
#include "C2DXPaySDK.h"

namespace mob {
    namespace paysdk {
        class C2DXAndroidPaySDK {
        public:
            /**
             通过ticketId支付

             @param ticketId 支付
             */
            static void payWithTicketId(std::string ticketId, C2DXPayChannel, C2DXPaySDKListener *listener);

            /**
             支付订单

             @param order 通过
             */
            static void
            payWithOrder(C2DXPayOrder *order, C2DXPayChannel channel, C2DXPaySDKListener *listener);

            /**
             开启debugLog iOS only

             @param enableDebug 是否开启日志
             */
            static void setDebugMode(bool enableDebug);

            /**
             获取版本号

             @return 版本号
             */
            static std::string getVersion();

            //callback
            static void onWillPay(std::string ticketId);

            static void onPayEnd(C2DXPayStatus status, std::string ticketId, int errorCode,
                                 std::string errorDes);
        };
    }
}

#endif
