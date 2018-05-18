package com.wpf.library.libyuv_android;

import com.wpf.library.libyuv_android.Data.ARGBBlendRow;
import com.wpf.library.libyuv_android.Data.FilterMode;
import com.wpf.library.libyuv_android.Data.RotationMode;

/**
 * Created by 王朋飞 on 2018/5/7.
 */
public class YUVUtils {

    static {
        System.loadLibrary("yuv");
    }

    private static YUVUtils yuvUtils;

    public static YUVUtils instance() {
        if (yuvUtils == null) {
            yuvUtils = new YUVUtils();
        }
        return yuvUtils;
    }

    public native int Compare_HashDjb2(byte[] src, long count, int seed);

    public native int Compare_ARGBDetect(byte[] argb, int stride_argb, int width, int height);

    public native long Compare_ComputeSumSquareError(byte[] src_a, byte[] src_b, int count);

    public native long Compare_ComputeSumSquareErrorPlane(byte[] src_a, int stride_a,
                                                          byte[] src_b, int stride_b,
                                                          int width, int height);

    public native long Compare_SumSquareErrorToPsnr(long sse, long count);

    public native long Compare_CalcFramePsnr(byte[] src_a, int stride_a,
                                             byte[] src_b, int stride_b,
                                             int width, int height);

    public native long Compare_I420Psnr(byte[] src_y_a, int stride_y_a,
                                        byte[] src_u_a, int stride_u_a,
                                        byte[] src_v_a, int stride_v_a,
                                        byte[] src_y_b, int stride_y_b,
                                        byte[] src_u_b, int stride_u_b,
                                        byte[] src_v_b, int stride_v_b,
                                        int width, int height);

    public native long Compare_CalcFrameSsim(byte[] src_a, int stride_a,
                                             byte[] src_b, int stride_b,
                                             int width, int height);

    public native long Compare_I420Ssim(byte[] src_y_a, int stride_y_a,
                                        byte[] src_u_a, int stride_u_a,
                                        byte[] src_v_a, int stride_v_a,
                                        byte[] src_y_b, int stride_y_b,
                                        byte[] src_u_b, int stride_u_b,
                                        byte[] src_v_b, int stride_v_b,
                                        int width, int height);

    //TODO(fbarchard): Use Scale plane which supports mirroring, but ensure
    public native int Convert_I420Copy(byte[] src_y, int src_stride_y,
                                       byte[] src_u, int src_stride_u,
                                       byte[] src_v, int src_stride_v,
                                       byte[] dst_y, int dst_stride_y,
                                       byte[] dst_u, int dst_stride_u,
                                       byte[] dst_v, int dst_stride_v,
                                       int width, int height);

    public native int Convert_I422ToI420(byte[] src_y, int src_stride_y,
                                         byte[] src_u, int src_stride_u,
                                         byte[] src_v, int src_stride_v,
                                         byte[] dst_y, int dst_stride_y,
                                         byte[] dst_u, int dst_stride_u,
                                         byte[] dst_v, int dst_stride_v,
                                         int width, int height);

    public native int Convert_I444ToI420(byte[] src_y, int src_stride_y,
                                         byte[] src_u, int src_stride_u,
                                         byte[] src_v, int src_stride_v,
                                         byte[] dst_y, int dst_stride_y,
                                         byte[] dst_u, int dst_stride_u,
                                         byte[] dst_v, int dst_stride_v,
                                         int width, int height);

    public native int Convert_I400ToI420(byte[] src_y, int src_stride_y,
                                         byte[] dst_y, int dst_stride_y,
                                         byte[] dst_u, int dst_stride_u,
                                         byte[] dst_v, int dst_stride_v,
                                         int width, int height);

    public native int Convert_NV12ToI420(byte[] src_y, int src_stride_y,
                                         byte[] src_uv, int src_stride_uv,
                                         byte[] dst_y, int dst_stride_y,
                                         byte[] dst_u, int dst_stride_u,
                                         byte[] dst_v, int dst_stride_v,
                                         int width, int height);

    public native int Convert_NV21ToI420(byte[] src_y, int src_stride_y,
                                         byte[] src_vu, int src_stride_vu,
                                         byte[] dst_y, int dst_stride_y,
                                         byte[] dst_u, int dst_stride_u,
                                         byte[] dst_v, int dst_stride_v,
                                         int width, int height);

    public native int Convert_M420ToI420(byte[] src_m420, int src_stride_m420,
                                         byte[] dst_y, int dst_stride_y,
                                         byte[] dst_u, int dst_stride_u,
                                         byte[] dst_v, int dst_stride_v,
                                         int width, int height);

    public native int Convert_YUY2ToI420(byte[] src_yuy2, int src_stride_yuy2,
                                         byte[] dst_y, int dst_stride_y,
                                         byte[] dst_u, int dst_stride_u,
                                         byte[] dst_v, int dst_stride_v,
                                         int width, int height);

    public native int Convert_UYVYToI420(byte[] src_uyvy, int src_stride_uyvy,
                                         byte[] dst_y, int dst_stride_y,
                                         byte[] dst_u, int dst_stride_u,
                                         byte[] dst_v, int dst_stride_v,
                                         int width, int height);

