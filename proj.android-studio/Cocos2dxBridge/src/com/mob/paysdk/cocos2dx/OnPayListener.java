package com.mob.paysdk.cocos2dx;

import com.mob.paysdk.MobPayAPI;
import com.mob.paysdk.Order;
import com.mob.paysdk.PayResult;

/**
 * OnPayListener for cocos2dx.<br/>
 */
public class OnPayListener extends JavaCxxObject implements com.mob.paysdk.OnPayListener {

	public OnPayListener() {
		super();
	}

//	@Override
//	public boolean onWillPay(String s, Order t, MobPayAPI mobPayAPI) {
//		int cxxThis = getCxxObject();
//		return nativeOnWillPay(cxxThis, s, t, mobPayAPI);
//	}

	@Override
	public void onPayEnd(PayResult payResult, Order t, MobPayAPI mobPayAPI) {
		int cxxThis = getCxxObject();
		nativeOnPayEnd(cxxThis, payResult.ordinal(), t, mobPayAPI);
	}

	private native boolean nativeOnWillPay(int cxxThis, String s, Order t, MobPayAPI mobPayAPI);
	private native void nativeOnPayEnd(int cxxThis, int payResult, Order t, MobPayAPI mobPayAPI);
}
