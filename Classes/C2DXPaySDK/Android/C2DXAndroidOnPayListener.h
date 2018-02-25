#ifndef __C2DXPAYSDKBRIDGE__C2DXANDROIDONPAYLISTENER__
#define __C2DXPAYSDKBRIDGE__C2DXANDROIDONPAYLISTENER__

#include "C2DXCxxJavaObject.h"
#include "C2DXPaySDK.h"
#include "JvmJniEnv.h"
#include "C2DXAndroidOrder.h"
#include "C2DXAndroidPayApi.h"
#include "C2DXAndroidTypeDef.h"

using namespace mob::paysdk;

namespace mob
{
    namespace paysdk
    {
        template <typename O, typename API>
        class C2DXAndroidOnPayListener : public C2DXCxxJavaObject {
        public:
            static C2DXAndroidOnPayListener<O, API>* create()
            {
                JvmJniEnv env;
                jobject object = newJavaInstance(env, "com/mob/paysdk/cocos2dx/OnPayListener");
                jclass jclazz = getJavaClass(env, object);
                C2DXAndroidOnPayListener<O, API>* cxxOjbect = new C2DXAndroidOnPayListener<O, API>();

                jmethodID jMethod = getJavaMethodID(env, jclazz, "jniAttachCxxObject", "(I)V");
                env->CallVoidMethod(object, jMethod, (jint)cxxOjbect);
                cxxOjbect->attachJavaObject(env, object);
                return cxxOjbect;
            }
        public:
            C2DXAndroidOnPayListener()
            {
                onPayListener = NULL;
            }
        public:
            void setOnPayListener(C2DXOnPayListener* callback)
            {
                onPayListener = callback;
            }
            bool onWillPay(JNIEnv *env, jstring jTicketId, jobject jOrder, jobject jApi)
            {
                bool handled = false;
                C2DXOnPayListener* callback = onPayListener;
                if (NULL != callback) {
                    const char* cxxTicketId = env->GetStringUTFChars(jTicketId, NULL);
                    C2DXString ticketId = cxxTicketId;
                    env->ReleaseStringUTFChars(jTicketId, cxxTicketId);
//                    O* order = dynamic_cast<O*>(findCxxJavaObject(env, jOrder));
//                    API* api = dynamic_cast<API*>(findCxxJavaObject(env, jApi));
//                    handled = callback->onWillPay(ticketId, order, api);
                    // TODO callback
                }
                return handled;
            }
            void onPayEnd(JNIEnv *env, jint jResult, jobject jOrder, jobject jApi)
            {
                C2DXOnPayListener* callback = onPayListener;
                if (NULL != callback) {
//                    C2DXPayResult* result = new C2DXPayResult();
//                    result->setPayStatus(jResult);
//                    O* order = dynamic_cast<O*>(findCxxJavaObject(env, jOrder));
//                    API* api = dynamic_cast<API*>(findCxxJavaObject(env, jApi));
                    // TODO callback
//                    callback->onPayEnd(result, order, api);
//                    delete order;
//                    delete api;
                }
                detachJavaObject(env, NULL);
            }
        private:
            C2DXOnPayListener* onPayListener;
        public:
            virtual ~C2DXAndroidOnPayListener()
            {
            }
        };

        bool androidOnWillPay(JNIEnv *env, C2DXCxxJavaObject* cxx, jstring jTicketId, jobject jOrder, jobject jApi);
        bool androidOnPayEnd(JNIEnv *env, C2DXCxxJavaObject* cxx, jint jResult, jobject jOrder, jobject jApi);
    }
}

#endif