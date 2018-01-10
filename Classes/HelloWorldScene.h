#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;
using namespace std;
//using namespace mob::paysdk;
#include "C2DXPaySDKTypeDef.h"

class HelloWorld : public cocos2d::Scene , public C2DXOnPayListener<C2DXPayOrder, C2DXAliPayApi>
{
public:
    static cocos2d::Scene* createScene();

    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);


    virtual bool onWillPay(C2DXString ticketId, C2DXPayOrder* order, C2DXAliPayApi* api);
    virtual void onPayEnd(C2DXPayResult* payResult, C2DXPayOrder* order, C2DXAliPayApi* api);

};

#endif // __HELLOWORLD_SCENE_H__
