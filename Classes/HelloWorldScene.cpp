#include <ui/UIButton.h>
#include "HelloWorldScene.h"
#include "C2DXPaySDK.h"
#include "string"

using namespace cocos2d::ui;
Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    C2DXPaySDK::setDebugMode(true);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto button = Button::create();
    button->setTitleText("支付宝支付");
    button->setPosition(Vec2(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - 150));
    button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED: {
                C2DXPayOrder *order = new C2DXPayOrder();
                order -> subject = "orderSubject";
                order -> orderId = getOutOrderNO();
                order -> amount = 1;
                order -> body = "order_body";
                order -> desc = "order_desc";
                order -> metadata = "order_metaData";
                order -> appUserId = "userId";
                order -> appUserNickname = "nickName";
                C2DXPaySDK::payWithOrder(order, C2DXPayChannelAlipay, this);
            }
                break;
            default:
                break;
        }
    });
    this->addChild(button);

    button = Button::create();
    button->setTitleText("微信支付");
    button->setPosition(Vec2(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - 200));
    button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED: {
                C2DXPayOrder *order = new C2DXPayOrder();
                order -> subject = "orderSubject";
                order -> orderId = getOutOrderNO();
                order -> amount = 1;
                order -> body = "order_body";
                order -> desc = "order_desc";
                order -> metadata = "order_metaData";
                order -> appUserId = "userId";
                order -> appUserNickname = "nickName";
                C2DXPaySDK::payWithOrder(order, C2DXPayChannelWechat, this);
            }
                break;
            default:
                break;
        }
    });
    this->addChild(button);
    
    return true;
}

void HelloWorld::onPayEnd(mob::paysdk::C2DXPayStatus status, std::string ticketId, int errorCode, std::string errorDes)
{
    switch (status)
    {
        case mob::paysdk::C2DXPayStatusSuccess:
            printf("\n ---> 支付结果：success!,%s\n",ticketId.c_str());
            break;
        
        case mob::paysdk::C2DXPayStatusFail:
            printf("\n ---> 支付结果：fail!,%s,%s\n",ticketId.c_str(),errorDes.c_str());
            break;
            
        default:
            printf("\n ---> 支付结果：cancel!,%s\n",ticketId.c_str());
            break;
    }
}

bool HelloWorld::onWillPay(std::string ticketId)
{
    printf("\n ---> 开始支付%s\n",ticketId.c_str());
    return true;
}


std::string HelloWorld::getOutOrderNO()
{
    return StringUtils::format("%ld", clock());
}

