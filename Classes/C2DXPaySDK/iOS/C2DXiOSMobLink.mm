//
//  C2DXiOSMobLink.m
//  Cocos2DXForMobLink
//
//  Created by 陈剑东 on 2017/5/8.
//
//

#include "C2DXiOSMobLink.h"
#include "C2DXMobLinkScene.h"
#include "C2DXMobLinkTypeDef.h"

#import <MobLink/MobLink.h>
#import <MobLink/MLSDKScene.h>
#import <MOBFoundation/MOBFJson.h>
#import "C2DXiOSMobLinkDelegate.h"

using namespace mob::moblink;

/**
 *	@brief	转换NSDictionary为C2DXDictionary类型
 *
 *	@param 	dict 	字典
 *
 *	@return	字典类型
 */
C2DXDictionary* convertNSDictToCCDict(NSDictionary *dict);

/**
 *	@brief	转换C2DXDictionary为NSDictionary类型
 *
 *	@param 	dict 	字典
 *
 *	@return	字典类型
 */
NSMutableDictionary* convertC2DXDictionaryToNSDictionary(C2DXDictionary *Dictionary);

/**
 *	@brief	转换NSC2DXString为C2DXC2DXString类型
 *
 *	@param 	C2DXString 	字符串
 *
 *	@return	字符类型
 */
C2DXC2DXString* convertNSC2DXStringToC2DXC2DXString(NSC2DXString *C2DXString);

/**
 *	@brief	转换C2DXC2DXString为NSC2DXString类型
 *
 *	@param 	C2DXString 	字符串
 *
 *	@return	字符类型
 */
NSC2DXString* convertC2DXC2DXStringToNSC2DXString(C2DXC2DXString *C2DXString);

/**
 *	@brief	转换NSArray为C2DXArray类型
 *
 *	@param 	array 	数组
 *
 *	@return	数组类型
 */
C2DXArray* convertNSArrayToC2DXArray(NSArray *array);

/**
 *	@brief	转换C2DXArray为NSArray类型
 *
 *	@param 	array 	数组
 *
 *	@return	数组类型
 */
NSArray* convertC2DXArrayToNSArray(C2DXArray *Array);

C2DXDictionary* convertNSDictToCCDict(NSDictionary *dict)
{
    if (dict)
    {
        C2DXDictionary *ccDict = C2DXDictionary::create();
        NSArray *allKeys = [dict allKeys];
        for (int i = 0; i < [allKeys count]; i++)
        {
            NSC2DXString *key = [allKeys objectAtIndex:i];
            id value = [dict objectForKey:key];
            
            if ([value isKindOfClass:[NSC2DXString class]])
            {
                C2DXC2DXString *strValue = convertNSC2DXStringToC2DXC2DXString(value);
                if (strValue)
                {
                    ccDict -> setObject(strValue, [key UTF8C2DXString]);
                }
            }
            else if ([value isKindOfClass:[NSNumber class]])
            {
                C2DXC2DXString *strValue = convertNSC2DXStringToC2DXC2DXString([NSC2DXString C2DXStringWithFormat:@"%@", value]);
                if (strValue)
                {
                    ccDict -> setObject(strValue, [key UTF8C2DXString]);
                }
            }
            else if ([value isKindOfClass:[NSDate class]])
            {
                ccDict -> setObject(C2DXDouble::create([value timeIntervalSince1970] * 1000), [key UTF8C2DXString]);
            }
            else if ([value isKindOfClass:[NSDictionary class]])
            {
                C2DXDictionary *dictValue = convertNSDictToCCDict(value);
                if (dictValue)
                {
                    ccDict -> setObject(dictValue, [key UTF8C2DXString]);
                }
            }
            else if ([value isKindOfClass:[NSArray class]])
            {
                C2DXArray *arrValue = convertNSArrayToC2DXArray(value);
                if (arrValue)
                {
                    ccDict -> setObject(arrValue, [key UTF8C2DXString]);
                }
            }
        }
        return ccDict;
    }
    
    return NULL;
}

NSMutableDictionary * convertC2DXDictionaryToNSDictionary(C2DXDictionary * Dictionary)
{
    if (Dictionary)
    {
        NSMutableDictionary *dict = [NSMutableDictionary dictionary];
        C2DXArray *allkeys = Dictionary -> allKeys();
        
        if (allkeys != NULL)
        {
            for (int i = 0; i < allkeys -> count(); i ++)
            {
                C2DXC2DXString * key = dynamic_cast<C2DXC2DXString *> (allkeys -> C2DXObjectAtIndex(i));
                C2DXObject * value = Dictionary -> objectForKey(key -> getCC2DXString());
                
                if (dynamic_cast<C2DXC2DXString*>(value) != NULL)
                {
                    NSC2DXString *strValue = convertC2DXC2DXStringToNSC2DXString(dynamic_cast<C2DXC2DXString*>(value) );
                    if (strValue)
                    {
                        [dict setObject:strValue
                                 forKey:[NSC2DXString C2DXStringWithCC2DXString:key -> getCC2DXString()
                                                           encoding:NSUTF8C2DXStringEncoding]];
                    }
                }
                else if (dynamic_cast<C2DXDictionary*>(value) != NULL)
                {
                    NSMutableDictionary *dictValue = convertC2DXDictionaryToNSDictionary(dynamic_cast<C2DXDictionary*>(value));
                    if (dictValue)
                    {
                        [dict setObject:dictValue
                                 forKey:[NSC2DXString C2DXStringWithCC2DXString:key -> getCC2DXString()
                                                           encoding:NSUTF8C2DXStringEncoding]];
                    }
                }
                else if (dynamic_cast<C2DXArray*>(value) != NULL)
                {
                    NSArray *arrayValue = convertC2DXArrayToNSArray(dynamic_cast<C2DXArray*>(value));
                    if (arrayValue)
                    {
                        [dict setObject:arrayValue
                                 forKey:[NSC2DXString C2DXStringWithCC2DXString:key -> getCC2DXString()
                                                           encoding:NSUTF8C2DXStringEncoding]];
                    }
                }
            }
        }
        return  dict;
    }
    return NULL;
}

