package com.wpf.library.libyuv_android.Data;

/**
 * Created by 王朋飞 on 2018/5/8.
 */
public class ARGBBlendRow {
    private byte[] src_argb0;
    private byte[] src_argb1;
    private byte[] dst_argb;
    private int width;

    public ARGBBlendRow(byte[] src_argb0, byte[] src_argb1, byte[] dst_argb, int width) {
        this.src_argb0 = src_argb0;
        this.src_argb1 = src_argb1;
        this.dst_argb = dst_argb;
        this.width = width;
    }

    public byte[] getSrc_argb0() {
        return src_argb0;
    }

    public void setSrc_argb0(byte[] src_argb0) {
        this.src_argb0 = src_argb0;
    }

    public byte[] getSrc_argb1() {
        return src_argb1;
    }

    public void setSrc_argb1(byte[] src_argb1) {
        this.src_argb1 = src_argb1;
    }

    public byte[] getDst_argb() {
        return dst_argb;
    }

    public void setDst_argb(byte[] dst_argb) {
        this.dst_argb = dst_argb;
    }

    public int getWidth() {
        return width;
    }

    public void setWidth(int width) {
        this.width = width;
    }
}
