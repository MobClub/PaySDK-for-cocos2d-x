


#include "C2DXMobPayApi.h"

using namespace mob::paysdk;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include "C2DXAndroidPayApi.h"

#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
// TODO handle ios
#endif


C2DXAliPayApi* C2DXAliPayApi::create() {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    C2DXAndroidAliApi* api = C2DXAndroidAliApi::create();
    return (C2DXAliPayApi*)api;
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    // TODO handle ios
#endif
}


void C2DXAliPayApi::pay(C2DXPayOrder* order, C2DXOnPayListener* callback)
{

}

void C2DXAliPayApi::pay(C2DXTicketOrder* order, C2DXOnPayListener* callback)
{

}


C2DXWxPayApi* C2DXWxPayApi::create() {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    C2DXWxPayApi* api = C2DXAndroidWxApi::create();
    return (C2DXWxPayApi*)api;
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    // TODO handle ios
#endif
}






C2DXWxPayApi* C2DXWxPayApi::create() {

}


virtual void pay(C2DXPayOrder* order, C2DXOnPayListener* callback);
virtual void pay(C2DXTicketOrder* order, C2DXOnPayListener* callback);

class C2DXAliPayApi : C2DXMobPayApi {
private:
    C2DXAliPayApi();
public:
    CREATE_INSTANCE_FUNC(C2DXAliPayApi);
    virtual void pay(C2DXPayOrder* order, C2DXOnPayListener* callback);
    virtual void pay(C2DXTicketOrder* order, C2DXOnPayListener* callback);
public:
    virtual ~C2DXAliPayApi();
};


class C2DXWxPayApi : C2DXMobPayApi {
private:
    C2DXWxPayApi();
public:
    CREATE_INSTANCE_FUNC(C2DXWxPayApi);
    virtual void pay(C2DXPayOrder* order, C2DXOnPayListener* callback);
    virtual void pay(C2DXTicketOrder* order, C2DXOnPayListener* callback)

public:
    virtual ~C2DXWxPayApi();
};






