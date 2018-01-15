#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;
using namespace std;
#include "C2DXPaySDKTypeDef.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

    std::string getOutOrderNO();

};


template <typename O, typename API>
class OnPayListener : public C2DXOnPayListener<O, API>
{
public:
    OnPayListener(HelloWorld* out)
    {
        outer = out;
    }
    virtual bool onWillPay(C2DXString ticketId, O* order, API* api)
    {
        return false;
    }
    virtual void onPayEnd(C2DXPayResult* payResult, O* order, API* api)
    {
        // TODO 支付结束
    }

    HelloWorld* outer;
};

#endif

