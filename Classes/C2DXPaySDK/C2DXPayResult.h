#ifndef __C2DXPAYSDKBRIDGE__C2DXPAYRESULT__
#define __C2DXPAYSDKBRIDGE__C2DXPAYRESULT__

#include <stdio.h>

/** 支付结果, 支付成功 */
#define PAYRESULT_OK 0

/**
 * 支付结果, 支付错误.<br/>
 * 可能的原因：签名错误、未注册APPID、项目设置APPID不正确、注册的APPID与设置的不匹配、其他异常等。
 */
#define PAYRESULT_ERROR 1


/**
 * 支付结果, 支付取消.<br/>
 * 无需处理。发生场景：用户不支付了，点击取消，返回APP
 */
#define PAYRESULT_CANCEL 2

/** 支付结果， 支付渠道未开通 */
#define PAYRESULT_INVALID_CHANNEL 3

namespace mob
{
    namespace paysdk
    {
        class C2DXPayResult {
        public:
            C2DXPayResult();

            /**
             * 设置支付结果状态码(开发者不需要调用)
             * @param status 状态码
             */
            void setPayStatus(int status);

            /**
             * 获取支付结果状态码
             * @return 状态码
             */
            int getPayStatus();

            ~C2DXPayResult();
        private:
            int payStatus;
        };
    }
}

#endif
