
#include "C2DXAndroidOrder.h"

//#include "JSON/CCJSONConverter.h"

//USING_NS_CC;

#include "JvmJniEnv.h"
using namespace mob::paysdk;

//void C2DXAndroidMobLink::getMobId(mob::moblink::C2DXMobLinkScene *scene, C2DXGetMobIdResultEvent callback)
//{
//    JNIEnv* env = JniHelper::getEnv();
//    jstring jPath = env->NewStringUTF(scene->path.c_str());
//    jstring jSource = env->NewStringUTF(scene->source.c_str());
//
//    jobject jParam;
//    {
//        // 大括号, 隐藏不必要的变量
//        C2DXDictionary* dict = scene->getCustomParams();
//        CCJSONConverter* json = CCJSONConverter::sharedConverter();
//        const char* ccContent = json->strFrom(dict);
//        jParam = jsonString2HashMap(env, ccContent);
//    }
//
//    JniMethodInfo mi;
//    JniHelper::getStaticMethodInfo(mi, "com/mob/moblink/MobLink"
//            , "getMobID", "(Ljava/util/HashMap;Ljava/lang/String;Ljava/lang/String;Lcom/mob/moblink/ActionListener;)V");
//
//    jobject jListener = newActionListener(env);
//    C2DXAndroidActionListener* cxxListener = (C2DXAndroidActionListener*)getCxxObject(env, jListener);
//    cxxListener->setGetModIdCallBack(callback);
//
//    env->CallStaticVoidMethod(mi.classID, mi.methodID, jParam, jPath, jSource, jListener);
//}
//
//void C2DXAndroidMobLink::setRestoreCallBack(C2DXRestoreSceneResultEvent callback)
//{
//    JNIEnv* env = JniHelper::getEnv();
//    JniMethodInfo mi;
//    JniHelper::getStaticMethodInfo(mi, "com/mob/moblink/cocos2dx/RestoreSceneListener", "newInstance", "()Lcom/mob/moblink/cocos2dx/RestoreSceneListener;");
//    jobject javaListener = env->CallStaticObjectMethod(mi.classID, mi.methodID);
//
//    C2DXAndroidRestoreSceneListener* cxxListener = (C2DXAndroidRestoreSceneListener*) getCxxObject(env, javaListener);
//    cxxListener->setRestoreSceneCallBack(callback);
//
//    JniHelper::getStaticMethodInfo(mi, "com/mob/moblink/MobLink", "setRestoreSceneListener", "(Lcom/mob/moblink/RestoreSceneListener;)V");
//    env->CallStaticVoidMethod(mi.classID, mi.methodID, javaListener);
//
//    // 防止setRestoreCallBack调用过晚, 导致错过scene
//    updateIntent();
//}
//
//jobject C2DXAndroidMobLink::getAndroidContext(JNIEnv* env)
//{
//    JniMethodInfo methodInfo;
//    JniHelper::getStaticMethodInfo(methodInfo, "org/cocos2dx/lib/Cocos2dxActivity", "getContext", "()Landroid/content/Context;");
//    return env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
//}
//
//jobject C2DXAndroidMobLink::jsonString2HashMap(JNIEnv* env, const char* json)
//{
//    JniMethodInfo mi;
//    JniHelper::getMethodInfo(mi, "com/mob/tools/utils/Hashon", "<init>", "()V");
//    jobject jthiz = env->NewObject(mi.classID, mi.methodID);
//
//    jmethodID jmethod = env->GetMethodID(mi.classID, "fromJson", "(Ljava/lang/String;)Ljava/util/HashMap;");
//    jstring jJson = env->NewStringUTF(json);
//    jobject result = env->CallObjectMethod(jthiz, jmethod, jJson);
//    return result;
//}
//
//jobject C2DXAndroidMobLink::newActionListener(JNIEnv* env)
//{
//    JniMethodInfo mi;
//    JniHelper::getStaticMethodInfo(mi, "com/mob/moblink/cocos2dx/ActionListener", "newInstance", "()Lcom/mob/moblink/cocos2dx/ActionListener;");
//    return env->CallStaticObjectMethod(mi.classID, mi.methodID);
//}
//
//void C2DXAndroidMobLink::updateIntent()
//{
//    JNIEnv* env = JniHelper::getEnv();
//
//    JniHelper::
//
//    JNIEnv* jniEnv = JniHelper::getEnv();
//    jniEnv->DefineClass()
//
//    jobject jactivity = getAndroidContext(env);
//    jmethodID jmethod = env->GetMethodID(env->GetObjectClass(jactivity), "getIntent", "()Landroid/content/Intent;");
//    jobject jIntent = env->CallObjectMethod(jactivity, jmethod);
//
//    JniMethodInfo mi;
//    JniHelper::getStaticMethodInfo(mi, "com/mob/moblink/MobLink", "updateIntent", "(Landroid/app/Activity;Landroid/content/Intent;)V");
//    env->CallStaticVoidMethod(mi.classID, mi.methodID, jactivity, jIntent);
//}
//
//jint mob::moblink::getCxxObject(JNIEnv *env, jobject jthiz) {
//    jclass jthizclass = env->GetObjectClass(jthiz);
//    jmethodID method = env->GetMethodID(jthizclass, "getCxxObject", "()I");
//    jint result = env->CallIntMethod(jthiz, method);
//    return result;
//}


