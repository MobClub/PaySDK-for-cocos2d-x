#ifndef __C2DXPAYSDKBRIDGE__C2DXANDROIDORDER__
#define __C2DXPAYSDKBRIDGE__C2DXANDROIDORDER__


#include <stdio.h>
#include "jni.h"

#include "C2DXOrder.h"
#include "C2DXCxxJavaObject.h"

namespace mob
{
    namespace paysdk
    {

        class C2DXAndroidPayOrder : public C2DXPayOrder, C2DXCxxJavaObject
        {
        public:
            CREATE_INSTANCE_FUNC(C2DXAndroidPayOrder);

            /**
             * 获取之前配置的支付订单号
             * @return 订单号
             */
            virtual String getOrderNo();

            /**
             * 设置支付订单号
             * @param orderNo 订单号
             */
            virtual void setOrderNo(String orderNo);

            /**
             * 获取之前配置的支付金额, 单位：分.
             * @return 支付金额
             */
            virtual int getAmount();

            /**
             * 设置支付金额, 单位：分.
             * @param amount 支付金额
             */
            virtual void setAmount(int amount);

            /**
             * 获取之前配置的支付标题, 支付时展示
             * @return 支付标题
             */
            virtual String getSubject();

            /**
             * 设置支付标题, 支付时展示
             * @param subject 支付标题
             */
            virtual void setSubject(String subject);

            /**
             * 获取之前配置的支付主体, 支付时展示
             * @return 支付主体
             */
            virtual String getBody();

            /**
             * 设置支付主体, 支付时展示
             * @return 支付主体
             */
            virtual void setBody(String body);

            virtual String getDescription();

            virtual void setDescription(String description);

            virtual String getMetadata();

            virtual void setMetadata(String metadata);

            /**
             * 获取ticketId
             * @return ticketId
             */
            virtual String getTicketId();

        private:
            C2DXAndroidPayOrder();
        public:
            virtual ~C2DXAndroidPayOrder();
        };


        class C2DXAndroidTicketOrder : public C2DXTicketOrder, C2DXCxxJavaObject
        {

        public:
            CREATE_INSTANCE_FUNC(C2DXAndroidTicketOrder);

            /**
             * 设置ticketId
             * @param tId ticketId
             */
            virtual void setTicketId(String tId);

            /**
             * 获取ticketId
             * @return ticketId
             */
            virtual String getTicketId();

        private:
            C2DXAndroidTicketOrder();

        public:
            virtual ~C2DXAndroidTicketOrder();
        };
    }
}

#endif
