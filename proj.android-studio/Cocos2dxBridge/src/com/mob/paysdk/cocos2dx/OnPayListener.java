package com.mob.paysdk.cocos2dx;

import com.mob.paysdk.MobPayAPI;
import com.mob.paysdk.PayResult;

/**
 * ActionListener for cocos2dx.<br/>
 * 使用demo, step by step:
 * <ul>
 *     <li>cxx代码, 创建本类的实例, 通过jni提示的方式</li>
 *     <li>通过getCxxObject获取cxx对象, 并对cxx对象进行配置</li>
 *     <li>传递此对象引用到MobLink中, 等待回调</li>
 *     <li>回调的方法通过native调用cxx对象对应的函数</li>
 *     <li>在cxx对象对应的函数中实现不同的需要</li>
 * </ul>
 *
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
	public boolean onWillPay(C2DXString s, T t, MobPayAPI mobPayAPI) {
		int cxxThis = getCxxObject();
		return nativeOnWillPay(cxxThis, s, t, mobPayAPI);
	}

	@Override
	public void onPayEnd(PayResult payResult, T t, MobPayAPI mobPayAPI) {
		int cxxThis = getCxxObject();
		nativeOnPayEnd(cxxThis, payResult, t, mobPayAPI);
	}

	private native int nativeOnCreateCxxObject(int p);
	private native boolean nativeOnWillPay(int cxxThis, C2DXString s, T t, MobPayAPI mobPayAPI);
	private native void nativeOnPayEnd(int cxxThis, PayResult payResult, T t, MobPayAPI mobPayAPI);
	private native int nativeOnDestoryCxxObject(int p);
}
