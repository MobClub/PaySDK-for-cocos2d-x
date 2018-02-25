#include "C2DXAndroidPayApi.h"
#include "C2DXAndroidOrder.h"
#include "JvmJniEnv.h"
#include "C2DXAndroidOnPayListener.h"


C2DXAndroidAliApi* C2DXAndroidAliApi::create()
{

    return new C2DXAndroidAliApi();
}

C2DXAndroidAliApi::C2DXAndroidAliApi()
{
    JvmJniEnv env;
    jobject javaObject = newJavaInstance(env, "com/mob/paysdk/AliPayAPI");
    attachJavaObject(env, javaObject);
}

void C2DXAndroidAliApi::pay(C2DXAndroidPayOrder* order, C2DXOnPayListener* callback)
{

    JvmJniEnv env;
    jobject jApi = getLocalJavaObject(env);
    jclass jApiClazz = getJavaClass(env, jApi);
    jmethodID jApiPayMethod = getJavaMethodID(env, jApiClazz, "pay",
        "(Lcom/mob/paysdk/Order;Lcom/mob/paysdk/OnPayListener;)V");


    C2DXAndroidPayOrder* dOrder = order;
    jobject jorder = dOrder->getLocalJavaObject(env);

    C2DXAndroidOnPayListener<C2DXAndroidPayOrder, C2DXAndroidAliApi>* cxx = C2DXAndroidOnPayListener<C2DXAndroidPayOrder, C2DXAndroidAliApi>::create();
    cxx->setOnPayListener(callback);
    jobject jListener = cxx->getLocalJavaObject(env);

    env->CallVoidMethod(jApi, jApiPayMethod, jorder, jListener);
}


void C2DXAndroidAliApi::pay(C2DXAndroidTicketOrder* order, C2DXOnPayListener* callback)
{
    JvmJniEnv env;
    jobject jApi = getLocalJavaObject(env);
    jclass jApiClazz = getJavaClass(env, jApi);
    jmethodID jApiPayMethod = getJavaMethodID(env, jApiClazz, "pay",
        "(Lcom/mob/paysdk/Order;Lcom/mob/paysdk/OnPayListener;)V");


    C2DXAndroidPayOrder* dOrder = (C2DXAndroidPayOrder*) order;
    jobject jorder = dOrder->getLocalJavaObject(env);

    C2DXAndroidOnPayListener<C2DXAndroidTicketOrder, C2DXAndroidAliApi>* cxx = C2DXAndroidOnPayListener<C2DXAndroidTicketOrder, C2DXAndroidAliApi>::create();
    cxx->setOnPayListener(callback);
    jobject jListener = cxx->getLocalJavaObject(env);

    env->CallVoidMethod(jApi, jApiPayMethod, jorder, jListener);
}

C2DXAndroidAliApi::~C2DXAndroidAliApi()
{

}


C2DXAndroidWxApi* C2DXAndroidWxApi::create()
{
    return new C2DXAndroidWxApi();
}


C2DXAndroidWxApi::C2DXAndroidWxApi()
{
    JvmJniEnv env;
    jobject javaObject = newJavaInstance(env, "com/mob/paysdk/WXPayAPI");
    attachJavaObject(env, javaObject);
}

void C2DXAndroidWxApi::pay(C2DXAndroidPayOrder* order, C2DXOnPayListener* callback)
{
    JvmJniEnv env;
    jobject jApi = getLocalJavaObject(env);
    jclass jApiClazz = getJavaClass(env, jApi);
    jmethodID jApiPayMethod = getJavaMethodID(env, jApiClazz, "pay",
                                              "(Lcom/mob/paysdk/Order;Lcom/mob/paysdk/OnPayListener;)V");


    C2DXAndroidPayOrder* dOrder = (C2DXAndroidPayOrder*) order;
    jobject jorder = dOrder->getLocalJavaObject(env);

    C2DXAndroidOnPayListener<C2DXPayOrder, C2DXAndroidWxApi>* cxx = C2DXAndroidOnPayListener<C2DXPayOrder, C2DXAndroidWxApi>::create();
    cxx->setOnPayListener(callback);
    jobject jListener = cxx->getLocalJavaObject(env);

    env->CallVoidMethod(jApi, jApiPayMethod, jorder, jListener);
}


void C2DXAndroidWxApi::pay(C2DXAndroidTicketOrder* order, C2DXOnPayListener* callback)
{
    JvmJniEnv env;
    jobject jApi = getLocalJavaObject(env);
    jclass jApiClazz = getJavaClass(env, jApi);
    jmethodID jApiPayMethod = getJavaMethodID(env, jApiClazz, "pay",
        "(Lcom/mob/paysdk/Order;Lcom/mob/paysdk/OnPayListener;)V");


    C2DXAndroidPayOrder* dOrder = (C2DXAndroidPayOrder*) order;
    jobject jorder = dOrder->getLocalJavaObject(env);

    C2DXAndroidOnPayListener<C2DXAndroidTicketOrder, C2DXAndroidWxApi>* cxx = C2DXAndroidOnPayListener<C2DXAndroidTicketOrder, C2DXAndroidWxApi>::create();
    cxx->setOnPayListener(callback);
    jobject jListener = cxx->getLocalJavaObject(env);

    env->CallVoidMethod(jApi, jApiPayMethod, jorder, jListener);
}

C2DXAndroidWxApi::~C2DXAndroidWxApi()
{
}



