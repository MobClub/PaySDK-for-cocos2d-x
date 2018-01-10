#include "C2DXAndroidOnPayListener.h"
#include "JvmJniEnv.h"


C2DXAndroidOnPayListener* C2DXAndroidOnPayListener::create()
{
    JvmJniEnv env;
    jobject object = newJavaInstance(env, "com.mob.paysdk.cocos2dx.OnPayListener");
    jclass jclazz = getJavaClass(env, object);
    jmethodID jMethod = getJavaMethodID(env, jclazz, "jniGetCxxObject", "()I");
    int pointer = env->CallIntMethod(object, jMethod);
    C2DXAndroidOnPayListener* cxxOjbect = (C2DXAndroidOnPayListener*)pointer;
    cxxOjbect->attachJavaObject(env, object);
    return cxxOjbect;
}

C2DXAndroidOnPayListener::C2DXAndroidOnPayListener()
{
    onPayListener = NULL;
}


template <typename O, typename API>
void C2DXAndroidOnPayListener::setOnPayListener(C2DXOnPayListener<O, API>* callback)
{
    onPayListener = callback;
}




