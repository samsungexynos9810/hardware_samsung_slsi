#############################################################################
#
# Copyright (c) 2012 - 2013 Samsung Electronics Co., Ltd
#
#############################################################################
LOCAL_PATH := $(call my-dir)

ifneq ($(BOARD_HAVE_BLUETOOTH_SLSI),)

include $(CLEAR_VARS)

# Setup bdroid local make variables for handling configuration
ifneq ($(BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR),)
    bdroid_C_INCLUDES := $(BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR)
    bdroid_CFLAGS := -DHAS_BDROID_BUILDCFG
else
  bdroid_C_INCLUDES :=
  bdroid_CFLAGS := -DHAS_NO_BDROID_BUILDCFG
endif

BDROID_DIR := $(TOP_DIR)packages/modules/Bluetooth/system

LOCAL_SRC_FILES := \
    src/bt_vendor_slsi.c

LOCAL_C_INCLUDES += \
    $(BDROID_DIR)/hci/include \
    $(BDROID_DIR)/stack/include \
    $(BDROID_DIR)/include \
    $(LOCAL_PATH)/include \
    $(BDROID_DIR) \
    $(BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR)

LOCAL_CFLAGS += $(bdroid_CFLAGS)

ifneq ($(TARGET_BUILD_VARIANT),user)
LOCAL_CFLAGS += -DBTVENDOR_DBG=TRUE
endif

ifeq ($(CONFIG_SAMSUNG_SCSC_WIFIBT),true)
# Enable BT/WIFI related code changes in Android source files
LOCAL_CFLAGS += -DCONFIG_SAMSUNG_SCSC_WIFIBT
endif

LOCAL_SHARED_LIBRARIES := \
    libcutils \
    liblog

LOCAL_MULTILIB := both
LOCAL_MODULE := libbt-vendor
LOCAL_MODULE_OWNER := samsung
LOCAL_MODULE_TAGS := optional

LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_MODULE_PATH_32 := $(TARGET_OUT_VENDOR)/lib
LOCAL_MODULE_PATH_64 := $(TARGET_OUT_VENDOR)/lib64

include $(BUILD_SHARED_LIBRARY)

endif # BOARD_HAVE_BLUETOOTH_SLSI
