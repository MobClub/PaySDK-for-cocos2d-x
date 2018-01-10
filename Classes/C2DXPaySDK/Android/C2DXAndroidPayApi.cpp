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

template <class O>
void C2DXAndroidAliApi::pay(O* order, C2DXOnPayListener<O, C2DXAliPayApi>* callback)
{
    JvmJniEnv env;
    jobject jApi = getLocalJavaObject(env);
    jclass jApiClazz = getJavaClass(env, jApi);
    jmethodID jApiPayMethod = getJavaMethodID(env, jApiClazz, "pay",
        "(Ljava/lang/Object;Lcom/mob/paysdk/;OnPayListener)V;");


    C2DXAndroidPayOrder* dOrder = (C2DXAndroidPayOrder*) order;
    jobject jorder = dOrder->getLocalJavaObject(env);

    C2DXAndroidOnPayListener* cxx = C2DXAndroidOnPayListener::create();
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
}

template <class O>
void C2DXAndroidWxApi::pay(O* order, C2DXOnPayListener<O, C2DXWxPayApi>* callback)
{

}

C2DXAndroidWxApi::~C2DXAndroidWxApi()
{
}



