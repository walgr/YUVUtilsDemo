// Created by 王朋飞 on 2018/5/8.
//

#include "com_wpf_library_libyuv_android_YUVUtils.h"

#define TAG "libyuv-jni" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Compare_HashDjb2
 * Signature: ([BJI)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Compare_1HashDjb2
        (JNIEnv *env, jclass thiz, jbyteArray src, jlong count, jint seed) {

    uint8 *srcNative = (uint8 *) env->GetByteArrayElements(src, 0);
    uint64 countNative = (uint64) count;
    uint32 seedNative = (uint32) seed;

    jint result = libyuv::HashDjb2(srcNative, countNative, seedNative);

    env->ReleaseByteArrayElements(src, reinterpret_cast<jbyte *> (srcNative), 0);

    return result;
}



/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Compare_ARGBDetect
 * Signature: ([BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Compare_1ARGBDetect
        (JNIEnv *env, jclass thiz,
         jbyteArray argb, jint stride_argb,
         jint width, jint height) {

    uint8 *argbNative = (uint8 *) env->GetByteArrayElements(argb, 0);

    jint result = libyuv::ARGBDetect(argbNative, stride_argb, width, height);

    env->ReleaseByteArrayElements(argb, reinterpret_cast<jbyte *>(argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Compare_ComputeSumSquareError
 * Signature: ([B[BI)J
 */
JNIEXPORT jlong JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Compare_1ComputeSumSquareError
        (JNIEnv *env, jclass thiz,
         jbyteArray src_a, jbyteArray src_b, jint count) {

    uint8 *src_aNative = (uint8 *) env->GetByteArrayElements(src_a, 0);
    uint8 *src_bNative = (uint8 *) env->GetByteArrayElements(src_b, 0);

    jlong result = libyuv::ComputeSumSquareError(src_aNative, src_bNative, count);

    env->ReleaseByteArrayElements(src_a, reinterpret_cast<jbyte *>(src_aNative), 0);
    env->ReleaseByteArrayElements(src_b, reinterpret_cast<jbyte *>(src_bNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Compare_ComputeSumSquareErrorPlane
 * Signature: ([BI[BIII)J
 */
JNIEXPORT jlong JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Compare_1ComputeSumSquareErrorPlane
        (JNIEnv *env, jclass thiz,
         jbyteArray src_a, jint stride_a,
         jbyteArray src_b, jint stride_b,
         jint width, jint height) {

    uint8 *src_aNative = (uint8 *) env->GetByteArrayElements(src_a, 0);
    uint8 *src_bNative = (uint8 *) env->GetByteArrayElements(src_b, 0);

    jlong result = libyuv::ComputeSumSquareErrorPlane(
            src_aNative, stride_a,
            src_bNative, stride_b,
            width, height);

    env->ReleaseByteArrayElements(src_a, reinterpret_cast<jbyte *>(src_aNative), 0);
    env->ReleaseByteArrayElements(src_b, reinterpret_cast<jbyte *>(src_bNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Compare_SumSquareErrorToPsnr
 * Signature: (JJ)J
 */
JNIEXPORT jdouble JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Compare_1SumSquareErrorToPsnr
        (JNIEnv *env, jclass thiz, jlong sse, jlong count) {

    uint32 sseNative = (uint32) sse;
    uint64 countNative = (uint64) count;

    return libyuv::SumSquareErrorToPsnr(sseNative, countNative);
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Compare_CalcFramePsnr
 * Signature: ([BI[BIII)J
 */
JNIEXPORT jdouble JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Compare_1CalcFramePsnr
        (JNIEnv *env, jclass thiz,
         jbyteArray src_a, jint stride_a,
         jbyteArray src_b, jint stride_b,
         jint width, jint height) {

    uint8 *src_aNative = (uint8 *) env->GetByteArrayElements(src_a, 0);
    uint8 *src_bNative = (uint8 *) env->GetByteArrayElements(src_b, 0);

    jdouble result = libyuv::CalcFramePsnr(
            src_aNative, stride_a,
            src_bNative, stride_b,
            width, height);

    env->ReleaseByteArrayElements(src_a, reinterpret_cast<jbyte *>(src_aNative), 0);
    env->ReleaseByteArrayElements(src_b, reinterpret_cast<jbyte *>(src_bNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Compare_I420Psnr
 * Signature: ([BI[BI[BI[BI[BI[BIII)J
 */
JNIEXPORT jdouble JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Compare_1I420Psnr
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y_a, jint stride_y_a,
         jbyteArray src_u_a, jint stride_u_a,
         jbyteArray src_v_a, jint stride_v_a,
         jbyteArray src_y_b, jint stride_y_b,
         jbyteArray src_u_b, jint stride_u_b,
         jbyteArray src_v_b, jint stride_v_b,
         jint width, jint height) {

    uint8 *src_y_aNative = (uint8 *) env->GetByteArrayElements(src_y_a, 0);
    uint8 *src_u_aNative = (uint8 *) env->GetByteArrayElements(src_u_a, 0);
    uint8 *src_v_aNative = (uint8 *) env->GetByteArrayElements(src_v_a, 0);
    uint8 *src_y_bNative = (uint8 *) env->GetByteArrayElements(src_y_b, 0);
    uint8 *src_u_bNative = (uint8 *) env->GetByteArrayElements(src_u_b, 0);
    uint8 *src_v_bNative = (uint8 *) env->GetByteArrayElements(src_v_b, 0);

    jdouble result = libyuv::I420Psnr(
            src_y_aNative, stride_y_a,
            src_u_aNative, stride_u_a,
            src_v_aNative, stride_v_a,
            src_y_bNative, stride_y_b,
            src_u_bNative, stride_u_b,
            src_v_bNative, stride_v_b,
            width, height
    );

    env->ReleaseByteArrayElements(src_y_a, reinterpret_cast<jbyte *>(src_y_aNative), 0);
    env->ReleaseByteArrayElements(src_u_a, reinterpret_cast<jbyte *>(src_u_aNative), 0);
    env->ReleaseByteArrayElements(src_v_a, reinterpret_cast<jbyte *>(src_v_aNative), 0);
    env->ReleaseByteArrayElements(src_y_b, reinterpret_cast<jbyte *>(src_y_bNative), 0);
    env->ReleaseByteArrayElements(src_u_b, reinterpret_cast<jbyte *>(src_u_bNative), 0);
    env->ReleaseByteArrayElements(src_v_b, reinterpret_cast<jbyte *>(src_v_bNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Compare_CalcFrameSsim
 * Signature: ([BI[BIII)J
 */
JNIEXPORT jdouble JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Compare_1CalcFrameSsim
        (JNIEnv *env, jclass thiz,
         jbyteArray src_a, jint stride_a,
         jbyteArray src_b, jint stride_b,
         jint width, jint height) {

    uint8 *src_aNative = (uint8 *) env->GetByteArrayElements(src_a, 0);
    uint8 *src_bNative = (uint8 *) env->GetByteArrayElements(src_b, 0);

    jdouble result = libyuv::CalcFrameSsim(
            src_aNative, stride_a,
            src_bNative, stride_b,
            width, height);

    env->ReleaseByteArrayElements(src_a, reinterpret_cast<jbyte *>(src_aNative), 0);
    env->ReleaseByteArrayElements(src_b, reinterpret_cast<jbyte *>(src_bNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Compare_I420Ssim
 * Signature: ([BI[BI[BI[BI[BI[BIII)J
 */
JNIEXPORT jdouble JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Compare_1I420Ssim
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y_a, jint stride_y_a,
         jbyteArray src_u_a, jint stride_u_a,
         jbyteArray src_v_a, jint stride_v_a,
         jbyteArray src_y_b, jint stride_y_b,
         jbyteArray src_u_b, jint stride_u_b,
         jbyteArray src_v_b, jint stride_v_b,
         jint width, jint height) {

    uint8 *src_y_aNative = (uint8 *) env->GetByteArrayElements(src_y_a, 0);
    uint8 *src_u_aNative = (uint8 *) env->GetByteArrayElements(src_u_a, 0);
    uint8 *src_v_aNative = (uint8 *) env->GetByteArrayElements(src_v_a, 0);
    uint8 *src_y_bNative = (uint8 *) env->GetByteArrayElements(src_y_b, 0);
    uint8 *src_u_bNative = (uint8 *) env->GetByteArrayElements(src_u_b, 0);
    uint8 *src_v_bNative = (uint8 *) env->GetByteArrayElements(src_v_b, 0);

    jdouble result = libyuv::I420Ssim(
            src_y_aNative, stride_y_a,
            src_u_aNative, stride_u_a,
            src_v_aNative, stride_v_a,
            src_y_bNative, stride_y_b,
            src_u_bNative, stride_u_b,
            src_v_bNative, stride_v_b,
            width, height
    );

    env->ReleaseByteArrayElements(src_y_a, reinterpret_cast<jbyte *>(src_y_aNative), 0);
    env->ReleaseByteArrayElements(src_u_a, reinterpret_cast<jbyte *>(src_u_aNative), 0);
    env->ReleaseByteArrayElements(src_v_a, reinterpret_cast<jbyte *>(src_v_aNative), 0);
    env->ReleaseByteArrayElements(src_y_b, reinterpret_cast<jbyte *>(src_y_bNative), 0);
    env->ReleaseByteArrayElements(src_u_b, reinterpret_cast<jbyte *>(src_u_bNative), 0);
    env->ReleaseByteArrayElements(src_v_b, reinterpret_cast<jbyte *>(src_v_bNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_I420Copy
 * Signature: ([BI[BI[BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1I420Copy
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::I420Copy(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_I422ToI420
 * Signature: ([BI[BI[BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1I422ToI420
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::I422ToI420(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_I444ToI420
 * Signature: ([BI[BI[BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1I444ToI420
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::I444ToI420(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_I400ToI420
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1I400ToI420
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::I400ToI420(
            src_yNative, src_stride_y,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_NV12ToI420
 * Signature: ([BI[BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1NV12ToI420
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_uv, jint src_stride_uv,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uvNative = (uint8 *) env->GetByteArrayElements(src_uv, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::NV12ToI420(
            src_yNative, src_stride_y,
            src_uvNative, src_stride_uv,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_uv, reinterpret_cast<jbyte *>(src_uvNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_NV21ToI420
 * Signature: ([BI[BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1NV21ToI420
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_vu, jint src_stride_vu,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_vuNative = (uint8 *) env->GetByteArrayElements(src_vu, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::NV21ToI420(
            src_yNative, src_stride_y,
            src_vuNative, src_stride_vu,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_vu, reinterpret_cast<jbyte *>(src_vuNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_M420ToI420
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1M420ToI420
        (JNIEnv *env, jclass thiz,
         jbyteArray src_m420, jint src_stride_m420,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_m420Native = (uint8 *) env->GetByteArrayElements(src_m420, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::M420ToI420(
            src_m420Native, src_stride_m420,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_m420, reinterpret_cast<jbyte *>(src_m420Native), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_YUY2ToI420
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1YUY2ToI420
        (JNIEnv *env, jclass thiz,
         jbyteArray src_yuy2, jint src_stride_yuy2,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_yuy2Native = (uint8 *) env->GetByteArrayElements(src_yuy2, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::YUY2ToI420(
            src_yuy2Native, src_stride_yuy2,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_yuy2, reinterpret_cast<jbyte *>(src_yuy2Native), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_UYVYToI420
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1UYVYToI420
        (JNIEnv *env, jclass thiz,
         jbyteArray src_uyvy, jint src_stride_uyvy,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_uyvyNative = (uint8 *) env->GetByteArrayElements(src_uyvy, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::UYVYToI420(
            src_uyvyNative, src_stride_uyvy,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_uyvy, reinterpret_cast<jbyte *>(src_uyvyNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGBToI420
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGBToI420
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_src_argb,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::ARGBToI420(
            src_argbNative, src_stride_src_argb,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_BGRAToI420
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1BGRAToI420
        (JNIEnv *env, jclass thiz,
         jbyteArray src_bgra, jint src_stride_bgra,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_bgraNative = (uint8 *) env->GetByteArrayElements(src_bgra, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::BGRAToI420(
            src_bgraNative, src_stride_bgra,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_bgra, reinterpret_cast<jbyte *>(src_bgraNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ABGRToI420
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ABGRToI420
        (JNIEnv *env, jclass thiz,
         jbyteArray src_abgr, jint src_stride_abgr,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_abgrNative = (uint8 *) env->GetByteArrayElements(src_abgr, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::ABGRToI420(
            src_abgrNative, src_stride_abgr,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_abgr, reinterpret_cast<jbyte *>(src_abgrNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_RGBAToI420
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1RGBAToI420
        (JNIEnv *env, jclass thiz,
         jbyteArray src_rgba, jint src_stride_rgba,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_rgbaNative = (uint8 *) env->GetByteArrayElements(src_rgba, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::RGBAToI420(
            src_rgbaNative, src_stride_rgba,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_rgba, reinterpret_cast<jbyte *>(src_rgbaNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_RGB24ToI420
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1RGB24ToI420
        (JNIEnv *env, jclass thiz,
         jbyteArray src_rgb24, jint src_stride_rgb24,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_rgb24Native = (uint8 *) env->GetByteArrayElements(src_rgb24, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::RGB24ToI420(
            src_rgb24Native, src_stride_rgb24,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_rgb24, reinterpret_cast<jbyte *>(src_rgb24Native), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_RAWToI420
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1RAWToI420
        (JNIEnv *env, jclass thiz,
         jbyteArray src_raw, jint src_stride_raw,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_rawNative = (uint8 *) env->GetByteArrayElements(src_raw, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::RAWToI420(
            src_rawNative, src_stride_raw,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_raw, reinterpret_cast<jbyte *>(src_rawNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_RGB565ToI420
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1RGB565ToI420
        (JNIEnv *env, jclass thiz,
         jbyteArray src_rgb565, jint src_stride_rgb565,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_rgb565Native = (uint8 *) env->GetByteArrayElements(src_rgb565, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::RGB565ToI420(
            src_rgb565Native, src_stride_rgb565,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_rgb565, reinterpret_cast<jbyte *>(src_rgb565Native), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB1555ToI420
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB1555ToI420
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb1555, jint src_stride_argb1555,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_argb1555Native = (uint8 *) env->GetByteArrayElements(src_argb1555, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::ARGB1555ToI420(
            src_argb1555Native, src_stride_argb1555,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_argb1555, reinterpret_cast<jbyte *>(src_argb1555Native), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB4444ToI420
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB4444ToI420
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb4444, jint src_stride_argb4444,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_argb4444Native = (uint8 *) env->GetByteArrayElements(src_argb4444, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::ARGB4444ToI420(
            src_argb4444Native, src_stride_argb4444,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_argb4444, reinterpret_cast<jbyte *>(src_argb4444Native), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_Android420ToI420
 * Signature: ([BI[BI[BII[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1Android420ToI420
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jint src_pixel_stride_uv,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::Android420ToI420(src_yNative, src_stride_y,
                                           src_uNative, src_stride_u,
                                           src_vNative, src_stride_v,
                                           src_pixel_stride_uv,
                                           dst_yNative, dst_stride_y,
                                           dst_uNative, dst_stride_u,
                                           dst_vNative, dst_stride_v,
                                           width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_ARGBCopy
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1ARGBCopy
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBCopy(
            src_argbNative, src_stride_argb,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_I420ToARGB
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1I420ToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {
    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::I420ToARGB(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_I420ToABGR
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1I420ToABGR
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_abgr, jint dst_stride_abgr,
         jint width, jint height) {
    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_abgrNative = (uint8 *) env->GetByteArrayElements(dst_abgr, 0);

    jint result = libyuv::I420ToABGR(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_abgrNative, dst_stride_abgr,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_abgr, reinterpret_cast<jbyte *>(dst_abgrNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_J420ToARGB
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1J420ToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {
    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::J420ToARGB(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_J420ToABGR
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1J420ToABGR
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_abgr, jint dst_stride_abgr,
         jint width, jint height) {
    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_abgrNative = (uint8 *) env->GetByteArrayElements(dst_abgr, 0);

    jint result = libyuv::J420ToABGR(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_abgrNative, dst_stride_abgr,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_abgr, reinterpret_cast<jbyte *>(dst_abgrNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_H420ToARGB
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1H420ToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {
    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::H420ToARGB(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_H420ToABGR
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1H420ToABGR
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_abgr, jint dst_stride_abgr,
         jint width, jint height) {
    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_abgrNative = (uint8 *) env->GetByteArrayElements(dst_abgr, 0);

    jint result = libyuv::H420ToABGR(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_abgrNative, dst_stride_abgr,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_abgr, reinterpret_cast<jbyte *>(dst_abgrNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_I422ToARGB
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1I422ToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {
    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::I422ToARGB(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_I422ToABGR
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1I422ToABGR
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_abgr, jint dst_stride_abgr,
         jint width, jint height) {
    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_abgrNative = (uint8 *) env->GetByteArrayElements(dst_abgr, 0);

    jint result = libyuv::I422ToABGR(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_abgrNative, dst_stride_abgr,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_abgr, reinterpret_cast<jbyte *>(dst_abgrNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_J422ToARGB
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1J422ToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {
    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::J422ToARGB(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_J422ToABGR
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1J422ToABGR
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_abgr, jint dst_stride_abgr,
         jint width, jint height) {
    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_abgrNative = (uint8 *) env->GetByteArrayElements(dst_abgr, 0);

    jint result = libyuv::J422ToABGR(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_abgrNative, dst_stride_abgr,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_abgr, reinterpret_cast<jbyte *>(dst_abgrNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_H422ToARGB
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1H422ToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {
    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::H422ToARGB(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_H422ToABGR
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1H422ToABGR
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_abgr, jint dst_stride_abgr,
         jint width, jint height) {
    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_abgrNative = (uint8 *) env->GetByteArrayElements(dst_abgr, 0);

    jint result = libyuv::H422ToABGR(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_abgrNative, dst_stride_abgr,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_abgr, reinterpret_cast<jbyte *>(dst_abgrNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_I444ToARGB
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1I444ToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {
    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::I444ToARGB(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_I444ToABGR
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1I444ToABGR
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_abgr, jint dst_stride_abgr,
         jint width, jint height) {
    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_abgrNative = (uint8 *) env->GetByteArrayElements(dst_abgr, 0);

    jint result = libyuv::I444ToABGR(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_abgrNative, dst_stride_abgr,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_abgr, reinterpret_cast<jbyte *>(dst_abgrNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_J444ToARGB
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1J444ToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {
    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::J444ToARGB(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_I420AlphaToARGB
 * Signature: ([BI[BI[BI[BI[BIIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1I420AlphaToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray src_a, jint src_stride_a,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height, jint attenuate) {
    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *src_aNative = (uint8 *) env->GetByteArrayElements(src_a, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::I420AlphaToARGB(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            src_aNative, src_stride_a,
            dst_argbNative, dst_stride_argb,
            width, height, attenuate);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(src_a, reinterpret_cast<jbyte *>(src_aNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_I420AlphaToABGR
 * Signature: ([BI[BI[BI[BI[BIIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1I420AlphaToABGR
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray src_a, jint src_stride_a,
         jbyteArray dst_abgr, jint dst_stride_abgr,
         jint width, jint height, jint attenuate) {
    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *src_aNative = (uint8 *) env->GetByteArrayElements(src_a, 0);
    uint8 *dst_abgrNative = (uint8 *) env->GetByteArrayElements(dst_abgr, 0);

    jint result = libyuv::I420AlphaToABGR(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            src_aNative, src_stride_a,
            dst_abgrNative, dst_stride_abgr,
            width, height, attenuate);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(src_a, reinterpret_cast<jbyte *>(src_aNative), 0);
    env->ReleaseByteArrayElements(dst_abgr, reinterpret_cast<jbyte *>(dst_abgrNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_I400ToARGB
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1I400ToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::I400ToARGB(
            src_yNative, src_stride_y,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_J400ToARGB
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1J400ToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::J400ToARGB(
            src_yNative, src_stride_y,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_BGRAToARGB
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1BGRAToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_bgra, jint src_stride_bgra,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_bgraNative = (uint8 *) env->GetByteArrayElements(src_bgra, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::BGRAToARGB(
            src_bgraNative, src_stride_bgra,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_bgra, reinterpret_cast<jbyte *>(src_bgraNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_ARGBToBGRA
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1ARGBToBGRA
        (JNIEnv *env, jclass thiz,
         jbyteArray src_bgra, jint src_stride_bgra,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_bgraNative = (uint8 *) env->GetByteArrayElements(src_bgra, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBToBGRA(
            src_bgraNative, src_stride_bgra,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_bgra, reinterpret_cast<jbyte *>(src_bgraNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_ABGRToARGB
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1ABGRToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_abgr, jint src_stride_abgr,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_abgrNative = (uint8 *) env->GetByteArrayElements(src_abgr, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ABGRToARGB(
            src_abgrNative, src_stride_abgr,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_abgr, reinterpret_cast<jbyte *>(src_abgrNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_ARGBToABGR
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1ARGBToABGR
        (JNIEnv *env, jclass thiz,
         jbyteArray src_abgr, jint src_stride_abgr,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_abgrNative = (uint8 *) env->GetByteArrayElements(src_abgr, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBToABGR(
            src_abgrNative, src_stride_abgr,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_abgr, reinterpret_cast<jbyte *>(src_abgrNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_RGBAToARGB
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1RGBAToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_rgba, jint src_stride_rgba,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_rgbaNative = (uint8 *) env->GetByteArrayElements(src_rgba, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::RGBAToARGB(
            src_rgbaNative, src_stride_rgba,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_rgba, reinterpret_cast<jbyte *>(src_rgbaNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_RGB24ToARGB
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1RGB24ToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_rgb24, jint src_stride_rgb24,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_rgb24Native = (uint8 *) env->GetByteArrayElements(src_rgb24, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::RGB24ToARGB(
            src_rgb24Native, src_stride_rgb24,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_rgb24, reinterpret_cast<jbyte *>(src_rgb24Native), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_RAWToARGB
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1RAWToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_rgb24, jint src_stride_rgb24,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_rgb24Native = (uint8 *) env->GetByteArrayElements(src_rgb24, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::RGB24ToARGB(
            src_rgb24Native, src_stride_rgb24,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_rgb24, reinterpret_cast<jbyte *>(src_rgb24Native), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_RGB565ToARGB
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1RGB565ToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_rgb565, jint src_stride_rgb565,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_rgb565Native = (uint8 *) env->GetByteArrayElements(src_rgb565, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::RGB565ToARGB(
            src_rgb565Native, src_stride_rgb565,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_rgb565, reinterpret_cast<jbyte *>(src_rgb565Native), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_ARGB1555ToARGB
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1ARGB1555ToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb1555, jint src_stride_argb1555,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_argb1555Native = (uint8 *) env->GetByteArrayElements(src_argb1555, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGB1555ToARGB(
            src_argb1555Native, src_stride_argb1555,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_argb1555, reinterpret_cast<jbyte *>(src_argb1555Native), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_ARGB4444ToARGB
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1ARGB4444ToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb4444, jint src_stride_argb4444,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_argb4444Native = (uint8 *) env->GetByteArrayElements(src_argb4444, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGB4444ToARGB(
            src_argb4444Native, src_stride_argb4444,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_argb4444, reinterpret_cast<jbyte *>(src_argb4444Native), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_NV12ToARGB
 * Signature: ([BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1NV12ToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_uv, jint src_stride_uv,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uvNative = (uint8 *) env->GetByteArrayElements(src_uv, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::NV12ToARGB(
            src_yNative, src_stride_y,
            src_uvNative, src_stride_uv,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_uv, reinterpret_cast<jbyte *>(src_uvNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_NV21ToARGB
 * Signature: ([BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1NV21ToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_uv, jint src_stride_uv,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uvNative = (uint8 *) env->GetByteArrayElements(src_uv, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::NV21ToARGB(
            src_yNative, src_stride_y,
            src_uvNative, src_stride_uv,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_uv, reinterpret_cast<jbyte *>(src_uvNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_M420ToARGB
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1M420ToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_m420, jint src_stride_m420,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_m420Native = (uint8 *) env->GetByteArrayElements(src_m420, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::M420ToARGB(
            src_m420Native, src_stride_m420,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_m420, reinterpret_cast<jbyte *>(src_m420Native), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_YUY2ToARGB
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1YUY2ToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_yuy2, jint src_stride_yuy2,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_yuy2Native = (uint8 *) env->GetByteArrayElements(src_yuy2, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::YUY2ToARGB(
            src_yuy2Native, src_stride_yuy2,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_yuy2, reinterpret_cast<jbyte *>(src_yuy2Native), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_ARGB_UYVYToARGB
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1ARGB_1UYVYToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray src_uyvy, jint src_stride_uyvy,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_uyvyNative = (uint8 *) env->GetByteArrayElements(src_uyvy, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::UYVYToARGB(
            src_uyvyNative, src_stride_uyvy,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_uyvy, reinterpret_cast<jbyte *>(src_uyvyNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_I420ToI422
 * Signature: ([BI[BI[BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1I420ToI422
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::I420ToI422(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_I420ToI444
 * Signature: ([BI[BI[BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1I420ToI444
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::I420ToI444(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_I400Copy
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1I400Copy
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray dst_y, jint dst_stride_y,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);

    jint result = libyuv::I400Copy(
            src_yNative, src_stride_y,
            dst_yNative, dst_stride_y,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_I422ToYUY2
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1I422ToYUY2
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_yuy2, jint dst_stride_yuy2,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_yuy2Native = (uint8 *) env->GetByteArrayElements(dst_yuy2, 0);

    jint result = libyuv::I422ToYUY2(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_yuy2Native, dst_stride_yuy2,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_yuy2, reinterpret_cast<jbyte *>(dst_yuy2Native), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_I420ToYUY2
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1I420ToYUY2
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_yuy2, jint dst_stride_yuy2,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_yuy2Native = (uint8 *) env->GetByteArrayElements(dst_yuy2, 0);

    jint result = libyuv::I420ToYUY2(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_yuy2Native, dst_stride_yuy2,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_yuy2, reinterpret_cast<jbyte *>(dst_yuy2Native), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_I422ToUYVY
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1I422ToUYVY
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_uyvy, jint dst_stride_uyvy,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_uyvyNative = (uint8 *) env->GetByteArrayElements(dst_uyvy, 0);

    jint result = libyuv::I422ToYUY2(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_uyvyNative, dst_stride_uyvy,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_uyvy, reinterpret_cast<jbyte *>(dst_uyvyNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_I420ToUYVY
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1I420ToUYVY
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_uyvy, jint dst_stride_uyvy,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_uyvyNative = (uint8 *) env->GetByteArrayElements(dst_uyvy, 0);

    jint result = libyuv::I420ToYUY2(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_uyvyNative, dst_stride_uyvy,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_uyvy, reinterpret_cast<jbyte *>(dst_uyvyNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_I420ToNV12
 * Signature: ([BI[BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1I420ToNV12
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_uv, jint dst_stride_uv,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uvNative = (uint8 *) env->GetByteArrayElements(dst_uv, 0);

    jint result = libyuv::I420ToNV12(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_yNative, dst_stride_y,
            dst_uvNative, dst_stride_uv,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_uv, reinterpret_cast<jbyte *>(dst_uvNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_I420ToNV21
 * Signature: ([BI[BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1I420ToNV21
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_vu, jint dst_stride_vu,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_vuNative = (uint8 *) env->GetByteArrayElements(dst_vu, 0);

    jint result = libyuv::I420ToNV21(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_yNative, dst_stride_y,
            dst_vuNative, dst_stride_vu,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_vu, reinterpret_cast<jbyte *>(dst_vuNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_I420ToRGBA
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1I420ToRGBA
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_rgba, jint dst_stride_rgba,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_rgbaNative = (uint8 *) env->GetByteArrayElements(dst_rgba, 0);

    jint result = libyuv::I420ToRGBA(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_rgbaNative, dst_stride_rgba,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_rgba, reinterpret_cast<jbyte *>(dst_rgbaNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_I420ToBGRA
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1I420ToBGRA
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_bgra, jint dst_stride_bgra,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_bgraNative = (uint8 *) env->GetByteArrayElements(dst_bgra, 0);

    jint result = libyuv::I420ToBGRA(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_bgraNative, dst_stride_bgra,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_bgra, reinterpret_cast<jbyte *>(dst_bgraNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_I420ToRGB24
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1I420ToRGB24
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_rgb24, jint dst_stride_rgb24,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_rgb24Native = (uint8 *) env->GetByteArrayElements(dst_rgb24, 0);

    jint result = libyuv::I420ToRGB24(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_rgb24Native, dst_stride_rgb24,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_rgb24, reinterpret_cast<jbyte *>(dst_rgb24Native), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_I420ToRAW
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1I420ToRAW
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_raw, jint dst_stride_raw,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_rawNative = (uint8 *) env->GetByteArrayElements(dst_raw, 0);

    jint result = libyuv::I420ToRAW(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_rawNative, dst_stride_raw,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_raw, reinterpret_cast<jbyte *>(dst_rawNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_I420ToARGB1555
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1I420ToARGB1555
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_argb1555, jint dst_stride_argb1555,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_argb1555Native = (uint8 *) env->GetByteArrayElements(dst_argb1555, 0);

    jint result = libyuv::I420ToARGB1555(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_argb1555Native, dst_stride_argb1555,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_argb1555, reinterpret_cast<jbyte *>(dst_argb1555Native), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_I420ToARGB4444
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1I420ToARGB4444
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_argb4444, jint dst_stride_argb4444,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_argb4444Native = (uint8 *) env->GetByteArrayElements(dst_argb4444, 0);

    jint result = libyuv::I420ToARGB4444(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_argb4444Native, dst_stride_argb4444,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_argb4444, reinterpret_cast<jbyte *>(dst_argb4444Native), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_I420ToRGB565
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1I420ToRGB565
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_rgb565, jint dst_stride_rgb565,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_rgb565Native = (uint8 *) env->GetByteArrayElements(dst_rgb565, 0);

    jint result = libyuv::I420ToRGB565(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_rgb565Native, dst_stride_rgb565,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_rgb565, reinterpret_cast<jbyte *>(dst_rgb565Native), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_I420ToRGB565Dither
 * Signature: ([BI[BI[BI[BI[BII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1I420ToRGB565Dither
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_rgb565, jint dst_stride_rgb565,
         jbyteArray dither4x4,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_rgb565Native = (uint8 *) env->GetByteArrayElements(dst_rgb565, 0);
    uint8 *dither4x4Native = (uint8 *) env->GetByteArrayElements(dst_rgb565, 0);

    jint result = libyuv::I420ToRGB565Dither(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_rgb565Native, dst_stride_rgb565,
            dither4x4Native,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_rgb565, reinterpret_cast<jbyte *>(dst_rgb565Native), 0);
    env->ReleaseByteArrayElements(dither4x4, reinterpret_cast<jbyte *>(dither4x4Native), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_ConvertFromI420
 * Signature: ([BI[BI[BI[BIIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1ConvertFromI420
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_sample, jint dst_stride_sample,
         jint width, jint height, jint fourcc) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_sampleNative = (uint8 *) env->GetByteArrayElements(dst_sample, 0);
    uint32 fourccNative = (uint32) fourcc;

    jint result = libyuv::ConvertFromI420(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_sampleNative, dst_stride_sample,
            width, height, fourccNative);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_sample, reinterpret_cast<jbyte *>(dst_sampleNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_ARGB_ARGBToI444
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1ARGB_1ARGBToI444
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::ARGBToI444(
            src_argbNative, src_stride_argb,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_ARGB_ARGBToI422
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1ARGB_1ARGBToI422
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::ARGBToI422(
            src_argbNative, src_stride_argb,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_ARGB_ARGBToNV12
 * Signature: ([BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1ARGB_1ARGBToNV12
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_uv, jint dst_stride_uv,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uvNative = (uint8 *) env->GetByteArrayElements(dst_uv, 0);

    jint result = libyuv::ARGBToNV12(
            src_argbNative, src_stride_argb,
            dst_yNative, dst_stride_y,
            dst_uvNative, dst_stride_uv,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_uv, reinterpret_cast<jbyte *>(dst_uvNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_ARGB_ARGBToNV21
 * Signature: ([BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1ARGB_1ARGBToNV21
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_uv, jint dst_stride_uv,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uvNative = (uint8 *) env->GetByteArrayElements(dst_uv, 0);

    jint result = libyuv::ARGBToNV21(
            src_argbNative, src_stride_argb,
            dst_yNative, dst_stride_y,
            dst_uvNative, dst_stride_uv,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_uv, reinterpret_cast<jbyte *>(dst_uvNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_ARGB_ARGBToYUY2
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1ARGB_1ARGBToYUY2
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_yuy2, jint dst_stride_yuy2,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_yuy2Native = (uint8 *) env->GetByteArrayElements(dst_yuy2, 0);

    jint result = libyuv::ARGBToYUY2(
            src_argbNative, src_stride_argb,
            dst_yuy2Native, dst_stride_yuy2,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_yuy2, reinterpret_cast<jbyte *>(dst_yuy2Native), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_ARGB_ARGBToUYVY
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1ARGB_1ARGBToUYVY
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_uyvy, jint dst_stride_uyvy,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_uyvyNative = (uint8 *) env->GetByteArrayElements(dst_uyvy, 0);

    jint result = libyuv::ARGBToUYVY(
            src_argbNative, src_stride_argb,
            dst_uyvyNative, dst_stride_uyvy,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_uyvy, reinterpret_cast<jbyte *>(dst_uyvyNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_ARGB_ARGBToI400
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1ARGB_1ARGBToI400
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_y, jint dst_stride_y,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);

    jint result = libyuv::ARGBToI400(
            src_argbNative, src_stride_argb,
            dst_yNative, dst_stride_y,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_ARGB_ARGBToRGBA
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1ARGB_1ARGBToRGBA
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_rgba, jint dst_stride_rgba,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_rgbaNative = (uint8 *) env->GetByteArrayElements(dst_rgba, 0);

    jint result = libyuv::ARGBToI400(
            src_argbNative, src_stride_argb,
            dst_rgbaNative, dst_stride_rgba,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_rgba, reinterpret_cast<jbyte *>(dst_rgbaNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_ARGB_ARGBToRGB24
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1ARGB_1ARGBToRGB24
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_rgb24, jint dst_stride_rgb24,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_rgb24Native = (uint8 *) env->GetByteArrayElements(dst_rgb24, 0);

    jint result = libyuv::ARGBToI400(
            src_argbNative, src_stride_argb,
            dst_rgb24Native, dst_stride_rgb24,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_rgb24, reinterpret_cast<jbyte *>(dst_rgb24Native), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_ARGB_ARGBToRAW
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1ARGB_1ARGBToRAW
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_raw, jint dst_stride_raw,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_rawNative = (uint8 *) env->GetByteArrayElements(dst_raw, 0);

    jint result = libyuv::ARGBToI400(
            src_argbNative, src_stride_argb,
            dst_rawNative, dst_stride_raw,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_raw, reinterpret_cast<jbyte *>(dst_rawNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_ARGB_ARGBToRGB565Dither
 * Signature: ([BI[BI[BII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1ARGB_1ARGBToRGB565Dither
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_rgb565, jint dst_stride_rgb565,
         jbyteArray dither4x4,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_rgb565Native = (uint8 *) env->GetByteArrayElements(dst_rgb565, 0);
    uint8 *dither4x4Native = (uint8 *) env->GetByteArrayElements(dst_rgb565, 0);

    jint result = libyuv::ARGBToRGB565Dither(
            src_argbNative, src_stride_argb,
            dst_rgb565Native, dst_stride_rgb565,
            dither4x4Native,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_rgb565, reinterpret_cast<jbyte *>(dst_rgb565Native), 0);
    env->ReleaseByteArrayElements(dither4x4, reinterpret_cast<jbyte *>(dither4x4Native), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_ARGB_ARGBToRGB565
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1ARGB_1ARGBToRGB565
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_rgb565, jint dst_stride_rgb565,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_rgb565Native = (uint8 *) env->GetByteArrayElements(dst_rgb565, 0);

    jint result = libyuv::ARGBToRGB565(
            src_argbNative, src_stride_argb,
            dst_rgb565Native, dst_stride_rgb565,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_rgb565, reinterpret_cast<jbyte *>(dst_rgb565Native), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_ARGB_ARGBToARGB1555
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1ARGB_1ARGBToARGB1555
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_argb1555, jint dst_stride_argb1555,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_argb1555Native = (uint8 *) env->GetByteArrayElements(dst_argb1555, 0);

    jint result = libyuv::ARGBToARGB1555(
            src_argbNative, src_stride_argb,
            dst_argb1555Native, dst_stride_argb1555,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_argb1555, reinterpret_cast<jbyte *>(dst_argb1555Native), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_ARGB_ARGBToARGB4444
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1ARGB_1ARGBToARGB4444
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_argb4444, jint dst_stride_argb4444,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_argb4444Native = (uint8 *) env->GetByteArrayElements(dst_argb4444, 0);

    jint result = libyuv::ARGBToARGB1555(
            src_argbNative, src_stride_argb,
            dst_argb4444Native, dst_stride_argb4444,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_argb4444, reinterpret_cast<jbyte *>(dst_argb4444Native), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_ARGB_ARGBToJ420
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1ARGB_1ARGBToJ420
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_src_argb,
         jbyteArray dst_yj, jint dst_stride_yj,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_yjNative = (uint8 *) env->GetByteArrayElements(dst_yj, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::ARGBToJ420(
            src_argbNative, src_stride_src_argb,
            dst_yjNative, dst_stride_yj,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_yj, reinterpret_cast<jbyte *>(dst_yjNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_ARGB_ARGBToJ422
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1ARGB_1ARGBToJ422
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_src_argb,
         jbyteArray dst_yj, jint dst_stride_yj,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_yjNative = (uint8 *) env->GetByteArrayElements(dst_yj, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::ARGBToJ422(
            src_argbNative, src_stride_src_argb,
            dst_yjNative, dst_stride_yj,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_yj, reinterpret_cast<jbyte *>(dst_yjNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_From_ARGB_ARGBToJ400
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1From_1ARGB_1ARGBToJ400
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_src_argb,
         jbyteArray dst_yj, jint dst_stride_yj,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_yjNative = (uint8 *) env->GetByteArrayElements(dst_yj, 0);

    jint result = libyuv::ARGBToJ400(
            src_argbNative, src_stride_src_argb,
            dst_yjNative, dst_stride_yj,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_yj, reinterpret_cast<jbyte *>(dst_yjNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_To_ARGB_ConvertToARGB
 * Signature: ([BI[BIIIIIIILcom/wpf/library/libyuv_android/Data/RotationMode  {
    return 0;
}I)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1To_1ARGB_1ConvertToARGB
        (JNIEnv *env, jclass thiz,
         jbyteArray sample, jint sample_size,
         jbyteArray crop_argb, jint argb_stride,
         jint crop_x, jint crop_y,
         jint src_width, jint src_height,
         jint crop_width, jint crop_height,
         jobject rotation, jint fourcc) {

    uint8 *sampleNative = (uint8 *) env->GetByteArrayElements(sample, 0);
    uint8 *crop_argbNative = (uint8 *) env->GetByteArrayElements(crop_argb, 0);
    uint32 sample_sizecNative = (uint32) sample_size;
    uint32 fourccNative = (uint32) fourcc;

    jint result = libyuv::ConvertToARGB(
            sampleNative, sample_sizecNative,
            crop_argbNative, argb_stride,
            crop_x, crop_y,
            src_width, src_height,
            crop_width, crop_height,
            getRotationMode(env, rotation), fourccNative);

    env->ReleaseByteArrayElements(sample, reinterpret_cast<jbyte *>(sampleNative), 0);
    env->ReleaseByteArrayElements(crop_argb, reinterpret_cast<jbyte *>(crop_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Convert_To_I420_ConvertToI420
 * Signature: ([BI[BI[BI[BIIIIIIILcom/wpf/library/libyuv_android/Data/RotationMode  {
    return 0;
}I)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Convert_1To_1I420_1ConvertToI420
        (JNIEnv *env, jclass thiz,
         jbyteArray sample, jint sample_size,
         jbyteArray y, jint y_stride,
         jbyteArray u, jint u_stride,
         jbyteArray v, jint v_stride,
         jint crop_x, jint crop_y,
         jint src_width, jint src_height,
         jint crop_width, jint crop_height,
         jobject rotation, jint fourcc) {

    uint8 *sampleNative = (uint8 *) env->GetByteArrayElements(sample, 0);
    uint8 *yNative = (uint8 *) env->GetByteArrayElements(y, 0);
    uint8 *uNative = (uint8 *) env->GetByteArrayElements(u, 0);
    uint8 *vNative = (uint8 *) env->GetByteArrayElements(v, 0);
    uint32 sample_sizecNative = (uint32) sample_size;
    uint32 fourccNative = (uint32) fourcc;

    jint result = libyuv::ConvertToI420(
            sampleNative, sample_sizecNative,
            yNative, y_stride,
            uNative, u_stride,
            vNative, v_stride,
            crop_x, crop_y,
            src_width, src_height,
            crop_width, crop_height,
            getRotationMode(env, rotation),
            fourccNative);

    env->ReleaseByteArrayElements(sample, reinterpret_cast<jbyte *>(sampleNative), 0);
    env->ReleaseByteArrayElements(y, reinterpret_cast<jbyte *>(yNative), 0);
    env->ReleaseByteArrayElements(u, reinterpret_cast<jbyte *>(uNative), 0);
    env->ReleaseByteArrayElements(v, reinterpret_cast<jbyte *>(vNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_CopyPlane
 * Signature: ([BI[BIII)V
 */
JNIEXPORT void JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1CopyPlane
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray dst_y, jint dst_stride_y,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);

    libyuv::CopyPlane(
            src_yNative, src_stride_y,
            dst_yNative, dst_stride_y,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_CopyPlane_16
 * Signature: ([SI[SIII)V
 */
JNIEXPORT void JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1CopyPlane_116
        (JNIEnv *env, jclass thiz,
         jshortArray src_y, jint src_stride_y,
         jshortArray dst_y, jint dst_stride_y,
         jint width, jint height) {

    uint16 *src_yNative = (uint16 *) env->GetShortArrayElements(src_y, 0);
    uint16 *dst_yNative = (uint16 *) env->GetShortArrayElements(dst_y, 0);

    libyuv::CopyPlane_16(
            src_yNative, src_stride_y,
            dst_yNative, dst_stride_y,
            width, height);

    env->ReleaseShortArrayElements(src_y, reinterpret_cast<jshort *>(src_yNative), 0);
    env->ReleaseShortArrayElements(dst_y, reinterpret_cast<jshort *>(dst_yNative), 0);
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_I422Copy
 * Signature: ([BI[BI[BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1I422Copy
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::I422Copy(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_I444Copy
 * Signature: ([BI[BI[BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1I444Copy
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::I444Copy(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_I400ToI400
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1I400ToI400
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray dst_y, jint dst_stride_y,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);

    jint result = libyuv::I400ToI400(
            src_yNative, src_stride_y,
            dst_yNative, dst_stride_y,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_I420ToI400
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1I420ToI400
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_y, jint dst_stride_y,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);

    jint result = libyuv::I420ToI400(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_yNative, dst_stride_y,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_SplitUVPlane
 * Signature: ([BI[BI[BIII)V
 */
JNIEXPORT void JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1SplitUVPlane
        (JNIEnv *env, jclass thiz,
         jbyteArray src_uv, jint src_stride_uv,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_uvNative = (uint8 *) env->GetByteArrayElements(src_uv, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    libyuv::SplitUVPlane(
            src_uvNative, src_stride_uv,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_uv, reinterpret_cast<jbyte *>(src_uvNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_MergeUVPlane
 * Signature: ([BI[BI[BIII)V
 */
JNIEXPORT void JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1MergeUVPlane
        (JNIEnv *env, jclass thiz,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_uv, jint dst_stride_uv,
         jint width, jint height) {

    uint8 *dst_uvNative = (uint8 *) env->GetByteArrayElements(dst_uv, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);

    libyuv::MergeUVPlane(
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_uvNative, dst_stride_uv,
            width, height);

    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_uv, reinterpret_cast<jbyte *>(dst_uvNative), 0);
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_YUY2ToI422
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1YUY2ToI422
        (JNIEnv *env, jclass thiz,
         jbyteArray src_yuy2, jint src_stride_yuy2,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_yuy2Native = (uint8 *) env->GetByteArrayElements(src_yuy2, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::YUY2ToI422(
            src_yuy2Native, src_stride_yuy2,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_yuy2, reinterpret_cast<jbyte *>(src_yuy2Native), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_UYVYToI422
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1UYVYToI422
        (JNIEnv *env, jclass thiz,
         jbyteArray src_uyvy, jint src_stride_uyvy,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_uyvyNative = (uint8 *) env->GetByteArrayElements(src_uyvy, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::UYVYToI422(
            src_uyvyNative, src_stride_uyvy,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_uyvy, reinterpret_cast<jbyte *>(src_uyvyNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_YUY2ToY
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1YUY2ToY
        (JNIEnv *env, jclass thiz,
         jbyteArray src_yuy2, jint src_stride_yuy2,
         jbyteArray dst_y, jint dst_stride_y,
         jint width, jint height) {

    uint8 *src_yuy2Native = (uint8 *) env->GetByteArrayElements(src_yuy2, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);

    jint result = libyuv::YUY2ToY(
            src_yuy2Native, src_stride_yuy2,
            dst_yNative, dst_stride_y,
            width, height);

    env->ReleaseByteArrayElements(src_yuy2, reinterpret_cast<jbyte *>(src_yuy2Native), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_I400Mirror
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1I400Mirror
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray dst_y, jint dst_stride_y,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);

    jint result = libyuv::I400Mirror(
            src_yNative, src_stride_y,
            dst_yNative, dst_stride_y,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_I420Mirror
 * Signature: ([BI[BI[BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1I420Mirror
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::I420Mirror(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBMirror
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBMirror
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBMirror(
            src_argbNative, src_stride_argb,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBBlend
 * Signature: ([BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBBlend
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray src_argb1, jint src_stride_argb1,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *src_argb1Native = (uint8 *) env->GetByteArrayElements(src_argb1, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBBlend(
            src_argbNative, src_stride_argb,
            src_argb1Native, src_stride_argb1,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(src_argb1, reinterpret_cast<jbyte *>(src_argb1Native), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_BlendPlane
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1BlendPlane
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y0, jint src_stride_y0,
         jbyteArray src_y1, jint src_stride_y1,
         jbyteArray alpha, jint alpha_stride,
         jbyteArray dst_y, jint dst_stride_y,
         jint width, jint height) {

    uint8 *src_y0Native = (uint8 *) env->GetByteArrayElements(src_y0, 0);
    uint8 *src_y1Native = (uint8 *) env->GetByteArrayElements(src_y1, 0);
    uint8 *alphaNative = (uint8 *) env->GetByteArrayElements(alpha, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);

    jint result = libyuv::BlendPlane(
            src_y0Native, src_stride_y0,
            src_y1Native, src_stride_y1,
            alphaNative, alpha_stride,
            dst_yNative, dst_stride_y,
            width, height);

    env->ReleaseByteArrayElements(src_y0, reinterpret_cast<jbyte *>(src_y0Native), 0);
    env->ReleaseByteArrayElements(src_y1, reinterpret_cast<jbyte *>(src_y1Native), 0);
    env->ReleaseByteArrayElements(alpha, reinterpret_cast<jbyte *>(alphaNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_I420Blend
 * Signature: ([BI[BI[BI[BI[BI[BI[BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1I420Blend
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y0, jint src_stride_y0,
         jbyteArray src_u0, jint src_stride_u0,
         jbyteArray src_v0, jint src_stride_v0,
         jbyteArray src_y1, jint src_stride_y1,
         jbyteArray src_u1, jint src_stride_u1,
         jbyteArray src_v1, jint src_stride_v1,
         jbyteArray alpha, jint alpha_stride,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height) {

    uint8 *src_y0Native = (uint8 *) env->GetByteArrayElements(src_y0, 0);
    uint8 *src_u0Native = (uint8 *) env->GetByteArrayElements(src_u0, 0);
    uint8 *src_v0Native = (uint8 *) env->GetByteArrayElements(src_v0, 0);
    uint8 *src_y1Native = (uint8 *) env->GetByteArrayElements(src_y1, 0);
    uint8 *src_u1Native = (uint8 *) env->GetByteArrayElements(src_u1, 0);
    uint8 *src_v1Native = (uint8 *) env->GetByteArrayElements(src_v1, 0);
    uint8 *alphaNative = (uint8 *) env->GetByteArrayElements(alpha, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::I420Blend(
            src_y0Native, src_stride_y0,
            src_u0Native, src_stride_u0,
            src_v0Native, src_stride_v0,
            src_y1Native, src_stride_y1,
            src_u1Native, src_stride_u1,
            src_v1Native, src_stride_v1,
            alphaNative, alpha_stride,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height);

    env->ReleaseByteArrayElements(src_y0, reinterpret_cast<jbyte *>(src_y0Native), 0);
    env->ReleaseByteArrayElements(src_u0, reinterpret_cast<jbyte *>(src_u0Native), 0);
    env->ReleaseByteArrayElements(src_v0, reinterpret_cast<jbyte *>(src_v0Native), 0);
    env->ReleaseByteArrayElements(src_y1, reinterpret_cast<jbyte *>(src_y1Native), 0);
    env->ReleaseByteArrayElements(src_u1, reinterpret_cast<jbyte *>(src_u1Native), 0);
    env->ReleaseByteArrayElements(src_v1, reinterpret_cast<jbyte *>(src_v1Native), 0);
    env->ReleaseByteArrayElements(alpha, reinterpret_cast<jbyte *>(alphaNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBMultiply
 * Signature: ([BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBMultiply
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray src_argb1, jint src_stride_argb1,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *src_argb1Native = (uint8 *) env->GetByteArrayElements(src_argb1, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBMultiply(
            src_argbNative, src_stride_argb,
            src_argb1Native, src_stride_argb1,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(src_argb1, reinterpret_cast<jbyte *>(src_argb1Native), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBAdd
 * Signature: ([BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBAdd
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray src_argb1, jint src_stride_argb1,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *src_argb1Native = (uint8 *) env->GetByteArrayElements(src_argb1, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBAdd(
            src_argbNative, src_stride_argb,
            src_argb1Native, src_stride_argb1,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(src_argb1, reinterpret_cast<jbyte *>(src_argb1Native), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBSubtract
 * Signature: ([BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBSubtract
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray src_argb1, jint src_stride_argb1,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *src_argb1Native = (uint8 *) env->GetByteArrayElements(src_argb1, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBSubtract(
            src_argbNative, src_stride_argb,
            src_argb1Native, src_stride_argb1,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(src_argb1, reinterpret_cast<jbyte *>(src_argb1Native), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_I422ToRGBA
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1I422ToRGBA
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_rgba, jint dst_stride_rgba,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_rgbaNative = (uint8 *) env->GetByteArrayElements(dst_rgba, 0);

    jint result = libyuv::I422ToRGBA(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_rgbaNative, dst_stride_rgba,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_rgba, reinterpret_cast<jbyte *>(dst_rgbaNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_I422ToBGRA
 * Signature: ([BI[BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1I422ToBGRA
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_bgra, jint dst_stride_bgra,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_bgraNative = (uint8 *) env->GetByteArrayElements(dst_bgra, 0);

    jint result = libyuv::I422ToBGRA(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_bgraNative, dst_stride_bgra,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_bgra, reinterpret_cast<jbyte *>(dst_bgraNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_NV12ToRGB565
 * Signature: ([BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1NV12ToRGB565
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_uv, jint src_stride_uv,
         jbyteArray dst_rgb565, jint dst_stride_rgb565,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uvNative = (uint8 *) env->GetByteArrayElements(src_uv, 0);
    uint8 *dst_rgb565Native = (uint8 *) env->GetByteArrayElements(dst_rgb565, 0);

    jint result = libyuv::NV12ToRGB565(
            src_yNative, src_stride_y,
            src_uvNative, src_stride_uv,
            dst_rgb565Native, dst_stride_rgb565,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_uv, reinterpret_cast<jbyte *>(src_uvNative), 0);
    env->ReleaseByteArrayElements(dst_rgb565, reinterpret_cast<jbyte *>(dst_rgb565Native), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_RAWToRGB24
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1RAWToRGB24
        (JNIEnv *env, jclass thiz,
         jbyteArray src_raw, jint src_stride_raw,
         jbyteArray dst_rgb24, jint dst_stride_rgb24,
         jint width, jint height) {

    uint8 *src_rawNative = (uint8 *) env->GetByteArrayElements(src_raw, 0);
    uint8 *dst_rgb24Native = (uint8 *) env->GetByteArrayElements(dst_rgb24, 0);

    jint result = libyuv::RAWToRGB24(
            src_rawNative, src_stride_raw,
            dst_rgb24Native, dst_stride_rgb24,
            width, height);

    env->ReleaseByteArrayElements(src_raw, reinterpret_cast<jbyte *>(src_rawNative), 0);
    env->ReleaseByteArrayElements(dst_rgb24, reinterpret_cast<jbyte *>(dst_rgb24Native), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_SetPlane
 * Signature: ([BIIII)V
 */
JNIEXPORT void JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1SetPlane
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jint width, jint height,
         jint value) {
    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint32 valueNative = (uint32) value;

    libyuv::SetPlane(src_yNative, src_stride_y, width, height, valueNative);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_I420Rect
 * Signature: ([BI[BI[BIIIIIIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1I420Rect
        (JNIEnv *env, jclass thiz,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint x, jint y,
         jint width, jint height,
         jint value_y, jint value_u, jint value_v) {

    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::I420Rect(
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            x, y,
            width, height,
            value_y, value_u, value_v);

    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBRect
 * Signature: ([BIIIIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBRect
        (JNIEnv *env, jclass thiz,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint dst_x, jint dst_y,
         jint width, jint height,
         jint value) {

    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);
    uint32 valueNative = (uint32) value;

    jint result = libyuv::ARGBRect(
            dst_argbNative, dst_stride_argb,
            dst_x, dst_y,
            width, height,
            valueNative);

    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBAttenuate
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBAttenuate
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBAttenuate(
            src_argbNative, src_stride_argb,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBUnattenuate
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBUnattenuate
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBUnattenuate(
            src_argbNative, src_stride_argb,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBGrayTo
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBGrayTo
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBGrayTo(
            src_argbNative, src_stride_argb,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBGray
 * Signature: ([BIIIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBGray
        (JNIEnv *env, jclass thiz,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint dst_x, jint dst_y,
         jint width, jint height) {

    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBGray(
            dst_argbNative, dst_stride_argb,
            dst_x, dst_y,
            width, height);

    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBSepia
 * Signature: ([BIIIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBSepia
        (JNIEnv *env, jclass thiz,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint dst_x, jint dst_y,
         jint width, jint height) {

    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBSepia(
            dst_argbNative, dst_stride_argb,
            dst_x, dst_y,
            width, height);

    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBColorMatrix
 * Signature: ([BI[BILjava/lang/String  {
    return 0;
}II)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBColorMatrix
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_argb, jint dst_stride_argb,
         jbyteArray matrix_rgb,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);
    int8 *matrix_rgbNative = (int8 *) env->GetByteArrayElements(matrix_rgb, 0);

    jint result = libyuv::ARGBColorMatrix(
            src_argbNative, src_stride_argb,
            dst_argbNative, dst_stride_argb,
            matrix_rgbNative,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);
    env->ReleaseByteArrayElements(matrix_rgb, reinterpret_cast<jbyte *>(matrix_rgbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_RGBColorMatrix
 * Signature: ([BILjava/lang/String  {
    return 0;
}IIII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1RGBColorMatrix
        (JNIEnv *env, jclass thiz,
         jbyteArray dst_argb, jint dst_stride_argb,
         jbyteArray matrix_rgb,
         jint dst_x, jint dst_y,
         jint width, jint height) {

    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);
    int8 *matrix_rgbNative = (int8 *) env->GetByteArrayElements(matrix_rgb, 0);

    jint result = libyuv::RGBColorMatrix(
            dst_argbNative, dst_stride_argb,
            matrix_rgbNative,
            dst_x, dst_y,
            width, height);

    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);
    env->ReleaseByteArrayElements(matrix_rgb, reinterpret_cast<jbyte *>(matrix_rgbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBColorTable
 * Signature: ([BI[BIIII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBColorTable
        (JNIEnv *env, jclass thiz,
         jbyteArray dst_argb, jint dst_stride_argb,
         jbyteArray table_argb,
         jint dst_x, jint dst_y,
         jint width, jint height) {

    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);
    uint8 *table_argbNative = (uint8 *) env->GetByteArrayElements(table_argb, 0);

    jint result = libyuv::ARGBColorTable(
            dst_argbNative, dst_stride_argb,
            table_argbNative,
            dst_x, dst_y,
            width, height);

    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);
    env->ReleaseByteArrayElements(table_argb, reinterpret_cast<jbyte *>(table_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_RGBColorTable
 * Signature: ([BI[BIIII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1RGBColorTable
        (JNIEnv *env, jclass thiz,
         jbyteArray dst_argb, jint dst_stride_argb,
         jbyteArray table_argb,
         jint dst_x, jint dst_y,
         jint width, jint height) {

    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);
    uint8 *table_argbNative = (uint8 *) env->GetByteArrayElements(table_argb, 0);

    jint result = libyuv::RGBColorTable(
            dst_argbNative, dst_stride_argb,
            table_argbNative,
            dst_x, dst_y,
            width, height);

    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);
    env->ReleaseByteArrayElements(table_argb, reinterpret_cast<jbyte *>(table_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBQuantize
 * Signature: ([BIIIIIIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBQuantize
        (JNIEnv *env, jclass thiz,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint scale, jint interval_size, jint interval_offset,
         jint dst_x, jint dst_y, jint width, jint height) {

    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBQuantize(
            dst_argbNative, dst_stride_argb,
            scale, interval_size, interval_offset,
            dst_x, dst_y, width, height);

    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBComputeCumulativeSum
 * Signature: ([BI[IIII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBComputeCumulativeSum
        (JNIEnv *env, jclass thiz,
         jbyteArray dst_argb, jint dst_stride_argb,
         jintArray dst_cumsum, jint dst_stride32_cumsum,
         jint width, jint height) {

    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);
    int32 *dst_cumsumNative = (int32 *) env->GetIntArrayElements(dst_cumsum, 0);

    jint result = libyuv::ARGBComputeCumulativeSum(
            dst_argbNative, dst_stride_argb,
            dst_cumsumNative, dst_stride32_cumsum,
            width, height);

    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);
    env->ReleaseIntArrayElements(dst_cumsum, reinterpret_cast<jint *>(dst_cumsumNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBBlur
 * Signature: ([BI[BI[IIIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBBlur
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_argb, jint dst_stride_argb,
         jintArray dst_cumsum, jint dst_stride32_cumsum,
         jint width, jint height,
         jint radius) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);
    int32 *dst_cumsumNative = (int32 *) env->GetIntArrayElements(dst_cumsum, 0);

    jint result = libyuv::ARGBBlur(
            src_argbNative, src_stride_argb,
            dst_argbNative, dst_stride_argb,
            dst_cumsumNative, dst_stride32_cumsum,
            width, height, radius);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);
    env->ReleaseIntArrayElements(dst_cumsum, reinterpret_cast<jint *>(dst_cumsumNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBShade
 * Signature: ([BI[BIII[I)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBShade
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height,
         jint value) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);
    uint32 valueNative = (uint32) value;

    jint result = libyuv::ARGBShade(
            src_argbNative, src_stride_argb,
            dst_argbNative, dst_stride_argb,
            width, height, valueNative);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_InterpolatePlane
 * Signature: ([BI[BI[BIIII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1InterpolatePlane
        (JNIEnv *env, jclass thiz,
         jbyteArray src0, jint src_stride0,
         jbyteArray src1, jint src_stride1,
         jbyteArray dst, jint dst_stride,
         jint width, jint height,
         jint interpolation) {

    uint8 *src0Native = (uint8 *) env->GetByteArrayElements(src0, 0);
    uint8 *src1Native = (uint8 *) env->GetByteArrayElements(src1, 0);
    uint8 *dstNative = (uint8 *) env->GetByteArrayElements(dst, 0);

    jint result = libyuv::InterpolatePlane(
            src0Native, src_stride0,
            src1Native, src_stride1,
            dstNative, dst_stride,
            width, height, interpolation);

    env->ReleaseByteArrayElements(src0, reinterpret_cast<jbyte *>(src0Native), 0);
    env->ReleaseByteArrayElements(src1, reinterpret_cast<jbyte *>(src1Native), 0);
    env->ReleaseByteArrayElements(dst, reinterpret_cast<jbyte *>(dstNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBInterpolate
 * Signature: ([BI[BI[BIIII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBInterpolate
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb0, jint src_stride_argb0,
         jbyteArray src_argb1, jint src_stride_argb1,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height,
         jint interpolation) {

    uint8 *src_argb0Native = (uint8 *) env->GetByteArrayElements(src_argb0, 0);
    uint8 *src_argb1Native = (uint8 *) env->GetByteArrayElements(src_argb1, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBInterpolate(
            src_argb0Native, src_stride_argb0,
            src_argb1Native, src_stride_argb1,
            dst_argbNative, dst_stride_argb,
            width, height, interpolation);

    env->ReleaseByteArrayElements(src_argb0, reinterpret_cast<jbyte *>(src_argb0Native), 0);
    env->ReleaseByteArrayElements(src_argb1, reinterpret_cast<jbyte *>(src_argb1Native), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_I420Interpolate
 * Signature: ([BI[BI[BI[BI[BI[BI[BI[BI[BIIII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1I420Interpolate
        (JNIEnv *env, jclass thiz,
         jbyteArray src0_y, jint src0_stride_y,
         jbyteArray src0_u, jint src0_stride_u,
         jbyteArray src0_v, jint src0_stride_v,
         jbyteArray src1_y, jint src1_stride_y,
         jbyteArray src1_u, jint src1_stride_u,
         jbyteArray src1_v, jint src1_stride_v,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height, jint interpolation) {

    uint8 *src0_yNative = (uint8 *) env->GetByteArrayElements(src0_y, 0);
    uint8 *src0_uNative = (uint8 *) env->GetByteArrayElements(src0_u, 0);
    uint8 *src0_vNative = (uint8 *) env->GetByteArrayElements(src0_v, 0);
    uint8 *src1_yNative = (uint8 *) env->GetByteArrayElements(src1_y, 0);
    uint8 *src1_uNative = (uint8 *) env->GetByteArrayElements(src1_u, 0);
    uint8 *src1_vNative = (uint8 *) env->GetByteArrayElements(src1_v, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::I420Interpolate(
            src0_yNative, src0_stride_y,
            src0_uNative, src0_stride_u,
            src0_vNative, src0_stride_v,
            src1_yNative, src1_stride_y,
            src1_uNative, src1_stride_u,
            src1_vNative, src1_stride_v,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height, interpolation);

    env->ReleaseByteArrayElements(src0_y, reinterpret_cast<jbyte *>(src0_yNative), 0);
    env->ReleaseByteArrayElements(src0_u, reinterpret_cast<jbyte *>(src0_uNative), 0);
    env->ReleaseByteArrayElements(src0_v, reinterpret_cast<jbyte *>(src0_vNative), 0);
    env->ReleaseByteArrayElements(src1_y, reinterpret_cast<jbyte *>(src1_yNative), 0);
    env->ReleaseByteArrayElements(src1_u, reinterpret_cast<jbyte *>(src1_uNative), 0);
    env->ReleaseByteArrayElements(src1_v, reinterpret_cast<jbyte *>(src1_vNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBShuffle
 * Signature: ([BI[BI[BII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBShuffle
        (JNIEnv *env, jclass thiz,
         jbyteArray src_bgra, jint src_stride_bgra,
         jbyteArray dst_argb, jint dst_stride_argb,
         jbyteArray shuffler,
         jint width, jint height) {

    uint8 *src_bgraNative = (uint8 *) env->GetByteArrayElements(src_bgra, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);
    uint8 *shufflerNative = (uint8 *) env->GetByteArrayElements(shuffler, 0);

    jint result = libyuv::ARGBShuffle(
            src_bgraNative, src_stride_bgra,
            dst_argbNative, dst_stride_argb,
            shufflerNative,
            width, height);

    env->ReleaseByteArrayElements(src_bgra, reinterpret_cast<jbyte *>(src_bgraNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);
    env->ReleaseByteArrayElements(shuffler, reinterpret_cast<jbyte *>(shufflerNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBSobel
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBSobel
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBSobel(
            src_argbNative, src_stride_argb,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBSobelToPlane
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBSobelToPlane
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_y, jint dst_stride_y,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);

    jint result = libyuv::ARGBSobelToPlane(
            src_argbNative, src_stride_argb,
            dst_yNative, dst_stride_y,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBSobelXY
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBSobelXY
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBSobelXY(
            src_argbNative, src_stride_argb,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBPolynomial
 * Signature: ([BI[BI[FII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBPolynomial
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_argb, jint dst_stride_argb,
         jfloatArray poly,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);
    float *polyNative = (float *) env->GetFloatArrayElements(poly, 0);

    jint result = libyuv::ARGBPolynomial(
            src_argbNative, src_stride_argb,
            dst_argbNative, dst_stride_argb,
            polyNative,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);
    env->ReleaseFloatArrayElements(poly, reinterpret_cast<float *>(polyNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_HalfFloatPlane
 * Signature: ([SI[SIFII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1HalfFloatPlane
        (JNIEnv *env, jclass thiz,
         jshortArray src_y, jint src_stride_y,
         jshortArray dst_y, jint dst_stride_y,
         jfloat scale,
         jint width, jint height) {

    uint16 *src_yNative = (uint16 *) env->GetShortArrayElements(src_y, 0);
    uint16 *dst_yNative = (uint16 *) env->GetShortArrayElements(dst_y, 0);

    jint result = libyuv::HalfFloatPlane(
            src_yNative, src_stride_y,
            dst_yNative, dst_stride_y,
            scale,
            width, height);

    env->ReleaseShortArrayElements(src_y, reinterpret_cast<jshort *>(src_yNative), 0);
    env->ReleaseShortArrayElements(dst_y, reinterpret_cast<jshort *>(dst_yNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBLumaColorTable
 * Signature: ([BI[BI[BII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBLumaColorTable
        (JNIEnv *env, jclass thiz,
         jbyteArray src_bgra, jint src_stride_bgra,
         jbyteArray dst_argb, jint dst_stride_argb,
         jbyteArray luma,
         jint width, jint height) {

    uint8 *src_bgraNative = (uint8 *) env->GetByteArrayElements(src_bgra, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);
    uint8 *lumaNative = (uint8 *) env->GetByteArrayElements(luma, 0);

    jint result = libyuv::ARGBLumaColorTable(
            src_bgraNative, src_stride_bgra,
            dst_argbNative, dst_stride_argb,
            lumaNative,
            width, height);

    env->ReleaseByteArrayElements(src_bgra, reinterpret_cast<jbyte *>(src_bgraNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);
    env->ReleaseByteArrayElements(luma, reinterpret_cast<jbyte *>(lumaNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBCopyAlpha
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBCopyAlpha
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBCopyAlpha(
            src_argbNative, src_stride_argb,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBExtractAlpha
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBExtractAlpha
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_a, jint dst_stride_a,
         jint width, jint height) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_aNative = (uint8 *) env->GetByteArrayElements(dst_a, 0);

    jint result = libyuv::ARGBExtractAlpha(
            src_argbNative, src_stride_argb,
            dst_aNative, dst_stride_a,
            width, height);

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_a, reinterpret_cast<jbyte *>(dst_aNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_ARGBCopyYToAlpha
 * Signature: ([BI[BIII)I
 */
JNIEXPORT jint JNICALL
Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1ARGBCopyYToAlpha
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBCopyYToAlpha(
            src_yNative, src_stride_y,
            dst_argbNative, dst_stride_argb,
            width, height);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_YUY2ToNV12
 * Signature: ([BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1YUY2ToNV12
        (JNIEnv *env, jclass thiz,
         jbyteArray src_yuy2, jint src_stride_yuy2,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_uv, jint dst_stride_uv,
         jint width, jint height) {

    uint8 *src_yuy2Native = (uint8 *) env->GetByteArrayElements(src_yuy2, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uvNative = (uint8 *) env->GetByteArrayElements(dst_uv, 0);

    jint result = libyuv::YUY2ToNV12(
            src_yuy2Native, src_stride_yuy2,
            dst_yNative, dst_stride_y,
            dst_uvNative, dst_stride_uv,
            width, height);

    env->ReleaseByteArrayElements(src_yuy2, reinterpret_cast<jbyte *>(src_yuy2Native), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_uv, reinterpret_cast<jbyte *>(dst_uvNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Planar_functions_UYVYToNV12
 * Signature: ([BI[BI[BIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Planar_1functions_1UYVYToNV12
        (JNIEnv *env, jclass thiz,
         jbyteArray src_uyvy, jint src_stride_uyvy,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_uv, jint dst_stride_uv,
         jint width, jint height) {

    uint8 *src_uyvyNative = (uint8 *) env->GetByteArrayElements(src_uyvy, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uvNative = (uint8 *) env->GetByteArrayElements(dst_uv, 0);

    jint result = libyuv::UYVYToNV12(
            src_uyvyNative, src_stride_uyvy,
            dst_yNative, dst_stride_y,
            dst_uvNative, dst_stride_uv,
            width, height);

    env->ReleaseByteArrayElements(src_uyvy, reinterpret_cast<jbyte *>(src_uyvyNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_uv, reinterpret_cast<jbyte *>(dst_uvNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Rotate_TransposePlane
 * Signature: ([BI[BIII)V
 */
JNIEXPORT void JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Rotate_1TransposePlane
        (JNIEnv *env, jclass thiz,
         jbyteArray src, jint src_stride,
         jbyteArray dst, jint dst_stride,
         jint width, jint height) {

    uint8 *srcNative = (uint8 *) env->GetByteArrayElements(src, 0);
    uint8 *dstNative = (uint8 *) env->GetByteArrayElements(dst, 0);

    libyuv::TransposePlane(
            srcNative, src_stride,
            dstNative, dst_stride,
            width, height);

    env->ReleaseByteArrayElements(src, reinterpret_cast<jbyte *>(srcNative), 0);
    env->ReleaseByteArrayElements(dst, reinterpret_cast<jbyte *>(dstNative), 0);
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Rotate_RotatePlane90
 * Signature: ([BI[BIII)V
 */
JNIEXPORT void JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Rotate_1RotatePlane90
        (JNIEnv *env, jclass thiz,
         jbyteArray src, jint src_stride,
         jbyteArray dst, jint dst_stride,
         jint width, jint height) {

    uint8 *srcNative = (uint8 *) env->GetByteArrayElements(src, 0);
    uint8 *dstNative = (uint8 *) env->GetByteArrayElements(dst, 0);

    libyuv::RotatePlane90(
            srcNative, src_stride,
            dstNative, dst_stride,
            width, height);

    env->ReleaseByteArrayElements(src, reinterpret_cast<jbyte *>(srcNative), 0);
    env->ReleaseByteArrayElements(dst, reinterpret_cast<jbyte *>(dstNative), 0);
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Rotate_RotatePlane270
 * Signature: ([BI[BIII)V
 */
JNIEXPORT void JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Rotate_1RotatePlane270
        (JNIEnv *env, jclass thiz,
         jbyteArray src, jint src_stride,
         jbyteArray dst, jint dst_stride,
         jint width, jint height) {

    uint8 *srcNative = (uint8 *) env->GetByteArrayElements(src, 0);
    uint8 *dstNative = (uint8 *) env->GetByteArrayElements(dst, 0);

    libyuv::RotatePlane270(
            srcNative, src_stride,
            dstNative, dst_stride,
            width, height);

    env->ReleaseByteArrayElements(src, reinterpret_cast<jbyte *>(srcNative), 0);
    env->ReleaseByteArrayElements(dst, reinterpret_cast<jbyte *>(dstNative), 0);
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Rotate_RotatePlane180
 * Signature: ([BI[BIII)V
 */
JNIEXPORT void JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Rotate_1RotatePlane180
        (JNIEnv *env, jclass thiz,
         jbyteArray src, jint src_stride,
         jbyteArray dst, jint dst_stride,
         jint width, jint height) {

    uint8 *srcNative = (uint8 *) env->GetByteArrayElements(src, 0);
    uint8 *dstNative = (uint8 *) env->GetByteArrayElements(dst, 0);

    libyuv::RotatePlane180(
            srcNative, src_stride,
            dstNative, dst_stride,
            width, height);

    env->ReleaseByteArrayElements(src, reinterpret_cast<jbyte *>(srcNative), 0);
    env->ReleaseByteArrayElements(dst, reinterpret_cast<jbyte *>(dstNative), 0);
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Rotate_TransposeUV
 * Signature: ([BI[BI[BIII)V
 */
JNIEXPORT void JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Rotate_1TransposeUV
        (JNIEnv *env, jclass thiz,
         jbyteArray src, jint src_stride,
         jbyteArray dst_a, jint dst_stride_a,
         jbyteArray dst_b, jint dst_stride_b,
         jint width, jint height) {

    uint8 *srcNative = (uint8 *) env->GetByteArrayElements(src, 0);
    uint8 *dst_aNative = (uint8 *) env->GetByteArrayElements(dst_a, 0);
    uint8 *dst_bNative = (uint8 *) env->GetByteArrayElements(dst_b, 0);

    libyuv::TransposeUV(
            srcNative, src_stride,
            dst_aNative, dst_stride_a,
            dst_bNative, dst_stride_b,
            width, height);

    env->ReleaseByteArrayElements(src, reinterpret_cast<jbyte *>(srcNative), 0);
    env->ReleaseByteArrayElements(dst_a, reinterpret_cast<jbyte *>(dst_aNative), 0);
    env->ReleaseByteArrayElements(dst_b, reinterpret_cast<jbyte *>(dst_bNative), 0);
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Rotate_RotateUV90
 * Signature: ([BI[BI[BIII)V
 */
JNIEXPORT void JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Rotate_1RotateUV90
        (JNIEnv *env, jclass thiz,
         jbyteArray src, jint src_stride,
         jbyteArray dst_a, jint dst_stride_a,
         jbyteArray dst_b, jint dst_stride_b,
         jint width, jint height) {

    uint8 *srcNative = (uint8 *) env->GetByteArrayElements(src, 0);
    uint8 *dst_aNative = (uint8 *) env->GetByteArrayElements(dst_a, 0);
    uint8 *dst_bNative = (uint8 *) env->GetByteArrayElements(dst_b, 0);

    libyuv::RotateUV90(
            srcNative, src_stride,
            dst_aNative, dst_stride_a,
            dst_bNative, dst_stride_b,
            width, height);

    env->ReleaseByteArrayElements(src, reinterpret_cast<jbyte *>(srcNative), 0);
    env->ReleaseByteArrayElements(dst_a, reinterpret_cast<jbyte *>(dst_aNative), 0);
    env->ReleaseByteArrayElements(dst_b, reinterpret_cast<jbyte *>(dst_bNative), 0);
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Rotate_RotateUV270
 * Signature: ([BI[BI[BIII)V
 */
JNIEXPORT void JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Rotate_1RotateUV270
        (JNIEnv *env, jclass thiz,
         jbyteArray src, jint src_stride,
         jbyteArray dst_a, jint dst_stride_a,
         jbyteArray dst_b, jint dst_stride_b,
         jint width, jint height) {

    uint8 *srcNative = (uint8 *) env->GetByteArrayElements(src, 0);
    uint8 *dst_aNative = (uint8 *) env->GetByteArrayElements(dst_a, 0);
    uint8 *dst_bNative = (uint8 *) env->GetByteArrayElements(dst_b, 0);

    libyuv::RotateUV270(
            srcNative, src_stride,
            dst_aNative, dst_stride_a,
            dst_bNative, dst_stride_b,
            width, height);

    env->ReleaseByteArrayElements(src, reinterpret_cast<jbyte *>(srcNative), 0);
    env->ReleaseByteArrayElements(dst_a, reinterpret_cast<jbyte *>(dst_aNative), 0);
    env->ReleaseByteArrayElements(dst_b, reinterpret_cast<jbyte *>(dst_bNative), 0);
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Rotate_RotateUV180
 * Signature: ([BI[BI[BIII)V
 */
JNIEXPORT void JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Rotate_1RotateUV180
        (JNIEnv *env, jclass thiz,
         jbyteArray src, jint src_stride,
         jbyteArray dst_a, jint dst_stride_a,
         jbyteArray dst_b, jint dst_stride_b,
         jint width, jint height) {

    uint8 *srcNative = (uint8 *) env->GetByteArrayElements(src, 0);
    uint8 *dst_aNative = (uint8 *) env->GetByteArrayElements(dst_a, 0);
    uint8 *dst_bNative = (uint8 *) env->GetByteArrayElements(dst_b, 0);

    libyuv::RotateUV180(
            srcNative, src_stride,
            dst_aNative, dst_stride_a,
            dst_bNative, dst_stride_b,
            width, height);

    env->ReleaseByteArrayElements(src, reinterpret_cast<jbyte *>(srcNative), 0);
    env->ReleaseByteArrayElements(dst_a, reinterpret_cast<jbyte *>(dst_aNative), 0);
    env->ReleaseByteArrayElements(dst_b, reinterpret_cast<jbyte *>(dst_bNative), 0);
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Rotate_RotatePlane
 * Signature: ([BI[BIIILcom/wpf/library/libyuv_android/Data/RotationMode  {
    return 0;
})I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Rotate_1RotatePlane
        (JNIEnv *env, jclass thiz,
         jbyteArray src, jint src_stride,
         jbyteArray dst, jint dst_stride,
         jint width, jint height,
         jobject rotation) {

    uint8 *srcNative = (uint8 *) env->GetByteArrayElements(src, 0);
    uint8 *dstNative = (uint8 *) env->GetByteArrayElements(dst, 0);

    jint result = libyuv::RotatePlane(
            srcNative, src_stride,
            dstNative, dst_stride,
            width, height,
            getRotationMode(env, rotation));

    env->ReleaseByteArrayElements(src, reinterpret_cast<jbyte *>(srcNative), 0);
    env->ReleaseByteArrayElements(dst, reinterpret_cast<jbyte *>(dstNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Rotate_I420Rotate
 * Signature: ([BI[BI[BI[BI[BI[BIIILcom/wpf/library/libyuv_android/Data/RotationMode  {
    return 0;
})I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Rotate_1I420Rotate
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height,
         jobject mode) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::I420Rotate(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height,
            getRotationMode(env, mode));

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Rotate_NV12ToI420Rotate
 * Signature: ([BI[BI[BI[BI[BIIILcom/wpf/library/libyuv_android/Data/RotationMode  {
    return 0;
})I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Rotate_1NV12ToI420Rotate
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_uv, jint src_stride_uv,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint width, jint height,
         jobject mode) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uvNative = (uint8 *) env->GetByteArrayElements(src_uv, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::NV12ToI420Rotate(
            src_yNative, src_stride_y,
            src_uvNative, src_stride_uv,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            width, height,
            getRotationMode(env, mode));

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_uv, reinterpret_cast<jbyte *>(src_uvNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);
    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Rotate_ARGB_ARGBRotate
 * Signature: ([BI[BIIILcom/wpf/library/libyuv_android/Data/RotationMode  {
    return 0;
})I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Rotate_1ARGB_1ARGBRotate
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint width, jint height,
         jobject rotation) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBRotate(
            src_argbNative,src_stride_argb,
            dst_argbNative,dst_stride_argb,
            width,height,
            getRotationMode(env,rotation));

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Scale_ScalePlane
 * Signature: ([BIII[BIIILcom/wpf/library/libyuv_android/Data/FilterMode  {
    return 0;
})V
 */
JNIEXPORT void JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Scale_1ScalePlane
        (JNIEnv *env, jclass thiz,
         jbyteArray src, jint src_stride,
         jint src_width, jint src_height,
         jbyteArray dst, jint dst_stride,
         jint dst_width, jint dst_height,
         jobject filtering) {

    uint8 *srcNative = (uint8 *) env->GetByteArrayElements(src, 0);
    uint8 *dstNative = (uint8 *) env->GetByteArrayElements(dst, 0);

    libyuv::ScalePlane(
            srcNative,src_stride,
            src_width,src_height,
            dstNative,dst_stride,
            dst_width,dst_height,
            getFilterMode(env,filtering));

    env->ReleaseByteArrayElements(src, reinterpret_cast<jbyte *>(srcNative), 0);
    env->ReleaseByteArrayElements(dst, reinterpret_cast<jbyte *>(dstNative), 0);
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Scale_ScalePlane_16
 * Signature: ([SIII[SIIILcom/wpf/library/libyuv_android/Data/FilterMode  {
    return 0;
})V
 */
JNIEXPORT void JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Scale_1ScalePlane_116
        (JNIEnv *env, jclass thiz,
         jshortArray src, jint src_stride,
         jint src_width, jint src_height,
         jshortArray dst, jint dst_stride,
         jint dst_width, jint dst_height,
         jobject filtering) {

    uint16 *srcNative = (uint16 *) env->GetShortArrayElements(src, 0);
    uint16 *dstNative = (uint16 *) env->GetShortArrayElements(dst, 0);

    libyuv::ScalePlane_16(
            srcNative,src_stride,
            src_width,src_height,
            dstNative,dst_stride,
            dst_width,dst_height,
            getFilterMode(env,filtering));

    env->ReleaseShortArrayElements(src, reinterpret_cast<jshort *>(srcNative), 0);
    env->ReleaseShortArrayElements(dst, reinterpret_cast<jshort *>(dstNative), 0);
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Scale_I420Scale
 * Signature: ([BI[BI[BIII[BI[BI[BIIILcom/wpf/library/libyuv_android/Data/FilterMode  {
    return 0;
})I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Scale_1I420Scale
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jint src_width, jint src_height,
         jbyteArray dst_y, jint dst_stride_y,
         jbyteArray dst_u, jint dst_stride_u,
         jbyteArray dst_v, jint dst_stride_v,
         jint dst_width, jint dst_height,
         jobject filtering) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::I420Scale(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            src_width, src_height,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            dst_width, dst_height,
            getFilterMode(env, filtering));

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Scale_I420Scale_16
 * Signature: ([SI[SI[SIII[SI[SI[SIIILcom/wpf/library/libyuv_android/Data/FilterMode  {
    return 0;
})I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Scale_1I420Scale_116
        (JNIEnv *env, jclass thiz,
         jshortArray src_y, jint src_stride_y,
         jshortArray src_u, jint src_stride_u,
         jshortArray src_v, jint src_stride_v,
         jint src_width, jint src_height,
         jshortArray dst_y, jint dst_stride_y,
         jshortArray dst_u, jint dst_stride_u,
         jshortArray dst_v, jint dst_stride_v,
         jint dst_width, jint dst_height,
         jobject filtering) {

    uint16 *src_yNative = (uint16 *) env->GetShortArrayElements(src_y, 0);
    uint16 *src_uNative = (uint16 *) env->GetShortArrayElements(src_u, 0);
    uint16 *src_vNative = (uint16 *) env->GetShortArrayElements(src_v, 0);
    uint16 *dst_yNative = (uint16 *) env->GetShortArrayElements(dst_y, 0);
    uint16 *dst_uNative = (uint16 *) env->GetShortArrayElements(dst_u, 0);
    uint16 *dst_vNative = (uint16 *) env->GetShortArrayElements(dst_v, 0);

    jint result = libyuv::I420Scale_16(
            src_yNative, src_stride_y,
            src_uNative, src_stride_u,
            src_vNative, src_stride_v,
            src_width, src_height,
            dst_yNative, dst_stride_y,
            dst_uNative, dst_stride_u,
            dst_vNative, dst_stride_v,
            dst_width, dst_height,
            getFilterMode(env, filtering));

    env->ReleaseShortArrayElements(src_y, reinterpret_cast<jshort *>(src_yNative), 0);
    env->ReleaseShortArrayElements(src_u, reinterpret_cast<jshort *>(src_uNative), 0);
    env->ReleaseShortArrayElements(src_v, reinterpret_cast<jshort *>(src_vNative), 0);
    env->ReleaseShortArrayElements(dst_y, reinterpret_cast<jshort *>(dst_yNative), 0);
    env->ReleaseShortArrayElements(dst_u, reinterpret_cast<jshort *>(dst_uNative), 0);
    env->ReleaseShortArrayElements(dst_v, reinterpret_cast<jshort *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Scale_Scale
 * Signature: ([B[B[BIIIII[B[B[BIIIIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Scale_1Scale
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jbyteArray src_u, jbyteArray src_v,
         jint src_stride_y, jint src_stride_u, jint src_stride_v,
         jint src_width, jint src_height,
         jbyteArray dst_y, jbyteArray dst_u, jbyteArray dst_v,
         jint dst_stride_y, jint dst_stride_u, jint dst_stride_v,
         jint dst_width, jint dst_height,
         int interpolate) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_yNative = (uint8 *) env->GetByteArrayElements(dst_y, 0);
    uint8 *dst_uNative = (uint8 *) env->GetByteArrayElements(dst_u, 0);
    uint8 *dst_vNative = (uint8 *) env->GetByteArrayElements(dst_v, 0);

    jint result = libyuv::Scale(
            src_yNative, src_uNative, src_vNative,
            src_stride_y, src_stride_u, src_stride_v,
            src_width, src_height,
            dst_yNative, dst_uNative, dst_vNative,
            dst_stride_y, dst_stride_u, dst_stride_v,
            dst_width, dst_height,
            interpolate);

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_y, reinterpret_cast<jbyte *>(dst_yNative), 0);
    env->ReleaseByteArrayElements(dst_u, reinterpret_cast<jbyte *>(dst_uNative), 0);
    env->ReleaseByteArrayElements(dst_v, reinterpret_cast<jbyte *>(dst_vNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Scale_ScaleOffset
 * Signature: ([BII[BIIII)I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Scale_1ScaleOffset
        (JNIEnv *env, jclass thiz,
         jbyteArray src, jint src_width, jint src_height,
         jbyteArray dst , jint dst_width, jint dst_height,
         jint dst_yoffset, jint interpolate) {

    uint8 *srcNative = (uint8 *) env->GetByteArrayElements(src, 0);
    uint8 *dstNative = (uint8 *) env->GetByteArrayElements(dst, 0);

    jint result = libyuv::ScaleOffset(
            srcNative,src_width,src_height,
            dstNative,dst_width,dst_height,
            dst_yoffset,interpolate);

    env->ReleaseByteArrayElements(src, reinterpret_cast<jbyte *>(srcNative), 0);
    env->ReleaseByteArrayElements(dst, reinterpret_cast<jbyte *>(dstNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Scale_ARGB_ARGBScaleClip
 * Signature: ([BIII[BIIIIIIILcom/wpf/library/libyuv_android/Data/FilterMode  {
    return 0;
})I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Scale_1ARGB_1ARGBScaleClip
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jint src_width, jint src_height,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint dst_width, jint dst_height,
         jint clip_x, jint clip_y,
         jint clip_width, jint clip_height,
         jobject filtering) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBScaleClip(
            src_argbNative,src_stride_argb,
            src_width,src_height,
            dst_argbNative,dst_stride_argb,
            dst_width,dst_height,
            clip_x,clip_y,
            clip_width,clip_height,
            getFilterMode(env,filtering));

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Scale_ARGB_ARGBScale
 * Signature: ([BIII[BIIILcom/wpf/library/libyuv_android/Data/FilterMode  {
    return 0;
})I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Scale_1ARGB_1ARGBScale
        (JNIEnv *env, jclass thiz,
         jbyteArray src_argb, jint src_stride_argb,
         jint src_width, jint src_height,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint dst_width, jint dst_height,
         jobject filtering) {

    uint8 *src_argbNative = (uint8 *) env->GetByteArrayElements(src_argb, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);

    jint result = libyuv::ARGBScale(
            src_argbNative,src_stride_argb,
            src_width,src_height,
            dst_argbNative,dst_stride_argb,
            dst_width,dst_height,
            getFilterMode(env,filtering));

    env->ReleaseByteArrayElements(src_argb, reinterpret_cast<jbyte *>(src_argbNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

/*
 * Class:     com_wpf_library_libyuv_android_YUVUtils
 * Method:    Scale_ARGB_YUVToARGBScaleClip
 * Signature: ([BI[BI[BIIII[BIIIIIIIILcom/wpf/library/libyuv_android/Data/FilterMode  {
    return 0;
})I
 */
JNIEXPORT jint JNICALL Java_com_wpf_library_libyuv_1android_YUVUtils_Scale_1ARGB_1YUVToARGBScaleClip
        (JNIEnv *env, jclass thiz,
         jbyteArray src_y, jint src_stride_y,
         jbyteArray src_u, jint src_stride_u,
         jbyteArray src_v, jint src_stride_v,
         jint src_fourcc,
         jint src_width, jint src_height,
         jbyteArray dst_argb, jint dst_stride_argb,
         jint dst_fourcc,
         jint dst_width, jint dst_height,
         jint clip_x, jint clip_y, jint clip_width, jint clip_height,
         jobject filtering) {

    uint8 *src_yNative = (uint8 *) env->GetByteArrayElements(src_y, 0);
    uint8 *src_uNative = (uint8 *) env->GetByteArrayElements(src_u, 0);
    uint8 *src_vNative = (uint8 *) env->GetByteArrayElements(src_v, 0);
    uint8 *dst_argbNative = (uint8 *) env->GetByteArrayElements(dst_argb, 0);
    uint32 src_fourccNative = (uint32) src_fourcc;
    uint32 dst_fourccNative = (uint32) dst_fourcc;

    jint result = libyuv::YUVToARGBScaleClip(
            src_yNative,src_stride_y,
            src_uNative,src_stride_u,
            src_vNative,src_stride_v,
            src_fourccNative,
            src_width,src_height,
            dst_argbNative,dst_stride_argb,
            dst_fourccNative,
            dst_width,dst_height,
            clip_x,clip_y,clip_width,clip_height,
            getFilterMode(env,filtering));

    env->ReleaseByteArrayElements(src_y, reinterpret_cast<jbyte *>(src_yNative), 0);
    env->ReleaseByteArrayElements(src_u, reinterpret_cast<jbyte *>(src_uNative), 0);
    env->ReleaseByteArrayElements(src_v, reinterpret_cast<jbyte *>(src_vNative), 0);
    env->ReleaseByteArrayElements(dst_argb, reinterpret_cast<jbyte *>(dst_argbNative), 0);

    return result;
}

JNIEXPORT libyuv::FilterMode JNICALL getFilterMode(JNIEnv *env, jobject filtering) {
    libyuv::FilterMode filterMode = libyuv::kFilterNone;
    jclass enumClass = env->GetObjectClass(filtering);

    if (enumClass != NULL) {
        jmethodID getVal = env->GetMethodID(enumClass, "getValue", "()I");
        jint value = (jint) env->CallIntMethod(filtering, getVal);
        switch (value) {
            case 0:
                filterMode = libyuv::kFilterNone;
                break;
            case 1:
                filterMode = libyuv::kFilterLinear;
                break;
            case 2:
                filterMode = libyuv::kFilterBilinear;
                break;
            case 3:
                filterMode = libyuv::kFilterBox;
                break;
            default:
                filterMode = libyuv::kFilterNone;
                break;
        }
    }
    return filterMode;
}

JNIEXPORT libyuv::RotationMode JNICALL getRotationMode(JNIEnv *env, jobject rotation) {
    jclass enumClass = env->GetObjectClass(rotation);
    libyuv::RotationMode rotationMode = libyuv::kRotate0;
    if (enumClass != NULL) {
        jmethodID getVal = env->GetMethodID(enumClass, "getValue", "()I");
        jint value = (jint) env->CallIntMethod(rotation, getVal);
        switch (value) {
            case 0:
                rotationMode = libyuv::kRotate0;
                break;
            case 90:
                rotationMode = libyuv::kRotate90;
                break;
            case 180:
                rotationMode = libyuv::kRotate180;
                break;
            case 270:
                rotationMode = libyuv::kRotate270;
                break;
            default:
                rotationMode = libyuv::kRotate0;
                break;
        }
    }
    return rotationMode;
}