


#include "C2DXAliPayApi.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include "C2DXAndroidAliApi.h"

#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
// TODO handle ios
#endif


C2DXAliPayApi* C2DXAliPayApi::create() {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    C2DXAndroidAliApi* api = C2DXAndroidAliApi::create();
    return api;
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    // TODO handle ios
#endif
}






