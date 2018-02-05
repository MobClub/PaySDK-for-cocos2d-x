//
//  C2DXPaySDK.cpp
//  Cocos2D-For-PaySDK-mobile
//
//  Created by Max on 2018/1/26.
//

#include "C2DXPaySDK.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#include "C2DXiOSPaySDK.h"
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

#endif

using namespace paysdk;

void C2DXPaySDK::payWithTicketId(std::string ticketId, C2DXPayChannel channel, C2DXPaySDKListener *listener)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    C2DXiOSPaySDK::payWithTicketId(ticketId, listener);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

#endif
}

void C2DXPaySDK::payWithOrder(C2DXPayOrder *order, C2DXPayChannel channel, C2DXPaySDKListener *listener)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    C2DXiOSPaySDK::payWithOrder(order, channel, listener);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

#endif
}

void C2DXPaySDK::setDebugMode(bool enableDebug)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    C2DXiOSPaySDK::setDebugMode(enableDebug);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
#endif
}

std::string C2DXPaySDK::getVersion()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    return C2DXiOSPaySDK::getVersion();
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
#endif
}


