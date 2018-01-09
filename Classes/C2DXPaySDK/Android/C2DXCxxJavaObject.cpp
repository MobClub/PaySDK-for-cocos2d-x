

#include "C2DXCxxJavaObject.h"

using namespace mob::paysdk;


jobject C2DXCxxJavaObject::newJavaInstance(JNIEnv* env, const char* clazz)
{
    jclass jclazz = env->FindClass(clazz);
    jobject jret = env->AllocObject(jclazz);
    return jret;
}

C2DXCxxJavaObject::C2DXCxxJavaObject()
{
    globelJavaObject = NULL;
}

void C2DXCxxJavaObject::attachJavaObject(JNIEnv* env, jobject lRef)
{
    jobject gRef = env->NewGlobalRef(lRef);
    globelJavaObject = gRef;
}

jobject C2DXCxxJavaObject::getLocalJavaObject(JNIEnv* env)
{
    jobject gRef = globelJavaObject;
    if (NULL != gRef) {
        env->DeleteGlobalRef(gRef);
        globelJavaObject = NULL;
    }
    jobject jret = env->NewLocalRef(gRef);
    return jret;

}

void C2DXCxxJavaObject::detachJavaObject(JNIEnv* env, jobject lRef)
{
    jobject gRef = globelJavaObject;
    if (NULL != gRef) {
        env->DeleteGlobalRef(gRef);
        globelJavaObject = NULL;
    }
}

jobject C2DXCxxJavaObject::getJavaObject()
{
    return globelJavaObject;
}

C2DXCxxJavaObject::~C2DXCxxJavaObject()
{
// TODO 实现此函数
//    detachJavaObject(NULL);
}





