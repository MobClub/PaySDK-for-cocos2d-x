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
                C2DXAndroidOnPayListener<O, API>* cxxOjbect = new C2DXAndroidOnPayListener<O, API>();
	            cxxOjbect->attachJavaObject(env, object);
                return cxxOjbect;
            }

        public:
	        /**
			 * 重写目的是实现强组合关系(双向引用), 父类只实现了单项引用java.<br/>
			 * 这里再实现java引用c++.
			 * @param env
			 * @param lRef
			 */
	        virtual void attachJavaObject(JNIEnv* env, jobject lRef)
	        {
		        C2DXCxxJavaObject::attachJavaObject(env, lRef);
		        lRef = getLocalJavaObject(env);
		        if (NULL != lRef) {
			        jclass jclazz = getJavaClass(env, lRef);
			        jint cxxObject = (jint)((C2DXCxxJavaObject*)this);
			        jmethodID jMethod = getJavaMethodID(env, jclazz, "jniAttachCxxObject", "(I)V");
			        env->CallVoidMethod(lRef, jMethod, (jint)cxxObject);
		        }
	        }

	        /**
			 * 拆除强组合关系
			 * @param env
			 * @param lRef
			 */
	        virtual void detachJavaObject(JNIEnv* env, jobject lRef)
	        {
		        lRef = getLocalJavaObject(env);
		        if (NULL != lRef) {
			        jclass jclazz = getJavaClass(env, lRef);
			        jint cxxObject = (jint)((C2DXCxxJavaObject*)this);
			        jmethodID jMethod = getJavaMethodID(env, jclazz, "jniDetachCxxObject", "(I)V");
			        env->CallVoidMethod(lRef, jMethod, (jint)cxxObject);
		        }
		        C2DXCxxJavaObject::detachJavaObject(env, lRef);
	        }

        private:
            C2DXAndroidOnPayListener()
            {
	            order = NULL;
                api = NULL;
	            onPayListener = NULL;
            }
        public:
            void setOnPayListener(C2DXOnPayListener* callback)
            {
                onPayListener = callback;
            }

            C2DXOnPayListener* getOnPayListener()
            {
                return onPayListener;
            }
	        void setOrder(O* o)
	        {
		        order = o;
	        }
	        O* getOrder()
	        {
		        return order;
	        }

	        void setPayApi(API* a)
	        {
		        api = a;
	        }
	        API* getPayApi()
	        {
		        return api;
	        }

        public:
            bool onWillPay(JNIEnv *env, jstring jTicketId, jobject jOrder, jobject jApi)
            {
	            bool handled = false;
	            C2DXOnPayListener* callback = onPayListener;
	            if (NULL != callback) {
		            const char* cxxTicketId = env->GetStringUTFChars(jTicketId, NULL);
		            C2DXString ticketId = cxxTicketId;
		            env->ReleaseStringUTFChars(jTicketId, cxxTicketId);
		            return callback->onWillPay(ticketId);
	            }
	            return handled;
            }
            void onPayEnd(JNIEnv *env, jint jResult, jobject jOrder, jobject jApi)
            {
	            C2DXOnPayListener* callback = onPayListener;
	            if (NULL != callback) {
		            callback->onPayEnd((C2DXPayStatus)jResult, "", 0, "");
	            }
            }
        private:
            C2DXOnPayListener* onPayListener;
            O* order;
            API* api;
        public:
            virtual ~C2DXAndroidOnPayListener()
            {
            }
        };

        bool androidOnWillPay(JNIEnv *env, void* cxx, jstring jTicketId, jobject jOrder, jobject jApi);
        bool androidOnPayEnd(JNIEnv *env, void* cxx, jint jResult, jobject jOrder, jobject jApi);
    }
}

#endif