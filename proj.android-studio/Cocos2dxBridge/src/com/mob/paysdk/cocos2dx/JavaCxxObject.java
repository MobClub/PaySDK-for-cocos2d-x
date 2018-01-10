package com.mob.paysdk.cocos2dx;

import com.mob.paysdk.AliPayAPI;
import com.mob.paysdk.PaySDK;

/**
 * Created by litl on 2018/1/3.
 */

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

    private int jniGetCxxObject() {
        return getCxxObject();
    }
}
