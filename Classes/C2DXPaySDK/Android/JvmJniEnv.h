#ifndef __C2DXPAYSDKBRIDGE__JVMJNIENV__
#define __C2DXPAYSDKBRIDGE__JVMJNIENV__

//#include <stdio.h>
//#include "C2DXMobLinkTypeDef.h"
//
//
//#define CREATE_INSTANCE_FUNC(__TYPE__) \
//static __TYPE__* create() \
//{
//}

#include "jni.h"
//#include "jni/JniHelper.h"


namespace mob
{
    namespace paysdk
    {
        class JvmJniEnv {
        public:
            JvmJniEnv() {

            };

            operator JNIEnv*() {
                return (JNIEnv*)NULL;
            };

            JNIEnv* operator->() {

            }

            ~JvmJniEnv() {

            };
        };



    }
}

#endif
