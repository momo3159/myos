#include "graphics.hpp"

// 詳細・・・http://elm-chan.org/junk/32bit/binclude_j.html
// nm hankaku.oで変数名が見れる
extern const uint8_t _binary_hankaku_bin_start;
extern const uint8_t _binary_hankaku_bin_end;
extern const uint8_t _binary_hankaku_bin_size;

const uint8_t* GetFont(char c) {
  auto index = 16 * static_cast<unsigned int>(c);
  if (index >= reinterpret_cast<uintptr_t>(&_binary_hankaku_bin_size)) {
    return nullptr;
  }

  return &_binary_hankaku_bin_start + index;
}

// (x, y)は文字を囲む8x16ボックスの左上の頂点
void WriteAscii(PixelWriter& writer, int x, int y, char c, const PixelColor& color) {
  const uint8_t* font = GetFont(c);
  if (font == nullptr) return;

  for (int dy=0;dy<16;dy++) {
    for (int dx=0;dx<8;dx++) {
      // 1つずつ左シフトして，左端の値を抽出
      // 0x80u = 10000000
      if ((font[dy] << dx) & 0x80u) {
        writer.Write(x+dx, y+dy, color);
      }
    }
  }
}