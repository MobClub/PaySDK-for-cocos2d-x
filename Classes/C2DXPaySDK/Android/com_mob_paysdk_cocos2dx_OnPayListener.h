/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_mob_paysdk_cocos2dx_OnPayListener */

#ifndef _Included_com_mob_paysdk_cocos2dx_OnPayListener
#define _Included_com_mob_paysdk_cocos2dx_OnPayListener
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_mob_paysdk_cocos2dx_OnPayListener
 * Method:    nativeOnCreateCxxObject
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_mob_paysdk_cocos2dx_OnPayListener_nativeOnCreateCxxObject
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_mob_paysdk_cocos2dx_OnPayListener
 * Method:    nativeOnWillPay
 * Signature: (ILjava/lang/C2DXString;Ljava/lang/Object;Lcom/mob/paysdk/MobPayAPI;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_mob_paysdk_cocos2dx_OnPayListener_nativeOnWillPay
  (JNIEnv *, jobject, jint, jstring, jobject, jobject);

/*
 * Class:     com_mob_paysdk_cocos2dx_OnPayListener
 * Method:    nativeOnPayEnd
 * Signature: (ILcom/mob/paysdk/PayResult;Ljava/lang/Object;Lcom/mob/paysdk/MobPayAPI;)V
 */
JNIEXPORT void JNICALL Java_com_mob_paysdk_cocos2dx_OnPayListener_nativeOnPayEnd
  (JNIEnv *, jobject, jint, jobject, jobject, jobject);

/*
 * Class:     com_mob_paysdk_cocos2dx_OnPayListener
 * Method:    nativeOnDestoryCxxObject
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_mob_paysdk_cocos2dx_OnPayListener_nativeOnDestoryCxxObject
  (JNIEnv *, jobject, jint);

#ifdef __cplusplus
}
#endif
#endif