    public native int Convert_ARGBToI420(byte[] src_argb, int src_stride_argb,
                                         byte[] dst_y, int dst_stride_y,
                                         byte[] dst_u, int dst_stride_u,
                                         byte[] dst_v, int dst_stride_v,
                                         int width, int height);

    public native int Convert_BGRAToI420(byte[] src_bgra, int src_stride_bgra,
                                         byte[] dst_y, int dst_stride_y,
                                         byte[] dst_u, int dst_stride_u,
                                         byte[] dst_v, int dst_stride_v,
                                         int width, int height);

    public native int Convert_ABGRToI420(byte[] src_abgr, int src_stride_abgr,
                                         byte[] dst_y, int dst_stride_y,
                                         byte[] dst_u, int dst_stride_u,
                                         byte[] dst_v, int dst_stride_v,
                                         int width, int height);

    public native int Convert_RGBAToI420(byte[] src_rgba, int src_stride_rgba,
                                         byte[] dst_y, int dst_stride_y,
                                         byte[] dst_u, int dst_stride_u,
                                         byte[] dst_v, int dst_stride_v,
                                         int width, int height);

    public native int Convert_RGB24ToI420(byte[] src_rgb24, int src_stride_rgb24,
                                          byte[] dst_y, int dst_stride_y,
                                          byte[] dst_u, int dst_stride_u,
                                          byte[] dst_v, int dst_stride_v,
                                          int width, int height);

    public native int Convert_RAWToI420(byte[] src_raw, int src_stride_raw,
                                        byte[] dst_y, int dst_stride_y,
                                        byte[] dst_u, int dst_stride_u,
                                        byte[] dst_v, int dst_stride_v,
                                        int width, int height);

    public native int Convert_RGB565ToI420(byte[] src_rgb565, int src_stride_rgb565,
                                           byte[] dst_y, int dst_stride_y,
                                           byte[] dst_u, int dst_stride_u,
                                           byte[] dst_v, int dst_stride_v,
                                           int width, int height);

    public native int Convert_ARGB1555ToI420(byte[] src_argb1555, int src_stride_argb1555,
                                             byte[] dst_y, int dst_stride_y,
                                             byte[] dst_u, int dst_stride_u,
                                             byte[] dst_v, int dst_stride_v,
                                             int width, int height);

    public native int Convert_ARGB4444ToI420(byte[] src_argb4444, int src_stride_argb4444,
                                             byte[] dst_y, int dst_stride_y,
                                             byte[] dst_u, int dst_stride_u,
                                             byte[] dst_v, int dst_stride_v,
                                             int width, int height);

    public native int Convert_Android420ToI420(byte[] src_y, int src_stride_y,
                                               byte[] src_u, int src_stride_u,
                                               byte[] src_v, int src_stride_v,
                                               int src_pixel_stride_uv,
                                               byte[] dst_y, int dst_stride_y,
                                               byte[] dst_u, int dst_stride_u,
                                               byte[] dst_v, int dst_stride_v,
                                               int width, int height);


    public native int Convert_ARGB_ARGBCopy(byte[] src_argb, int src_stride_argb,
                                            byte[] dst_argb, int dst_stride_argb,
                                            int width, int height);

    public native int Convert_ARGB_I420ToARGB(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_argb, int dst_stride_argb,
                                              int width, int height);

    public native int Convert_ARGB_I420ToABGR(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_abgr, int dst_stride_abgr,
                                              int width, int height);

    public native int Convert_ARGB_J420ToARGB(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_argb, int dst_stride_argb,
                                              int width, int height);

    public native int Convert_ARGB_J420ToABGR(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_abgr, int dst_stride_abgr,
                                              int width, int height);

    public native int Convert_ARGB_H420ToARGB(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_argb, int dst_stride_argb,
                                              int width, int height);

    public native int Convert_ARGB_H420ToABGR(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_abgr, int dst_stride_abgr,
                                              int width, int height);

    public native int Convert_ARGB_I422ToARGB(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_argb, int dst_stride_argb,
                                              int width, int height);

    public native int Convert_ARGB_I422ToABGR(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_abgr, int dst_stride_abgr,
                                              int width, int height);

    public native int Convert_ARGB_J422ToARGB(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_argb, int dst_stride_argb,
                                              int width, int height);

    public native int Convert_ARGB_J422ToABGR(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_abgr, int dst_stride_abgr,
                                              int width, int height);

    public native int Convert_ARGB_H422ToARGB(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_argb, int dst_stride_argb,
                                              int width, int height);

    public native int Convert_ARGB_H422ToABGR(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_abgr, int dst_stride_abgr,
                                              int width, int height);

    public native int Convert_ARGB_I444ToARGB(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_argb, int dst_stride_argb,
                                              int width, int height);

    public native int Convert_ARGB_I444ToABGR(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_abgr, int dst_stride_abgr,
                                              int width, int height);

    public native int Convert_ARGB_J444ToARGB(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_argb, int dst_stride_argb,
                                              int width, int height);

    public native int Convert_ARGB_I420AlphaToARGB(byte[] src_y, int src_stride_y,
                                                   byte[] src_u, int src_stride_u,
                                                   byte[] src_v, int src_stride_v,
                                                   byte[] src_a, int src_stride_a,
                                                   byte[] dst_argb, int dst_stride_argb,
                                                   int width, int height, int attenuate);

