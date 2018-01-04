LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

COCOS2D_ROOT := ../../../cocos2d

LOCAL_MODULE := moblink_bridge
LOCAL_MODULE_FILENAME := libmoblinbridge

ifeq ($(USE_ARM_MODE),1)
LOCAL_ARM_MODE := arm
endif

LOCAL_SRC_FILES := 	../../../Classes/C2DXPaySDK/C2DXPaySDK.cpp \
					../../../Classes/C2DXPaySDK/C2DXOnPayListener.cpp \
					../../../Classes/C2DXPaySDK/C2DXPayOrder.cpp \
					../../../Classes/C2DXPaySDK/C2DXPayTicket.cpp \
					../../../Classes/C2DXPaySDK/C2DXMobPayApi.cpp \
                    ../../../Classes/C2DXPaySDK/C2DXWxPayApi.cpp \
                    ../../../Classes/C2DXPaySDK/C2DXAliPayApi.cpp \
					../../../Classes/C2DXPaySDK/C2DXPayResult.cpp \
                    ../../../Classes/C2DXPaySDK/Android/C2DXAndroidAliApi.cpp \
                    ../../../Classes/C2DXPaySDK/Android/C2DXAndroidWxApi.cpp \
                    ../../../Classes/C2DXPaySDK/Android/C2DXAndroidPayOrder.cpp \
                    ../../../Classes/C2DXPaySDK/Android/C2DXAndroidPayTicket.cpp \
                    ../../../Classes/C2DXPaySDK/Android/C2DXCxxJavaObject.cpp \
                    ../../../Classes/C2DXPaySDK/Android/C2DXAndroidWxApi.cpp \




					
LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(COCOS2D_ROOT)/cocos \
					$(LOCAL_PATH)/$(COCOS2D_ROOT)/cocos/platform/android \
					$(LOCAL_PATH)/../../../Classes \
					$(LOCAL_PATH)/../../../Classes/C2DXPaySDK \
					$(LOCAL_PATH)/../../../Classes/C2DXPaySDK/Android \
					$(LOCAL_PATH)/../../../Classes/C2DXPaySDK/Android/JSON \
                    $(LOCAL_PATH)/../../../Classes/C2DXPaySDK/Android/JSON/cJSON
					
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../../../Classes/C2DXPaySDK \
					$(LOCAL_PATH)/../../../Classes/C2DXPaySDK/Android \
					$(LOCAL_PATH)/../../../Classes/C2DXPaySDK/Android/JSON \
                    $(LOCAL_PATH)/../../../Classes/C2DXPaySDK/Android/JSON/cJSON
					

include $(BUILD_STATIC_LIBRARY)

