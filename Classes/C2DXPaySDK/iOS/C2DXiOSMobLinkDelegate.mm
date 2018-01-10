//
//  C2DXiOSMobLinkDelegate.m
//  Cocos2DXForMobLink
//
//  Created by 陈剑东 on 2017/5/8.
//
//
#include "C2DXMobLinkTypeDef.h"

#import "C2DXiOSMobLinkDelegate.h"
#import <MobLink/MLSDKScene.h>
#import <MOBFoundation/MOBFJson.h>
@implementation C2DXiOSMobLinkDelegate

+ (C2DXiOSMobLinkDelegate *)defaultDelegate
{
    static C2DXiOSMobLinkDelegate *_instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        if (_instance == nil)
        {
            _instance = [[C2DXiOSMobLinkDelegate alloc] init];
        }
    });
    
    return _instance;
}

- (void)IMLSDKWillRestoreScene:(MLSDKScene *)scene Restore:(void (^)(BOOL isRestore, RestoreStyle style))restoreHandler
{
    NSC2DXString *path = scene.path;
    NSC2DXString *source = scene.source;
    NSC2DXString *customStr = [MOBFJson jsonC2DXStringFromObject:scene.params];
    
    C2DXiOSMobLink::resorteSceneCallBack([path UTF8C2DXString], [source UTF8C2DXString], [customStr UTF8C2DXString]);
    
    restoreHandler(NO, Default);
}

@end
