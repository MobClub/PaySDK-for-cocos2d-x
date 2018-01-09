#include "C2DXOrder.h"

#if defined(ANDROID)
#include "C2DXAndroidOrder.h"
#elif defined(CC_TARGET_OS_IPHONE)
//TODO ios 头文件
#endif


using namespace mob::paysdk;

C2DXPayOrder* C2DXPayOrder::create()
{
#if defined(ANDROID)
    C2DXAndroidPayOrder* order = C2DXAndroidPayOrder::create();
    return order;
#elif defined(CC_TARGET_OS_IPHONE)
    //TODO ios impl
#endif
}

C2DXPayOrder::C2DXPayOrder()
{
}


/**
 * 获取之前配置的支付订单号
 * @return 订单号
 */
String C2DXPayOrder::getOrderNo()
{
}

/**
 * 设置支付订单号
 * @param orderNo 订单号
 */
void C2DXPayOrder::setOrderNo(String orderNo)
{
}

/**
 * 获取之前配置的支付金额, 单位：分.
 * @return 支付金额
 */
int C2DXPayOrder::getAmount()
{
    return 0;
}

/**
 * 设置支付金额, 单位：分.
 * @param amount 支付金额
 */
void C2DXPayOrder::setAmount(int amount)
{
}

/**
 * 获取之前配置的支付标题, 支付时展示
 * @return 支付标题
 */
String C2DXPayOrder::getSubject()
{
}

/**
 * 设置支付标题, 支付时展示
 * @param subject 支付标题
 */
void C2DXPayOrder::setSubject(String subject)
{
}

/**
 * 获取之前配置的支付主体, 支付时展示
 * @return 支付主体
 */
String C2DXPayOrder::getBody()
{
}

/**
 * 设置支付主体, 支付时展示
 * @return 支付主体
 */
void C2DXPayOrder::setBody(String body)
{
}

String C2DXPayOrder::getDescription()
{
}

void C2DXPayOrder::setDescription(String description)
{
}

String C2DXPayOrder::getMetadata()
{
}

void C2DXPayOrder::setMetadata(String metadata)
{
}

/**
 * 获取ticketId
 * @return ticketId
 */
String C2DXPayOrder::getTicketId()
{
}

/**
 * 设置ticketId
 * @param tId ticketId
 */
void C2DXPayOrder::setTicketId(String ticketId)
{
}

/**
 * 设置ticketId
 * @param tId ticketId
 */
void C2DXTicketOrder::setTicketId(String tId)
{
}

/**
 * 获取ticketId
 * @return ticketId
 */
String C2DXTicketOrder::getTicketId()
{
}