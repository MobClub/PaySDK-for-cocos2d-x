#include "com_mob_paysdk_cocos2dx_OnPayListener.h"
#include "C2DXAndroidOnPayListener.h"

/*
 * Class:     com_mob_paysdk_cocos2dx_OnPayListener
 * Method:    nativeOnWillPay
 * Signature: (ILjava/lang/C2DXString;Ljava/lang/Object;Lcom/mob/paysdk/MobPayAPI;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_mob_paysdk_cocos2dx_OnPayListener_nativeOnWillPay
  (JNIEnv *env, jobject, jint jcxx, jstring jTicketId, jobject jOrder, jobject jApi)
{
    C2DXCxxJavaObject* cxx = (C2DXCxxJavaObject*) jcxx;
    return mob::paysdk::androidOnWillPay(env, cxx, jTicketId, jOrder, jApi);
}

/*
 * Class:     com_mob_paysdk_cocos2dx_OnPayListener
 * Method:    nativeOnPayEnd
 * Signature: (ILjava/lang/Object;Lcom/mob/paysdk/MobPayAPI;)V
 */
JNIEXPORT void JNICALL Java_com_mob_paysdk_cocos2dx_OnPayListener_nativeOnPayEnd
  (JNIEnv *env, jobject, jint jcxx, jint jResult, jobject jOrder, jobject jApi)
{
    C2DXCxxJavaObject* cxx = (C2DXCxxJavaObject*) jcxx;
    mob::paysdk::androidOnPayEnd(env, cxx, jResult, jOrder, jApi);
}
