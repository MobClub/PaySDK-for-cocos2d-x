package com.mob.paysdk.cocos2dx;

public abstract class JavaCxxObject extends Object {

    private int cxxObject;

    protected void attachCxxObject(int pointer) {
        cxxObject = pointer;
    }

    protected int getCxxObject() {
        return cxxObject;
    }

    protected void detachCxxObject(int pointer) {
        cxxObject = 0;
    }

    protected void jniAttachCxxObject(int pointer) {
        attachCxxObject(pointer);
    }

    protected int jniGetCxxObject() {
        return getCxxObject();
    }


    protected void jniDetachCxxObject(int pointer) {
        detachCxxObject(pointer);
    }

}
