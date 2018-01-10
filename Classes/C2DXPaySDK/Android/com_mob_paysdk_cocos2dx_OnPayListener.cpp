#include "com_mob_paysdk_cocos2dx_OnPayListener.h"
#include "C2DXAndroidOnPayListener.h"

/*
 * Class:     com_mob_paysdk_cocos2dx_OnPayListener
 * Method:    nativeOnCreateCxxObject
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_mob_paysdk_cocos2dx_OnPayListener_nativeOnCreateCxxObject
  (JNIEnv *env, jobject jthiz, jint)
{
    C2DXAndroidOnPayListener* cxx = C2DXAndroidOnPayListener::create();
    return (jint)cxx;
}

/*
 * Class:     com_mob_paysdk_cocos2dx_OnPayListener
 * Method:    nativeOnWillPay
 * Signature: (ILjava/lang/C2DXString;Ljava/lang/Object;Lcom/mob/paysdk/MobPayAPI;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_mob_paysdk_cocos2dx_OnPayListener_nativeOnWillPay
  (JNIEnv *, jobject, jint, jC2DXString, jobject, jobject)
{

}

/*
 * Class:     com_mob_paysdk_cocos2dx_OnPayListener
 * Method:    nativeOnPayEnd
 * Signature: (ILcom/mob/paysdk/PayResult;Ljava/lang/Object;Lcom/mob/paysdk/MobPayAPI;)V
 */
JNIEXPORT void JNICALL Java_com_mob_paysdk_cocos2dx_OnPayListener_nativeOnPayEnd
  (JNIEnv *, jobject, jint, jobject, jobject, jobject)
{

}

/*
 * Class:     com_mob_paysdk_cocos2dx_OnPayListener
 * Method:    nativeOnDestoryCxxObject
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_mob_paysdk_cocos2dx_OnPayListener_nativeOnDestoryCxxObject
  (JNIEnv *env, jobject, jint pointer)
{
    C2DXAndroidOnPayListener* cxx = new C2DXAndroidOnPayListener();
    delete cxx;
}
