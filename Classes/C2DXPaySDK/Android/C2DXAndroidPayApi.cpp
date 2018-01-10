#include "C2DXAndroidPayApi.h"
#include "C2DXAndroidOrder.h"
#include "JvmJniEnv.h"
#include "C2DXAndroidOnPayListener.h"


void C2DXAndroidAliApi::pay(C2DXPayOrder* order, C2DXOnPayListener* callback)
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

void C2DXAndroidAliApi::pay(C2DXTicketOrder* order, C2DXOnPayListener* callback)
{

}




