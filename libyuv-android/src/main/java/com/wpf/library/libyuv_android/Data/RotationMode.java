package com.wpf.library.libyuv_android.Data;

/**
 * Created by 王朋飞 on 2018/5/9.
 */
public enum RotationMode {
    kRotate0(0),kRotate90(90),kRotate180(180),kRotate270(270),
    // Deprecated.
    kRotateNone(0),kRotateClockwise(90),kRotateCounterClockwise(270);

    private int value;

    RotationMode(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }

    // jni enum data
//    kRotate0 = 0,  // No rotation.
//    kRotate90 = 90,  // Rotate 90 degrees clockwise.
//    kRotate180 = 180,  // Rotate 180 degrees.
//    kRotate270 = 270,  // Rotate 270 degrees clockwise.
//
//    // Deprecated.
//    kRotateNone = 0,
//    kRotateClockwise = 90,
//    kRotateCounterClockwise = 270,
}
