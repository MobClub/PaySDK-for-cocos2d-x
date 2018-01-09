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
            void attachJavaObject(jobject gRef);
            void detachJavaObject(jobject gRef);
            jobject getJavaObject();
            jobject getLocalJavaObject(JNIEnv* env);
        public:
            static jobject newJavaInstance(JNIEnv* env, const char* clazz);
            static jobject newGlobelRef(JNIEnv* env, jobject localRef);
            static jobject getLocalJavaObject(JNIEnv* env, jobject gRef);

        public:
            virtual ~C2DXCxxJavaObject();
        private:
            jobject globelJavaObject;
        };



    }
}

#endif