    public native int Convert_ARGB_I420AlphaToABGR(byte[] src_y, int src_stride_y,
                                                   byte[] src_u, int src_stride_u,
                                                   byte[] src_v, int src_stride_v,
                                                   byte[] src_a, int src_stride_a,
                                                   byte[] dst_abgr, int dst_stride_abgr,
                                                   int width, int height, int attenuate);

    public native int Convert_ARGB_I400ToARGB(byte[] src_y, int src_stride_y,
                                              byte[] dst_argb, int dst_stride_argb,
                                              int width, int height);

    public native int Convert_ARGB_J400ToARGB(byte[] src_y, int src_stride_y,
                                              byte[] dst_argb, int dst_stride_argb,
                                              int width, int height);

    public native int Convert_ARGB_BGRAToARGB(byte[] src_bgra, int src_stride_bgra,
                                              byte[] dst_argb, int dst_stride_argb,
                                              int width, int height);

    public native int Convert_ARGB_ARGBToBGRA(byte[] src_bgra, int src_stride_bgra,
                                              byte[] dst_argb, int dst_stride_argb,
                                              int width, int height);

    public native int Convert_ARGB_ABGRToARGB(byte[] src_abgr, int src_stride_abgr,
                                              byte[] dst_argb, int dst_stride_argb,
                                              int width, int height);

    public native int Convert_ARGB_ARGBToABGR(byte[] src_abgr, int src_stride_abgr,
                                              byte[] dst_argb, int dst_stride_argb,
                                              int width, int height);

    public native int Convert_ARGB_RGBAToARGB(byte[] src_rgba, int src_stride_rgba,
                                              byte[] dst_argb, int dst_stride_argb,
                                              int width, int height);

    public native int Convert_ARGB_RGB24ToARGB(byte[] src_rgb24, int src_stride_rgb24,
                                               byte[] dst_argb, int dst_stride_argb,
                                               int width, int height);

    public native int Convert_ARGB_RAWToARGB(byte[] src_raw, int src_stride_raw,
                                             byte[] dst_argb, int dst_stride_argb,
                                             int width, int height);

    public native int Convert_ARGB_RGB565ToARGB(byte[] src_rgb565, int src_stride_rgb565,
                                                byte[] dst_argb, int dst_stride_argb,
                                                int width, int height);

    public native int Convert_ARGB_ARGB1555ToARGB(byte[] src_argb1555, int src_stride_argb1555,
                                                  byte[] dst_argb, int dst_stride_argb,
                                                  int width, int height);

    public native int Convert_ARGB_ARGB4444ToARGB(byte[] src_argb4444, int src_stride_argb4444,
                                                  byte[] dst_argb, int dst_stride_argb,
                                                  int width, int height);

    public native int Convert_ARGB_NV12ToARGB(byte[] src_y, int src_stride_y,
                                              byte[] src_uv, int src_stride_uv,
                                              byte[] dst_argb, int dst_stride_argb,
                                              int width, int height);

    public native int Convert_ARGB_NV21ToARGB(byte[] src_y, int src_stride_y,
                                              byte[] src_uv, int src_stride_uv,
                                              byte[] dst_argb, int dst_stride_argb,
                                              int width, int height);

    public native int Convert_ARGB_M420ToARGB(byte[] src_m420, int src_stride_m420,
                                              byte[] dst_argb, int dst_stride_argb,
                                              int width, int height);

    public native int Convert_ARGB_YUY2ToARGB(byte[] src_yuy2, int src_stride_yuy2,
                                              byte[] dst_argb, int dst_stride_argb,
                                              int width, int height);

    public native int Convert_ARGB_UYVYToARGB(byte[] src_uyvy, int src_stride_uyvy,
                                              byte[] dst_argb, int dst_stride_argb,
                                              int width, int height);


    public native int Convert_From_I420ToI422(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_y, int dst_stride_y,
                                              byte[] dst_u, int dst_stride_u,
                                              byte[] dst_v, int dst_stride_v,
                                              int width, int height);

    public native int Convert_From_I420ToI444(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_y, int dst_stride_y,
                                              byte[] dst_u, int dst_stride_u,
                                              byte[] dst_v, int dst_stride_v,
                                              int width, int height);

    public native int Convert_From_I400Copy(byte[] src_y, int src_stride_y,
                                            byte[] dst_y, int dst_stride_y,
                                            int width, int height);

    public native int Convert_From_I422ToYUY2(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_yuy2, int dst_stride_yuy2,
                                              int width, int height);

    public native int Convert_From_I420ToYUY2(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_yuy2, int dst_stride_yuy2,
                                              int width, int height);

    public native int Convert_From_I422ToUYVY(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_uyvy, int dst_stride_uyvy,
                                              int width, int height);

    public native int Convert_From_I420ToUYVY(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_uyvy, int dst_stride_uyvy,
                                              int width, int height);

    public native int Convert_From_I420ToNV12(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_y, int dst_stride_y,
                                              byte[] dst_uv, int dst_stride_uv,
                                              int width, int height);

    public native int Convert_From_I420ToNV21(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_y, int dst_stride_y,
                                              byte[] dst_vu, int dst_stride_vu,
                                              int width, int height);

    public native int Convert_From_I420ToRGBA(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_rgba, int dst_stride_rgba,
                                              int width, int height);

