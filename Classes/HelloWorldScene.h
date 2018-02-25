#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "C2DXPaySDK/C2DXPaySDK.h"

USING_NS_CC;
using namespace std;
using namespace mob::paysdk;

class HelloWorld : public cocos2d::Scene, public C2DXPaySDKListener
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    //C2DXPaySDKListener
    bool onWillPay(std::string ticketId);
    void onPayEnd(C2DXPayStatus status, std::string ticketId, int errorCode, std::string errorDes);

private:
    std::string getOutOrderNO();
};

#endif

