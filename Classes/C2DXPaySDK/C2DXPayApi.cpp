


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

C2DXWxPayApi::~C2DXWxPayApi()
{
}