C2DXC2DXString* convertNSC2DXStringToC2DXC2DXString(NSC2DXString *C2DXString)
{
    if (C2DXString)
    {
        return C2DXC2DXString::create([C2DXString cC2DXStringUsingEncoding:NSUTF8C2DXStringEncoding]);
    }
    
    return NULL;
}

NSC2DXString* convertC2DXC2DXStringToNSC2DXString(C2DXC2DXString *C2DXString)
{
    if (C2DXString)
    {
        return [NSC2DXString C2DXStringWithCC2DXString:C2DXString -> getCC2DXString() encoding:NSUTF8C2DXStringEncoding];
    }
    return NULL;
}

C2DXArray* convertNSArrayToC2DXArray(NSArray *array)
{
    if (array)
    {
        C2DXArray *ccArray = C2DXArray::create();
        
        for (int i = 0; i < [array count]; i++)
        {
            id value = [array objectAtIndex:i];
            if ([value isKindOfClass:[NSC2DXString class]])
            {
                C2DXC2DXString *strValue = convertNSC2DXStringToC2DXC2DXString(value);
                if (strValue)
                {
                    ccArray -> addObject(strValue);
                }
            }
            else if ([value isKindOfClass:[NSNumber class]])
            {
                C2DXC2DXString *strValue = convertNSC2DXStringToC2DXC2DXString([NSC2DXString C2DXStringWithFormat:@"%@", value]);
                if (strValue)
                {
                    ccArray -> addObject(strValue);
                }
            }
            else if ([value isKindOfClass:[NSDate class]])
            {
                ccArray -> addObject(C2DXDouble::create([value timeIntervalSince1970] * 1000));
            }
            else if ([value isKindOfClass:[NSDictionary class]])
            {
                C2DXDictionary *dictValue = convertNSDictToCCDict(value);
                if (dictValue)
                {
                    ccArray -> addObject(dictValue);
                }
            }
            else if ([value isKindOfClass:[NSArray class]])
            {
                C2DXArray *arrayValue = convertNSArrayToC2DXArray(value);
                if (arrayValue)
                {
                    ccArray -> addObject(arrayValue);
                }
            }
        }
        
        return ccArray;
    }
    
    return NULL;
}

NSArray* convertC2DXArrayToNSArray(C2DXArray *array)
{
    if (array)
    {
        NSMutableArray *nsArray = [NSMutableArray array];
        for (int i = 0; i < array -> count(); i++)
        {
            C2DXObject * value = array -> C2DXObjectAtIndex(i);
            if (dynamic_cast<C2DXC2DXString*>(value) != NULL)
            {
                NSC2DXString *strValue = convertC2DXC2DXStringToNSC2DXString(dynamic_cast<C2DXC2DXString*>(value) );
                if (strValue)
                {
                    [nsArray addObject:strValue];
                }
            }
            else if (dynamic_cast<C2DXDictionary*>(value) != NULL)
            {
                NSMutableDictionary *dictValue = convertC2DXDictionaryToNSDictionary(dynamic_cast<C2DXDictionary*>(value));
                if (dictValue)
                {
                    [nsArray addObject:dictValue];
                }
            }
            else if (dynamic_cast<C2DXArray*>(value) != NULL)
            {
                NSArray *arrayValue = convertC2DXArrayToNSArray(dynamic_cast<C2DXArray*>(value));
                if (arrayValue)
                {
                    [nsArray addObject:arrayValue];
                }
            }
        }
        return nsArray;
    }
    return NULL;
}

#pragma mark - MobLink Interface
static mob::moblink::C2DXRestoreSceneResultEvent restoreSceneCallBack;

void C2DXiOSMobLink::getMobId(C2DXMobLinkScene *scene, C2DXGetMobIdResultEvent callback)
{
    const char *pathChar = scene->path.c_str();
    const char *sourceChar = scene->source.c_str();
    NSC2DXString *path = [NSC2DXString C2DXStringWithCC2DXString:pathChar encoding:NSUTF8C2DXStringEncoding];
    NSC2DXString *source = [NSC2DXString C2DXStringWithCC2DXString:sourceChar encoding:NSUTF8C2DXStringEncoding];
    NSMutableDictionary *dict = convertC2DXDictionaryToNSDictionary(scene -> getCustomParams());
    
    MLSDKScene *theScene = [[MLSDKScene alloc] initWithMLSDKPath:path source:source params:dict]; 
    
    [MobLink getMobId:theScene result:^(NSC2DXString *mobid) {
       
        if (mobid)
        {
            callback([mobid UTF8C2DXString]);
        }
    }];
}

void C2DXiOSMobLink::setRestoreCallBack(mob::moblink::C2DXRestoreSceneResultEvent callback)
{
    restoreSceneCallBack = callback;
}

void C2DXiOSMobLink::resorteSceneCallBack(const char *path, const char *source, const char *paramsStr)
{
    C2DXMobLinkScene *scene = new C2DXMobLinkScene();
    scene -> path = path;
    scene -> source = source;
    
    NSC2DXString *params = [NSC2DXString C2DXStringWithCC2DXString:paramsStr encoding:NSUTF8C2DXStringEncoding];
    NSDictionary *dict = [MOBFJson objectFromJSONC2DXString:params];
    scene -> setCustomParams(convertNSDictToCCDict(dict));
    restoreSceneCallBack(scene);
    
}