    public native int Convert_From_I420ToBGRA(byte[] src_y, int src_stride_y,
                                              byte[] src_u, int src_stride_u,
                                              byte[] src_v, int src_stride_v,
                                              byte[] dst_bgra, int dst_stride_bgra,
                                              int width, int height);

    public native int Convert_From_I420ToRGB24(byte[] src_y, int src_stride_y,
                                               byte[] src_u, int src_stride_u,
                                               byte[] src_v, int src_stride_v,
                                               byte[] dst_rgb24, int dst_stride_rgb24,
                                               int width, int height);

    public native int Convert_From_I420ToRAW(byte[] src_y, int src_stride_y,
                                             byte[] src_u, int src_stride_u,
                                             byte[] src_v, int src_stride_v,
                                             byte[] dst_raw, int dst_stride_raw,
                                             int width, int height);

    public native int Convert_From_I420ToARGB1555(byte[] src_y, int src_stride_y,
                                                  byte[] src_u, int src_stride_u,
                                                  byte[] src_v, int src_stride_v,
                                                  byte[] dst_argb1555, int dst_stride_argb1555,
                                                  int width, int height);

    public native int Convert_From_I420ToARGB4444(byte[] src_y, int src_stride_y,
                                                  byte[] src_u, int src_stride_u,
                                                  byte[] src_v, int src_stride_v,
                                                  byte[] dst_argb4444, int dst_stride_argb4444,
                                                  int width, int height);

    public native int Convert_From_I420ToRGB565(byte[] src_y, int src_stride_y,
                                                byte[] src_u, int src_stride_u,
                                                byte[] src_v, int src_stride_v,
                                                byte[] dst_rgb565, int dst_stride_rgb565,
                                                int width, int height);

    public native int Convert_From_I420ToRGB565Dither(byte[] src_y, int src_stride_y,
                                                      byte[] src_u, int src_stride_u,
                                                      byte[] src_v, int src_stride_v,
                                                      byte[] dst_rgb565, int dst_stride_rgb565,
                                                      byte[] dither4x4, int width, int height);

    public native int Convert_From_ConvertFromI420(byte[] y, int y_stride,
                                                   byte[] u, int u_stride,
                                                   byte[] v, int v_stride,
                                                   byte[] dst_sample, int dst_sample_stride,
                                                   int width, int height,
                                                   int fourcc);


    public native int Convert_From_ARGB_ARGBToI444(byte[] src_argb, int src_stride_argb,
                                                   byte[] dst_y, int dst_stride_y,
                                                   byte[] dst_u, int dst_stride_u,
                                                   byte[] dst_v, int dst_stride_v,
                                                   int width, int height);

    public native int Convert_From_ARGB_ARGBToI422(byte[] src_argb, int src_stride_argb,
                                                   byte[] dst_y, int dst_stride_y,
                                                   byte[] dst_u, int dst_stride_u,
                                                   byte[] dst_v, int dst_stride_v,
                                                   int width, int height);

    public native int Convert_From_ARGB_ARGBToNV12(byte[] src_argb, int src_stride_argb,
                                                   byte[] dst_y, int dst_stride_y,
                                                   byte[] dst_uv, int dst_stride_uv,
                                                   int width, int height);

    public native int Convert_From_ARGB_ARGBToNV21(byte[] src_argb, int src_stride_argb,
                                                   byte[] dst_y, int dst_stride_y,
                                                   byte[] dst_uv, int dst_stride_uv,
                                                   int width, int height);

    public native int Convert_From_ARGB_ARGBToYUY2(byte[] src_argb, int src_stride_argb,
                                                   byte[] dst_yuy2, int dst_stride_yuy2,
                                                   int width, int height);

    public native int Convert_From_ARGB_ARGBToUYVY(byte[] src_argb, int src_stride_argb,
                                                   byte[] dst_uyvy, int dst_stride_uyvy,
                                                   int width, int height);

    public native int Convert_From_ARGB_ARGBToI400(byte[] src_argb, int src_stride_argb,
                                                   byte[] dst_y, int dst_stride_y,
                                                   int width, int height);

    public native int Convert_From_ARGB_ARGBToRGBA(byte[] src_argb, int src_stride_argb,
                                                   byte[] dst_rgba, int dst_stride_rgba,
                                                   int width, int height);

    public native int Convert_From_ARGB_ARGBToRGB24(byte[] src_argb, int src_stride_argb,
                                                    byte[] dst_rgb24, int dst_stride_rgb24,
                                                    int width, int height);

    public native int Convert_From_ARGB_ARGBToRAW(byte[] src_argb, int src_stride_argb,
                                                  byte[] dst_raw, int dst_stride_raw,
                                                  int width, int height);

    public native int Convert_From_ARGB_ARGBToRGB565Dither(byte[] src_argb, int src_stride_argb,
                                                           byte[] dst_rgb565, int dst_stride_rgb565,
                                                           byte[] dither4x4, int width, int height);

    // TODO(fbarchard): Consider using dither function low level with zeros.
    public native int Convert_From_ARGB_ARGBToRGB565(byte[] src_argb, int src_stride_argb,
                                                     byte[] dst_rgb565, int dst_stride_rgb565,
                                                     int width, int height);

    public native int Convert_From_ARGB_ARGBToARGB1555(byte[] src_argb, int src_stride_argb,
                                                       byte[] dst_argb1555, int dst_stride_argb1555,
                                                       int width, int height);

