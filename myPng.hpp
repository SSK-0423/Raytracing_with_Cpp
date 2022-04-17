#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "png.h"

enum COLORTYPE
{
    COLOR_RGB = 3,
    COLOR_RGBA,
};

// 色
struct Color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;

    Color(
        unsigned char red, unsigned char green,
        unsigned char blue, unsigned char alpha = 1)
        : r(red), g(green), b(blue), a(alpha) {}
};

// ピクセル構造体
struct Pixel
{
    Color color;
    void SetColor(Color newColor) { color = newColor; }
};

// ビットマップデータ
struct BitMapData
{
    unsigned int width;        // 幅
    unsigned int height;       // 高さ
    unsigned char *pixelsData; // ピクセルデータ
    unsigned char channel;     // チャネル

    BitMapData() {}
    BitMapData(unsigned int w, unsigned int h, unsigned int ch)
        : width(w), height(h), channel(ch) {}
};

int pngFileReadDecode(BitMapData *, const char *);
int pngFileEncodeWrite(BitMapData *, const char *);
int freeBitmapData(BitMapData *);

#define SIGNATURE_NUM 8