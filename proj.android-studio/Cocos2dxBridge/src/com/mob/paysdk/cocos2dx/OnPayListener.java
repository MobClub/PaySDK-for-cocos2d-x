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

	private int cxxObject;

	public OnPayListener() {
		super();
//		cxxObject = nativeOnCreateCxxObject();
	}

//	@Override
//	public void onResult(HashMap<String, Object> params) {
//		JSONObject json = new JSONObject(params);
//		String value = json.toString();
//		nativeOnResult(value);
//	}
//
//	@Override
//	public void onError(Throwable t) {
//		JSONObject json = new JSONObject();
//		String value = json.toString();
//		nativeOnError(value);
//	}

	@Override
	protected void finalize() throws Throwable {
		super.finalize();
//		nativeOnDestoryCxxObject();
	}

//	private native int nativeOnCreateCxxObject();
//	private native int nativeOnResult(String string);
//	private native int nativeOnError(String string);
//	private native int nativeOnDestoryCxxObject();
//
//	public int getCxxObject() {
//		return cxxObject;
//	}
//
//	public static ActionListener newInstance() {
//		return new ActionListener();
//	}

	@Override
	public boolean onWillPay(String s, T t, MobPayAPI mobPayAPI) {
		return false;
	}

	@Override
	public void onPayEnd(PayResult payResult, T t, MobPayAPI mobPayAPI) {

	}
}
