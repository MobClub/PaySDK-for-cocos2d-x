#include "C2DXAndroidOnPayListener.h"
#include "JvmJniEnv.h"

typedef C2DXAndroidOnPayListener<C2DXPayOrder, C2DXAliPayApi> PayOrderAli;
typedef C2DXAndroidOnPayListener<C2DXPayOrder, C2DXWxPayApi> PayOrderWx;
typedef C2DXAndroidOnPayListener<C2DXTicketOrder, C2DXAliPayApi> TicketOrderAli;
typedef C2DXAndroidOnPayListener<C2DXTicketOrder, C2DXWxPayApi> TicketOrderWx;
#define ANDROIDONWILLPAY(L, T, env, jTicketId, jOrder, jApi) \
    if (dynamic_cast<T*>(L)) { \
        T* p = (T*) L; \
        return p->onWillPay(env, jTicketId, jOrder, jApi); \
    }
#define ANDROIDONPAYEND(L, T, env, jTicketId, jOrder, jApi) \
    if (dynamic_cast<T*>(L)) { \
        T* p = (T*) L; \
        p->onPayEnd(env, jTicketId, jOrder, jApi); \
    }

bool mob::paysdk::androidOnWillPay(JNIEnv *env, C2DXCxxJavaObject* cxx, jstring jTicketId, jobject jOrder, jobject jApi) {
    ANDROIDONWILLPAY(cxx, PayOrderAli, env, jTicketId, jOrder, jApi);
    ANDROIDONWILLPAY(cxx, PayOrderWx, env, jTicketId, jOrder, jApi);
    ANDROIDONWILLPAY(cxx, TicketOrderAli, env, jTicketId, jOrder, jApi);
    ANDROIDONWILLPAY(cxx, TicketOrderWx, env, jTicketId, jOrder, jApi);
};

bool mob::paysdk::androidOnPayEnd(JNIEnv *env, C2DXCxxJavaObject* cxx, jint jResult, jobject jOrder, jobject jApi) {
    ANDROIDONPAYEND(cxx, PayOrderAli, env, jResult, jOrder, jApi);
    ANDROIDONPAYEND(cxx, PayOrderWx, env, jResult, jOrder, jApi);
    ANDROIDONPAYEND(cxx, TicketOrderAli, env, jResult, jOrder, jApi);
    ANDROIDONPAYEND(cxx, TicketOrderWx, env, jResult, jOrder, jApi);
};



