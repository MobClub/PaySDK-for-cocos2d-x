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
}

void C2DXAndroidAliApi::pay(C2DXPayOrder* order, C2DXOnPayListener<C2DXPayOrder, C2DXAliPayApi>* callback)
{

    JvmJniEnv env;
    jobject jApi = getLocalJavaObject(env);
    jclass jApiClazz = getJavaClass(env, jApi);
    jmethodID jApiPayMethod = getJavaMethodID(env, jApiClazz, "pay",
        "(Ljava/lang/Object;Lcom/mob/paysdk/;OnPayListener)V;");


    C2DXAndroidPayOrder* dOrder = (C2DXAndroidPayOrder*) order;
    jobject jorder = dOrder->getLocalJavaObject(env);

    C2DXAndroidOnPayListener* cxx = C2DXAndroidOnPayListener::create();
    cxx->setOnPayListener<C2DXPayOrder, C2DXAliPayApi>(callback);
    jobject jListener = cxx->getLocalJavaObject(env);

    env->CallVoidMethod(jApi, jApiPayMethod, jorder, jListener);
}


void C2DXAndroidAliApi::pay(C2DXTicketOrder* order, C2DXOnPayListener<C2DXTicketOrder, C2DXAliPayApi>* callback)
{

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
}

void C2DXAndroidWxApi::pay(C2DXPayOrder* order, C2DXOnPayListener<C2DXPayOrder, C2DXWxPayApi>* callback)
{
}


void C2DXAndroidWxApi::pay(C2DXTicketOrder* order, C2DXOnPayListener<C2DXTicketOrder, C2DXWxPayApi>* callback)
{
}

C2DXAndroidWxApi::~C2DXAndroidWxApi()
{
}



