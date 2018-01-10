#include "C2DXCxxJavaObject.h"

using namespace mob::paysdk;

jobject C2DXCxxJavaObject::newJavaInstance(JNIEnv* env, const char* clazz)
{
    jclass jclazz = env->FindClass(clazz);
    return env->AllocObject(jclazz);
}

jclass C2DXCxxJavaObject::getJavaClass(JNIEnv* env, jobject jo)
{
    return env->GetObjectClass(jo);
}

jmethodID C2DXCxxJavaObject::getJavaMethodID(JNIEnv* env, jclass clazz, const char* name, const char* sig)
{
    return env->GetMethodID(clazz, name, sig);
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
}






