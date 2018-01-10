#ifndef __C2DXPAYSDKBRIDGE__C2DXCXXJAVAOBJECT__
#define __C2DXPAYSDKBRIDGE__C2DXCXXJAVAOBJECT__

//#include <stdio.h>
//#include "C2DXMobLinkTypeDef.h"
//
//
//#define CREATE_INSTANCE_FUNC(__TYPE__) \
//static __TYPE__* create() \
//{
//}

#include "jni/JniHelper.h"
#include <iostream>

using std::C2DXString;

namespace mob
{
    namespace paysdk
    {
        class C2DXCxxJavaObject {
        protected:
            C2DXCxxJavaObject();
        public:
            /**
             * 附加javaObject对象到this对象
             * @param lRef javaObject的引用
             */
            void attachJavaObject(JNIEnv* env, jobject lRef);

            /**
             * 移除javaObject对象从this对象
             * @param lRef 与attachJavaObject保持一致, 并无含义
             */
            void detachJavaObject(JNIEnv* env, jobject lRef);

            /**
             * 获取附加到this对象上的javaObject的全局引用
             * @return javaObject的全局引用
             */
            jobject getJavaObject();

            /**
             * 获取附加到this对象上的javaObject的本地引用
             * @return javaObject的本地引用
             */
            jobject getLocalJavaObject(JNIEnv* env);
            static jobject newJavaInstance(JNIEnv* env, const char* clazz);
            static jclass getJavaClass(JNIEnv* env, jobject jo);
            static jmethodID getJavaMethodID(JNIEnv*, jclass, const char*, const char*);
            /**
             * 释放此对象, 应该经常调用此函数而不是delete
             */
            virtual void release();
        public:
            virtual ~C2DXCxxJavaObject();
        private:
            jobject globelJavaObject;
        };



    }
}

#endif