    public native int Convert_From_ARGB_ARGBToARGB4444(byte[] src_argb, int src_stride_argb,
                                                       byte[] dst_argb4444, int dst_stride_argb4444,
                                                       int width, int height);

    public native int Convert_From_ARGB_ARGBToJ420(byte[] src_argb, int src_stride_argb,
                                                   byte[] dst_yj, int dst_stride_yj,
                                                   byte[] dst_u, int dst_stride_u,
                                                   byte[] dst_v, int dst_stride_v,
                                                   int width, int height);

    public native int Convert_From_ARGB_ARGBToJ422(byte[] src_argb, int src_stride_argb,
                                                   byte[] dst_yj, int dst_stride_yj,
                                                   byte[] dst_u, int dst_stride_u,
                                                   byte[] dst_v, int dst_stride_v,
                                                   int width, int height);

    public native int Convert_From_ARGB_ARGBToJ400(byte[] src_argb, int src_stride_argb,
                                                   byte[] dst_yj, int dst_stride_yj,
                                                   int width, int height);


    public native int Convert_To_ARGB_ConvertToARGB(byte[] sample, int sample_size,
                                                    byte[] crop_argb, int argb_stride,
                                                    int crop_x, int crop_y,
                                                    int src_width, int src_height,
                                                    int crop_width, int crop_height,
                                                    RotationMode rotation,
                                                    int fourcc);

    public native int Convert_To_I420_ConvertToI420(byte[] sample,
                                                    int sample_size,
                                                    byte[] y, int y_stride,
                                                    byte[] u, int u_stride,
                                                    byte[] v, int v_stride,
                                                    int crop_x, int crop_y,
                                                    int src_width, int src_height,
                                                    int crop_width, int crop_height,
                                                    RotationMode rotation,
                                                    int fourcc);


    public native void Planar_functions_CopyPlane(byte[] src_y, int src_stride_y,
                                                  byte[] dst_y, int dst_stride_y,
                                                  int width, int height);

    // TODO(fbarchard): Consider support for negative height.
    // TODO(fbarchard): Consider stride measured in bytes.
    public native void Planar_functions_CopyPlane_16(short[] src_y, int src_stride_y,
                                                     short[] dst_y, int dst_stride_y,
                                                     int width, int height);

    public native int Planar_functions_I422Copy(byte[] src_y, int src_stride_y,
                                                byte[] src_u, int src_stride_u,
                                                byte[] src_v, int src_stride_v,
                                                byte[] dst_y, int dst_stride_y,
                                                byte[] dst_u, int dst_stride_u,
                                                byte[] dst_v, int dst_stride_v,
                                                int width, int height);

    public native int Planar_functions_I444Copy(byte[] src_y, int src_stride_y,
                                                byte[] src_u, int src_stride_u,
                                                byte[] src_v, int src_stride_v,
                                                byte[] dst_y, int dst_stride_y,
                                                byte[] dst_u, int dst_stride_u,
                                                byte[] dst_v, int dst_stride_v,
                                                int width, int height);

    public native int Planar_functions_I400ToI400(byte[] src_y, int src_stride_y,
                                                  byte[] dst_y, int dst_stride_y,
                                                  int width, int height);

    public native int Planar_functions_I420ToI400(byte[] src_y, int src_stride_y,
                                                  byte[] src_u, int src_stride_u,
                                                  byte[] src_v, int src_stride_v,
                                                  byte[] dst_y, int dst_stride_y,
                                                  int width, int height);

    public native void Planar_functions_SplitUVPlane(byte[] src_uv, int src_stride_uv,
                                                     byte[] dst_u, int dst_stride_u,
                                                     byte[] dst_v, int dst_stride_v,
                                                     int width, int height);

    public native void Planar_functions_MergeUVPlane(byte[] src_u, int src_stride_u,
                                                     byte[] src_v, int src_stride_v,
                                                     byte[] dst_uv, int dst_stride_uv,
                                                     int width, int height);

    public native int Planar_functions_YUY2ToI422(byte[] src_yuy2, int src_stride_yuy2,
                                                  byte[] dst_y, int dst_stride_y,
                                                  byte[] dst_u, int dst_stride_u,
                                                  byte[] dst_v, int dst_stride_v,
                                                  int width, int height);

    public native int Planar_functions_UYVYToI422(byte[] src_uyvy, int src_stride_uyvy,
                                                  byte[] dst_y, int dst_stride_y,
                                                  byte[] dst_u, int dst_stride_u,
                                                  byte[] dst_v, int dst_stride_v,
                                                  int width, int height);

    public native int Planar_functions_YUY2ToY(byte[] src_yuy2, int src_stride_yuy2,
                                               byte[] dst_y, int dst_stride_y,
                                               int width, int height);

    public native int Planar_functions_I400Mirror(byte[] src_y, int src_stride_y,
                                                  byte[] dst_y, int dst_stride_y,
                                                  int width, int height);

    public native int Planar_functions_I420Mirror(byte[] src_y, int src_stride_y,
                                                  byte[] src_u, int src_stride_u,
                                                  byte[] src_v, int src_stride_v,
                                                  byte[] dst_y, int dst_stride_y,
                                                  byte[] dst_u, int dst_stride_u,
                                                  byte[] dst_v, int dst_stride_v,
                                                  int width, int height);

