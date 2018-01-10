#include "C2DXAndroidPayApi.h"
#include "C2DXAndroidOrder.h"
#include "JvmJniEnv.h"
#include "C2DXAndroidOnPayListener.h"


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



