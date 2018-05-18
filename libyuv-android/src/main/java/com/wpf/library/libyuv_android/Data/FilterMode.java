package com.wpf.library.libyuv_android.Data;

/**
 * Created by 王朋飞 on 2018/5/9.
 */
public enum FilterMode {

    kFilterNone(0),kFilterLinear(1),kFilterBilinear(2),kFilterBox(3);

    private int value;

    FilterMode(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }

//    jni enum data
//    kFilterNone = 0,  // Point sample; Fastest.
//    kFilterLinear = 1,  // Filter horizontally only.
//    kFilterBilinear = 2,  // Faster than box, but lower quality scaling down.
//    kFilterBox = 3  // Highest quality.
}
