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

using std::string;

namespace mob
{
    namespace paysdk
    {
        class C2DXCxxJavaObject {
        protected:
            C2DXCxxJavaObject();

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
        public:
            static jobject newJavaInstance(JNIEnv* env, const char* clazz);
        public:
            virtual ~C2DXCxxJavaObject();
        private:
            jobject globelJavaObject;
        };



    }
}

#endif
