


#include "C2DXMobPayApi.h"

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