C2DXAndroidPayOrder* C2DXAndroidPayOrder::create()
{
    C2DXAndroidPayOrder* p = new C2DXAndroidPayOrder();
    return p;
}


C2DXAndroidPayOrder::C2DXAndroidPayOrder()
{
    JvmJniEnv env;
    jobject javaObject = newJavaInstance(env, "com.mob.paysdk.PayOrder");
    attachJavaObject(env, javaObject);
}

String C2DXAndroidPayOrder::getOrderNo()
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return "";
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "getOrderNo", "()Ljava/lang/String;");
    jstring jvalue = (jstring)env->CallObjectMethod(jthiz, jmethod);
    String ret = env->GetStringUTFChars(jvalue, NULL);
    return ret;
}

void C2DXAndroidPayOrder::setOrderNo(String orderNo)
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return;
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "setOrderNo", "(Ljava/lang/String;)V");
    jstring jvalue = env->NewStringUTF(orderNo.c_str());
    env->CallVoidMethod(jthiz, jmethod, jvalue);
}

int C2DXAndroidPayOrder::getAmount()
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return 0;
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "getAmount", "()I");
    int ret = env->CallIntMethod(jthiz, jmethod);
    return ret;
}

void C2DXAndroidPayOrder::setAmount(int amount)
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return;
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "setAmount", "(I)V");
    env->CallVoidMethod(jthiz, jmethod, amount);
}

String C2DXAndroidPayOrder::getSubject()
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return "";
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "getSubject", "()Ljava/lang/String;");
    jstring jvalue = (jstring)env->CallObjectMethod(jthiz, jmethod);
    String ret = env->GetStringUTFChars(jvalue, NULL);
    return ret;
}

void C2DXAndroidPayOrder::setSubject(String subject)
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return;
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "setSubject", "(Ljava/lang/String;)V");
    jstring jvalue = env->NewStringUTF(subject.c_str());
    env->CallVoidMethod(jthiz, jmethod, jvalue);
}

String C2DXAndroidPayOrder::getBody()
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return "";
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "getBody", "()Ljava/lang/String;");
    jstring jvalue = (jstring)env->CallObjectMethod(jthiz, jmethod);
    String ret = env->GetStringUTFChars(jvalue, NULL);
    return ret;
}

void C2DXAndroidPayOrder::setBody(String body)
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return;
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "setBody", "(Ljava/lang/String;)V");
    jstring jvalue = env->NewStringUTF(body.c_str());
    env->CallVoidMethod(jthiz, jmethod, jvalue);
}

String C2DXAndroidPayOrder::getDescription()
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return "";
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "getDescription", "()Ljava/lang/String;");
    jstring jvalue = (jstring)env->CallObjectMethod(jthiz, jmethod);
    String ret = env->GetStringUTFChars(jvalue, NULL);
    return ret;
}

void C2DXAndroidPayOrder::setDescription(String description)
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return;
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "setDescription", "(Ljava/lang/String;)V");
    jstring jvalue = env->NewStringUTF(description.c_str());
    env->CallVoidMethod(jthiz, jmethod, jvalue);
}

String C2DXAndroidPayOrder::getMetadata()
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return "";
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "getMetadata", "()Ljava/lang/String;");
    jstring jvalue = (jstring)env->CallObjectMethod(jthiz, jmethod);
    String ret = env->GetStringUTFChars(jvalue, NULL);
    return ret;
}

void C2DXAndroidPayOrder::setMetadata(String metadata)
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return;
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "setMetadata", "(Ljava/lang/String;)V");
    jstring jvalue = env->NewStringUTF(metadata.c_str());
    env->CallVoidMethod(jthiz, jmethod, jvalue);
}

String C2DXAndroidPayOrder::getTicketId()
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return "";
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "getTicketId", "()Ljava/lang/String;");
    jstring jvalue = (jstring)env->CallObjectMethod(jthiz, jmethod);
    String ret = env->GetStringUTFChars(jvalue, NULL);
    return ret;
}


C2DXAndroidPayOrder::~C2DXAndroidPayOrder()
{
    JvmJniEnv env;
    detachJavaObject(env, NULL);
}


C2DXAndroidTicketOrder* C2DXAndroidTicketOrder::create()
{
    C2DXAndroidTicketOrder* p = new C2DXAndroidTicketOrder();
    return p;
}


C2DXAndroidTicketOrder::C2DXAndroidTicketOrder()
{
    JvmJniEnv env;
    jobject javaObject = newJavaInstance(env, "com.mob.paysdk.TicketOrder");
    attachJavaObject(env, javaObject);
}


void C2DXAndroidTicketOrder::setTicketId(String tId)
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return;
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "setTicketId", "(Ljava/lang/String;)V");
    jstring jvalue = env->NewStringUTF(tId.c_str());
    env->CallVoidMethod(jthiz, jmethod, jvalue);
}

String C2DXAndroidTicketOrder::getTicketId()
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return "";
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "getTicketId", "()Ljava/lang/String;");
    jstring jvalue = (jstring)env->CallObjectMethod(jthiz, jmethod);
    String ret = env->GetStringUTFChars(jvalue, NULL);
    return ret;
}



C2DXAndroidTicketOrder::~C2DXAndroidTicketOrder()
{
    JvmJniEnv env;
    detachJavaObject(env, NULL);
}