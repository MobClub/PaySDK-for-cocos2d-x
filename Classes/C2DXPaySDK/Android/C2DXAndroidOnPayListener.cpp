#include "C2DXAndroidOnPayListener.h"
#include "JvmJniEnv.h"

#define ANDROIDONWILLPAY(O, API, listener, env, jTicketId, jOrder, jApi) \
    if (NULL != dynamic_cast<C2DXAndroidOnPayListener<O, API>*>(listener)) { \
        C2DXAndroidOnPayListener<O, API>* p = (C2DXAndroidOnPayListener<O, API>*) listener; \
        return p->onWillPay(env, jTicketId, jOrder, jApi); \
    }

#define ANDROIDONPAYEND(O, API, listener, env, jTicketId, jOrder, jApi) \
    if (NULL != dynamic_cast<C2DXAndroidOnPayListener<O, API>*>(listener)) { \
        C2DXAndroidOnPayListener<O, API>* p = (C2DXAndroidOnPayListener<O, API>*) listener; \
        p->onPayEnd(env, jTicketId, jOrder, jApi); \
		O* order = p->getOrder(); \
		API* api = p->getPayApi(); \
		delete p; \
		delete order; \
		delete api; \
    }

bool mob::paysdk::androidOnWillPay(JNIEnv *env, void* cxx, jstring jTicketId, jobject jOrder, jobject jApi)
{
	C2DXCxxJavaObject* listener = (C2DXCxxJavaObject*)cxx;
    ANDROIDONWILLPAY(C2DXAndroidPayOrder, C2DXAndroidAliApi, listener, env, jTicketId, jOrder, jApi);
    ANDROIDONWILLPAY(C2DXAndroidPayOrder, C2DXAndroidWxApi, listener, env, jTicketId, jOrder, jApi);
    ANDROIDONWILLPAY(C2DXAndroidTicketOrder, C2DXAndroidAliApi, listener,  env, jTicketId, jOrder, jApi);
    ANDROIDONWILLPAY(C2DXAndroidTicketOrder, C2DXAndroidWxApi, listener, env, jTicketId, jOrder, jApi);
}

bool mob::paysdk::androidOnPayEnd(JNIEnv *env, void* cxx, jint jResult, jobject jOrder, jobject jApi)
{
	C2DXCxxJavaObject* listener = (C2DXCxxJavaObject*)cxx;
    ANDROIDONPAYEND(C2DXAndroidPayOrder, C2DXAndroidAliApi, listener, env, jResult, jOrder, jApi);
    ANDROIDONPAYEND(C2DXAndroidPayOrder, C2DXAndroidWxApi, listener, env, jResult, jOrder, jApi);
    ANDROIDONPAYEND(C2DXAndroidTicketOrder, C2DXAndroidAliApi, listener, env, jResult, jOrder, jApi);
    ANDROIDONPAYEND(C2DXAndroidTicketOrder, C2DXAndroidWxApi, listener, env, jResult, jOrder, jApi);
}





