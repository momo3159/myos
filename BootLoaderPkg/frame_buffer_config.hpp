#pragma once
#include <stdint.h>

enum PixelFormat {
  kPixelRGBResv8BitPerColor,
  kPixelBGRResv8BitPerColor,
};

struct FrameBufferConfig {
  uint8_t* frame_buffer;         // フレームバッファへのポインタ
  uint32_t pixels_per_scan_line; // 横方向のピクセル数（非表示領域を含む）
  uint32_t horizontal_resolution;
  uint32_t vertical_resolution;
  enum PixelFormat pixel_format;
};