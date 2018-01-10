package com.mob.paysdk.cocos2dx;

import com.mob.paysdk.MobPayAPI;
import com.mob.paysdk.PayResult;

/**
 * OnPayListener for cocos2dx.<br/>
 */
public class OnPayListener<T> extends JavaCxxObject implements com.mob.paysdk.OnPayListener<T> {


	public OnPayListener() {
		super();
		int pointer = nativeOnCreateCxxObject(0);
		attachCxxObject(pointer);
	}

	@Override
	protected void finalize() throws Throwable {
		super.finalize();
		int pointer = getCxxObject();
		detachCxxObject(0);
		nativeOnDestoryCxxObject(pointer);
	}

	@Override
	public boolean onWillPay(String s, T t, MobPayAPI mobPayAPI) {
		int cxxThis = getCxxObject();
		return nativeOnWillPay(cxxThis, s, t, mobPayAPI);
	}

	@Override
	public void onPayEnd(PayResult payResult, T t, MobPayAPI mobPayAPI) {
		int cxxThis = getCxxObject();
		nativeOnPayEnd(cxxThis, payResult, t, mobPayAPI);
	}

	private native int nativeOnCreateCxxObject(int p);
	private native boolean nativeOnWillPay(int cxxThis, String s, T t, MobPayAPI mobPayAPI);
	private native void nativeOnPayEnd(int cxxThis, PayResult payResult, T t, MobPayAPI mobPayAPI);
	private native int nativeOnDestoryCxxObject(int p);
}