    public native int Planar_functions_ARGBMirror(byte[] src_argb, int src_stride_argb,
                                                  byte[] dst_argb, int dst_stride_argb,
                                                  int width, int height);

    public native int Planar_functions_ARGBBlend(byte[] src_argb0, int src_stride_argb0,
                                                 byte[] src_argb1, int src_stride_argb1,
                                                 byte[] dst_argb, int dst_stride_argb,
                                                 int width, int height);

    public native int Planar_functions_BlendPlane(byte[] src_y0, int src_stride_y0,
                                                  byte[] src_y1, int src_stride_y1,
                                                  byte[] alpha, int alpha_stride,
                                                  byte[] dst_y, int dst_stride_y,
                                                  int width, int height);

    public native int Planar_functions_I420Blend(byte[] src_y0, int src_stride_y0,
                                                 byte[] src_u0, int src_stride_u0,
                                                 byte[] src_v0, int src_stride_v0,
                                                 byte[] src_y1, int src_stride_y1,
                                                 byte[] src_u1, int src_stride_u1,
                                                 byte[] src_v1, int src_stride_v1,
                                                 byte[] alpha, int alpha_stride,
                                                 byte[] dst_y, int dst_stride_y,
                                                 byte[] dst_u, int dst_stride_u,
                                                 byte[] dst_v, int dst_stride_v,
                                                 int width, int height);

    public native int Planar_functions_ARGBMultiply(byte[] src_argb0, int src_stride_argb0,
                                                    byte[] src_argb1, int src_stride_argb1,
                                                    byte[] dst_argb, int dst_stride_argb,
                                                    int width, int height);

    public native int Planar_functions_ARGBAdd(byte[] src_argb0, int src_stride_argb0,
                                               byte[] src_argb1, int src_stride_argb1,
                                               byte[] dst_argb, int dst_stride_argb,
                                               int width, int height);

    public native int Planar_functions_ARGBSubtract(byte[] src_argb0, int src_stride_argb0,
                                                    byte[] src_argb1, int src_stride_argb1,
                                                    byte[] dst_argb, int dst_stride_argb,
                                                    int width, int height);

    public native int Planar_functions_I422ToRGBA(byte[] src_y, int src_stride_y,
                                                  byte[] src_u, int src_stride_u,
                                                  byte[] src_v, int src_stride_v,
                                                  byte[] dst_rgba, int dst_stride_rgba,
                                                  int width, int height);

    public native int Planar_functions_I422ToBGRA(byte[] src_y, int src_stride_y,
                                                  byte[] src_u, int src_stride_u,
                                                  byte[] src_v, int src_stride_v,
                                                  byte[] dst_bgra, int dst_stride_bgra,
                                                  int width, int height);

    public native int Planar_functions_NV12ToRGB565(byte[] src_y, int src_stride_y,
                                                    byte[] src_uv, int src_stride_uv,
                                                    byte[] dst_rgb565, int dst_stride_rgb565,
                                                    int width, int height);

    public native int Planar_functions_RAWToRGB24(byte[] src_raw, int src_stride_raw,
                                                  byte[] dst_rgb24, int dst_stride_rgb24,
                                                  int width, int height);

    public native void Planar_functions_SetPlane(byte[] dst_y, int dst_stride_y,
                                                 int width, int height,
                                                 int value);

    public native int Planar_functions_I420Rect(byte[] dst_y, int dst_stride_y,
                                                byte[] dst_u, int dst_stride_u,
                                                byte[] dst_v, int dst_stride_v,
                                                int x, int y,
                                                int width, int height,
                                                int value_y, int value_u, int value_v);

    public native int Planar_functions_ARGBRect(byte[] dst_argb, int dst_stride_argb,
                                                int dst_x, int dst_y,
                                                int width, int height,
                                                int value);

    public native int Planar_functions_ARGBAttenuate(byte[] src_argb, int src_stride_argb,
                                                     byte[] dst_argb, int dst_stride_argb,
                                                     int width, int height);

    public native int Planar_functions_ARGBUnattenuate(byte[] src_argb, int src_stride_argb,
                                                       byte[] dst_argb, int dst_stride_argb,
                                                       int width, int height);

    public native int Planar_functions_ARGBGrayTo(byte[] src_argb, int src_stride_argb,
                                                  byte[] dst_argb, int dst_stride_argb,
                                                  int width, int height);

    public native int Planar_functions_ARGBGray(byte[] dst_argb, int dst_stride_argb,
                                                int dst_x, int dst_y,
                                                int width, int height);

    public native int Planar_functions_ARGBSepia(byte[] dst_argb, int dst_stride_argb,
                                                 int dst_x, int dst_y,
                                                 int width, int height);

    public native int Planar_functions_ARGBColorMatrix(byte[] src_argb, int src_stride_argb,
                                                       byte[] dst_argb, int dst_stride_argb,
                                                       byte[] matrix_argb,
                                                       int width, int height);

    public native int Planar_functions_RGBColorMatrix(byte[] dst_argb, int dst_stride_argb,
                                                      byte[] matrix_rgb,
                                                      int dst_x, int dst_y,
                                                      int width, int height);

