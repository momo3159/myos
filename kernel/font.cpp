#include "graphics.hpp"

const uint8_t kFontA[16] = {
  0b00000000,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00100100,
  0b00100100,
  0b00100100,
  0b00100100,
  0b01111110,
  0b01000010,
  0b01000010,
  0b01000010,
  0b11100111,
  0b00000000,
  0b00000000,
};

// (x, y)は文字を囲む8x16ボックスの左上の頂点
void WriteAscii(PixelWriter& writer, int x, int y, char c, const PixelColor& color) {
  if (c != 'A') return;
  for (int dy=0;dy<16;dy++) {
    for (int dx=0;dx<8;dx++) {
      // 1つずつ左シフトして，左端の値を抽出
      // 0x80u = 10000000
      if ((kFontA[dy] << dx) & 0x80u) {
        writer.Write(x+dx, y+dy, color);
      }
    }
  }
}