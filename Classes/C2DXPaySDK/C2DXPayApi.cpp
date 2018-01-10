


#include "C2DXPayApi.h"

using namespace mob::paysdk;

#if defined(ANDROID)
#include "C2DXAndroidPayApi.h"
#elif defined(CC_TARGET_OS_IPHONE)
//TODO handle ios
#endif

C2DXAliPayApi* C2DXAliPayApi::create() {
#if defined(ANDROID)
    C2DXAndroidAliApi* api = C2DXAndroidAliApi::create();
    return (C2DXAliPayApi*)api;
#elif defined(CC_TARGET_OS_IPHONE)
    //TODO ios impl
#endif
}

C2DXAliPayApi::C2DXAliPayApi()
{
}

template <class O> void C2DXAliPayApi::pay(O* order, C2DXOnPayListener<O, C2DXAliPayApi>* callback)
{
#if defined(ANDROID)
    C2DXAndroidAliApi* api = (C2DXAndroidAliApi*)this;
    api->pay(order, callback);
#elif defined(CC_TARGET_OS_IPHONE)
    //TODO ios impl
#endif
}

C2DXAliPayApi::~C2DXAliPayApi()
{
}

C2DXWxPayApi* C2DXWxPayApi::create() {
#if defined(ANDROID)
    C2DXAndroidWxApi* api = C2DXAndroidWxApi::create();
    return (C2DXWxPayApi*)api;
#elif defined(CC_TARGET_OS_IPHONE)
    //TODO ios impl
#endif
}

C2DXWxPayApi::C2DXWxPayApi()
{
}

template <class O> void C2DXWxPayApi::pay(O* order, C2DXOnPayListener<O, C2DXWxPayApi>* callback)
{

}

C2DXWxPayApi::~C2DXWxPayApi()
{
}