    public native int Planar_functions_ARGBColorTable(byte[] dst_argb, int dst_stride_argb,
                                                      byte[] table_argb,
                                                      int dst_x, int dst_y, int width, int height);

    public native int Planar_functions_RGBColorTable(byte[] dst_argb, int dst_stride_argb,
                                                     byte[] table_argb,
                                                     int dst_x, int dst_y, int width, int height);

    public native int Planar_functions_ARGBQuantize(byte[] dst_argb, int dst_stride_argb,
                                                    int scale, int interval_size, int interval_offset,
                                                    int dst_x, int dst_y, int width, int height);

    public native int Planar_functions_ARGBComputeCumulativeSum(byte[] src_argb, int src_stride_argb,
                                                                int[] dst_cumsum, int dst_stride32_cumsum,
                                                                int width, int height);

    public native int Planar_functions_ARGBBlur(byte[] src_argb, int src_stride_argb,
                                                byte[] dst_argb, int dst_stride_argb,
                                                int[] dst_cumsum, int dst_stride32_cumsum,
                                                int width, int height, int radius);

    public native int Planar_functions_ARGBShade(byte[] src_argb, int src_stride_argb,
                                                 byte[] dst_argb, int dst_stride_argb,
                                                 int width, int height, int value);

    public native int Planar_functions_InterpolatePlane(byte[] src0, int src_stride0,
                                                        byte[] src1, int src_stride1,
                                                        byte[] dst, int dst_stride,
                                                        int width, int height, int interpolation);

    public native int Planar_functions_ARGBInterpolate(byte[] src_argb0, int src_stride_argb0,
                                                       byte[] src_argb1, int src_stride_argb1,
                                                       byte[] dst_argb, int dst_stride_argb,
                                                       int width, int height, int interpolation);

    public native int Planar_functions_I420Interpolate(byte[] src0_y, int src0_stride_y,
                                                       byte[] src0_u, int src0_stride_u,
                                                       byte[] src0_v, int src0_stride_v,
                                                       byte[] src1_y, int src1_stride_y,
                                                       byte[] src1_u, int src1_stride_u,
                                                       byte[] src1_v, int src1_stride_v,
                                                       byte[] dst_y, int dst_stride_y,
                                                       byte[] dst_u, int dst_stride_u,
                                                       byte[] dst_v, int dst_stride_v,
                                                       int width, int height, int interpolation);

    public native int Planar_functions_ARGBShuffle(byte[] src_bgra, int src_stride_bgra,
                                                   byte[] dst_argb, int dst_stride_argb,
                                                   byte[] shuffler, int width, int height);

    public native int Planar_functions_ARGBSobel(byte[] src_argb, int src_stride_argb,
                                                 byte[] dst_argb, int dst_stride_argb,
                                                 int width, int height);

    public native int Planar_functions_ARGBSobelToPlane(byte[] src_argb, int src_stride_argb,
                                                        byte[] dst_y, int dst_stride_y,
                                                        int width, int height);

    public native int Planar_functions_ARGBSobelXY(byte[] src_argb, int src_stride_argb,
                                                   byte[] dst_argb, int dst_stride_argb,
                                                   int width, int height);

    public native int Planar_functions_ARGBPolynomial(byte[] src_argb, int src_stride_argb,
                                                      byte[] dst_argb, int dst_stride_argb,
                                                      float[] poly,
                                                      int width, int height);

    public native int Planar_functions_HalfFloatPlane(short[] src_y, int src_stride_y,
                                                      short[] dst_y, int dst_stride_y,
                                                      float scale,
                                                      int width, int height);

    public native int Planar_functions_ARGBLumaColorTable(byte[] src_argb, int src_stride_argb,
                                                          byte[] dst_argb, int dst_stride_argb,
                                                          byte[] luma,
                                                          int width, int height);

    public native int Planar_functions_ARGBCopyAlpha(byte[] src_argb, int src_stride_argb,
                                                     byte[] dst_argb, int dst_stride_argb,
                                                     int width, int height);

    public native int Planar_functions_ARGBExtractAlpha(byte[] src_argb, int src_stride,
                                                        byte[] dst_a, int dst_stride,
                                                        int width, int height);

    public native int Planar_functions_ARGBCopyYToAlpha(byte[] src_y, int src_stride_y,
                                                        byte[] dst_argb, int dst_stride_argb,
                                                        int width, int height);

    public native int Planar_functions_YUY2ToNV12(byte[] src_yuy2, int src_stride_yuy2,
                                                  byte[] dst_y, int dst_stride_y,
                                                  byte[] dst_uv, int dst_stride_uv,
                                                  int width, int height);

    public native int Planar_functions_UYVYToNV12(byte[] src_uyvy, int src_stride_uyvy,
                                                  byte[] dst_y, int dst_stride_y,
                                                  byte[] dst_uv, int dst_stride_uv,
                                                  int width, int height);


    public native void Rotate_TransposePlane(byte[] src, int src_stride,
                                             byte[] dst, int dst_stride,
                                             int width, int height);

    public native void Rotate_RotatePlane90(byte[] src, int src_stride,
                                            byte[] dst, int dst_stride,
                                            int width, int height);

    public native void Rotate_RotatePlane270(byte[] src, int src_stride,
                                             byte[] dst, int dst_stride,
                                             int width, int height);

