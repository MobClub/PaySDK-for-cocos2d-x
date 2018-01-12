#include <ui/UIButton.h>
#include "HelloWorldScene.h"

#include "C2DXPaySDKTypeDef.h"

using namespace cocos2d::ui;
Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

void getMobIdHandler(const char * mobid)
{
    log("result - mobid = %s", mobid);
    std::string content = "mobId:";
    content += mobid;
    MessageBox(content.c_str(), "获取MobId的回调");
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
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    //this->addChild(sprite, 0);

    auto button = Button::create();
    button->setTitleText("PayWithAli");
    button->setPosition(Vec2(visibleSize.width/2 + origin.x, label->getPosition().y - 100));
    button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED: {
                C2DXPayOrder* order = C2DXPayOrder::create();
                order->setOrderNo("01");
                order->setAmount(1);
                order->setSubject("subject");
                order->setBody("body");
                C2DXAliPayApi* api = C2DXPaySDK::createMobPayAPI<C2DXAliPayApi>();

                C2DXOnPayListener<C2DXPayOrder, C2DXAliPayApi>* l = new OnPayListener<C2DXPayOrder, C2DXAliPayApi>(this);
                api->pay(order, l);

            }
                break;
            default:
                break;
        }
    });
    this->addChild(button);


    button = Button::create();
    button->setTitleText("PayWithWx");
    button->setPosition(Vec2(visibleSize.width/2 + origin.x, label->getPosition().y - 120));
    button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED: {
                C2DXPayOrder* order = C2DXPayOrder::create();
                order->setOrderNo("01");
                order->setAmount(1);
                order->setSubject("subject");
                order->setBody("body");
                C2DXWxPayApi* api = C2DXPaySDK::createMobPayAPI<C2DXWxPayApi>();
                C2DXOnPayListener<C2DXPayOrder, C2DXWxPayApi>* l = new OnPayListener<C2DXPayOrder, C2DXWxPayApi>(this);
                api->pay(order, l);

            }
                break;
            default:
                break;
        }
    });
    this->addChild(button);
    
    return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
