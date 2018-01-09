

#include "C2DXCxxJavaObject.h"

using namespace mob::paysdk;


jobject C2DXCxxJavaObject::newJavaInstance(JNIEnv* env, const char* clazz)
{
    jclass jclazz = env->FindClass(clazz);
    jobject jret = env->AllocObject(jclazz);
    return jret;
}


jobject C2DXCxxJavaObject::newGlobelRef(JNIEnv* env, jobject localRef)
{
    jobject jret = env->NewGlobalRef(localRef);
    return jret;
}

jobject C2DXCxxJavaObject::getLocalJavaObject(JNIEnv* env, jobject gRef)
{


    jobject jret = env->NewLocalRef(gRef);
    return jret;

}

C2DXCxxJavaObject::C2DXCxxJavaObject()
{
    globelJavaObject = NULL;
}

void C2DXCxxJavaObject::attachJavaObject(jobject gRef)
{
    globelJavaObject = gRef;
}

void C2DXCxxJavaObject::detachJavaObject(jobject gRef)
{
    globelJavaObject = NULL;
}

jobject C2DXCxxJavaObject::getJavaObject()
{

    return globelJavaObject;
}



C2DXCxxJavaObject::~C2DXCxxJavaObject()
{
    detachJavaObject(NULL);
}






void (jobject gRef);


jobject getLocalJavaObject(JNIEnv* env);
jint getCxxObject(JNIEnv* env, jobject jthiz);