    public native void Rotate_RotatePlane180(byte[] src, int src_stride,
                                             byte[] dst, int dst_stride,
                                             int width, int height);

    public native void Rotate_TransposeUV(byte[] src, int src_stride,
                                          byte[] dst_a, int dst_stride_a,
                                          byte[] dst_b, int dst_stride_b,
                                          int width, int height);

    public native void Rotate_RotateUV90(byte[] src, int src_stride,
                                         byte[] dst_a, int dst_stride_a,
                                         byte[] dst_b, int dst_stride_b,
                                         int width, int height);

    public native void Rotate_RotateUV270(byte[] src, int src_stride,
                                          byte[] dst_a, int dst_stride_a,
                                          byte[] dst_b, int dst_stride_b,
                                          int width, int height);

    public native void Rotate_RotateUV180(byte[] src, int src_stride,
                                          byte[] dst_a, int dst_stride_a,
                                          byte[] dst_b, int dst_stride_b,
                                          int width, int height);

    public native int Rotate_RotatePlane(byte[] src, int src_stride,
                                         byte[] dst, int dst_stride,
                                         int width, int height,
                                         RotationMode mode);

    public native int Rotate_I420Rotate(byte[] src_y, int src_stride_y,
                                        byte[] src_u, int src_stride_u,
                                        byte[] src_v, int src_stride_v,
                                        byte[] dst_y, int dst_stride_y,
                                        byte[] dst_u, int dst_stride_u,
                                        byte[] dst_v, int dst_stride_v,
                                        int width, int height,
                                        RotationMode mode);

    public native int Rotate_NV12ToI420Rotate(byte[] src_y, int src_stride_y,
                                              byte[] src_uv, int src_stride_uv,
                                              byte[] dst_y, int dst_stride_y,
                                              byte[] dst_u, int dst_stride_u,
                                              byte[] dst_v, int dst_stride_v,
                                              int width, int height,
                                              RotationMode mode);


    public native int Rotate_ARGB_ARGBRotate(byte[] src_argb, int src_stride_argb,
                                             byte[] dst_argb, int dst_stride_argb,
                                             int width, int height,
                                             RotationMode mode);


    public native void Scale_ScalePlane(byte[] src, int src_stride,
                                        int src_width, int src_height,
                                        byte[] dst, int dst_stride,
                                        int dst_width, int dst_height,
                                        FilterMode filtering);

    public native void Scale_ScalePlane_16(short[] src, int src_stride,
                                           int src_width, int src_height,
                                           short[] dst, int dst_stride,
                                           int dst_width, int dst_height,
                                           FilterMode filtering);

    public native int Scale_I420Scale(byte[] src_y, int src_stride_y,
                                      byte[] src_u, int src_stride_u,
                                      byte[] src_v, int src_stride_v,
                                      int src_width, int src_height,
                                      byte[] dst_y, int dst_stride_y,
                                      byte[] dst_u, int dst_stride_u,
                                      byte[] dst_v, int dst_stride_v,
                                      int dst_width, int dst_height,
                                      FilterMode filtering);

    public native int Scale_I420Scale_16(short[] src_y, int src_stride_y,
                                         short[] src_u, int src_stride_u,
                                         short[] src_v, int src_stride_v,
                                         int src_width, int src_height,
                                         short[] dst_y, int dst_stride_y,
                                         short[] dst_u, int dst_stride_u,
                                         short[] dst_v, int dst_stride_v,
                                         int dst_width, int dst_height,
                                         FilterMode filtering);

    @Deprecated
    // Deprecated api
    public native int Scale_Scale(byte[] src_y, byte[] src_u, byte[] src_v,
                                  int src_stride_y, int src_stride_u, int src_stride_v,
                                  int src_width, int src_height,
                                  byte[] dst_y, byte[] dst_u, byte[] dst_v,
                                  int dst_stride_y, int dst_stride_u, int dst_stride_v,
                                  int dst_width, int dst_height,
                                  int interpolate);

    @Deprecated
    // Deprecated api
    public native int Scale_ScaleOffset(byte[] src, int src_width, int src_height,
                                        byte[] dst, int dst_width, int dst_height,
                                        int dst_yoffset, int interpolate);


    public native int Scale_ARGB_ARGBScaleClip(byte[] src_argb, int src_stride_argb,
                                               int src_width, int src_height,
                                               byte[] dst_argb, int dst_stride_argb,
                                               int dst_width, int dst_height,
                                               int clip_x, int clip_y, int clip_width, int clip_height,
                                               FilterMode filtering);

    public native int Scale_ARGB_ARGBScale(byte[] src_argb, int src_stride_argb,
                                           int src_width, int src_height,
                                           byte[] dst_argb, int dst_stride_argb,
                                           int dst_width, int dst_height,
                                           FilterMode filtering);

    public native int Scale_ARGB_YUVToARGBScaleClip(byte[] src_y, int src_stride_y,
                                                    byte[] src_u, int src_stride_u,
                                                    byte[] src_v, int src_stride_v,
                                                    int src_fourcc,
                                                    int src_width, int src_height,
                                                    byte[] dst_argb, int dst_stride_argb,
                                                    int dst_fourcc,
                                                    int dst_width, int dst_height,
                                                    int clip_x, int clip_y, int clip_width, int clip_height,
                                                    FilterMode filtering);
}
