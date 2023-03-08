﻿#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_New_DOM
#define LV_ATTRIBUTE_IMG_New_DOM
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_New_DOM uint8_t New_Dom_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb6, 0x25, 0x49, 0x6d, 0x6d, 0x6d, 0x6d, 0x49, 0x6e, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb6, 0x49, 0xb6, 0x92, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x6e, 0xb7, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6d, 0x49, 0xff, 0xb7, 0x49, 0x6d, 0x6d, 0x6d, 0x6d, 0x49, 0x49, 0x6e, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6e, 0x49, 0x49, 0x49, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x49, 0x6d, 0x6e, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6e, 0x49, 0x6d, 0x49, 0x6d, 0x6d, 0x49, 0x49, 0x49, 0x49, 0x49, 0x6e, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6e, 0x49, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x49, 0x92, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6e, 0x49, 0x6d, 0x6d, 0x49, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6e, 0x49, 0x6d, 0x6d, 0x49, 0x6d, 0xb6, 0x92, 0xb6, 0xff, 0xff, 0xff, 
  0xb6, 0xb6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb7, 0x49, 0x49, 0x6d, 0x49, 0xb6, 0xff, 0xdb, 0xb7, 0xdb, 0xff, 0xff, 0xff, 
  0x49, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb6, 0x6d, 0x49, 0x6d, 0x49, 0x49, 0xb7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x6e, 0x6e, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb7, 0x6d, 0x49, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x92, 0xb7, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x6e, 0x49, 0x49, 0xdb, 0xff, 0xff, 0xff, 0x92, 0x49, 0x49, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x49, 0x6e, 0x6e, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x92, 0x6d, 0x49, 0x6d, 0xdb, 0xff, 0x92, 0x49, 0x49, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x49, 0x49, 0xdb, 0xff, 0xb6, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x6e, 0x49, 0x49, 0x49, 0x6d, 0x6d, 0x49, 0x49, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x49, 0x49, 0xb7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x92, 0x49, 0x49, 0x6d, 0x49, 0x49, 0x49, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x49, 0xb7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xdb, 0x6d, 0x49, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x49, 0x6d, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xdb, 0x49, 0x49, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x49, 0xb7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xdb, 0x6d, 0x49, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x49, 0x49, 0xb6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xdb, 0x6d, 0x49, 0x6d, 0x6d, 0x6d, 0x49, 0x49, 0x6d, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x92, 0x49, 0x49, 0x6e, 0xb6, 0x49, 0x6d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x49, 0x6d, 0xff, 0xff, 0x92, 0x6d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x49, 0xff, 0xff, 0xff, 0xff, 0x6d, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x92, 0xff, 0xff, 0xff, 0xff, 0x6d, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x49, 0xff, 0xff, 0xff, 0xff, 0x6d, 0x49, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd3, 0x9c, 0x25, 0x29, 0x69, 0x4a, 0xec, 0x62, 0xcb, 0x5a, 0xcb, 0x5a, 0xcb, 0x5a, 0x49, 0x4a, 0x6e, 0x73, 0xdf, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb3, 0x9c, 0x49, 0x4a, 0xb2, 0x94, 0xef, 0x7b, 0x08, 0x42, 0x8a, 0x52, 0x69, 0x4a, 0x6a, 0x52, 0x6a, 0x52, 0x8a, 0x52, 0x6e, 0x73, 0x14, 0xa5, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xab, 0x5a, 0xc7, 0x39, 0xba, 0xd6, 0x14, 0xa5, 0xe8, 0x41, 0xaa, 0x52, 0xab, 0x5a, 0xaa, 0x52, 0xcb, 0x5a, 0x6a, 0x52, 0x49, 0x4a, 0x4d, 0x6b, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0x2c, 0x63, 0x69, 0x4a, 0x69, 0x4a, 0x69, 0x4a, 0xaa, 0x52, 0xaa, 0x52, 0xab, 0x5a, 0xaa, 0x52, 0xab, 0x5a, 0x8a, 0x52, 0x8a, 0x52, 0x8e, 0x73, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0x0c, 0x63, 0x49, 0x4a, 0x8a, 0x52, 0x6a, 0x52, 0xab, 0x5a, 0x8a, 0x52, 0x6a, 0x52, 0x6a, 0x52, 0x8a, 0x52, 0x49, 0x4a, 0x69, 0x4a, 0x6d, 0x6b, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0x0c, 0x63, 0x49, 0x4a, 0xaa, 0x52, 0xaa, 0x52, 0x8a, 0x52, 0xab, 0x5a, 0xcb, 0x5a, 0xcb, 0x5a, 0xcb, 0x5a, 0xaa, 0x52, 0x49, 0x4a, 0x8e, 0x73, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0x2d, 0x6b, 0x49, 0x4a, 0xab, 0x5a, 0xcb, 0x5a, 0x08, 0x42, 0x10, 0x84, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xbe, 0xf7, 0xdf, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0x0c, 0x63, 0x49, 0x4a, 0xab, 0x5a, 0xab, 0x5a, 0x49, 0x4a, 0xec, 0x62, 0x92, 0x94, 0x72, 0x94, 0xd3, 0x9c, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xb3, 0x9c, 0xb3, 0x9c, 0xbe, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x76, 0xb5, 0x6a, 0x52, 0x8a, 0x52, 0x8a, 0x52, 0x6a, 0x52, 0xd3, 0x9c, 0x3d, 0xef, 0xb7, 0xbd, 0x55, 0xad, 0xd7, 0xbd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x8a, 0x52, 0x8e, 0x73, 0x7d, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7d, 0xef, 0xb2, 0x94, 0xcb, 0x5a, 0x49, 0x4a, 0xab, 0x5a, 0x8a, 0x52, 0x69, 0x4a, 0x75, 0xad, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x0c, 0x63, 0x0c, 0x63, 0xd7, 0xbd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x5d, 0xef, 0x55, 0xad, 0xeb, 0x5a, 0xe7, 0x39, 0xaa, 0x52, 0xab, 0x5a, 0xaa, 0x52, 0x8a, 0x52, 0x8a, 0x52, 0xf0, 0x83, 0x55, 0xad, 0x9a, 0xd6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x6d, 0x6b, 0x08, 0x42, 0x49, 0x4a, 0x79, 0xce, 0xff, 0xff, 0xff, 0xff, 0x7e, 0xf7, 0x31, 0x8c, 0xe7, 0x39, 0x6a, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0x6a, 0x52, 0x6d, 0x6b, 0x2d, 0x6b, 0xaf, 0x7b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xae, 0x73, 0xaa, 0x52, 0xc7, 0x39, 0xaa, 0x52, 0x18, 0xc6, 0x7d, 0xef, 0x30, 0x84, 0xc7, 0x39, 0x6a, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0x8a, 0x52, 0xaa, 0x52, 0x8a, 0x52, 0x49, 0x4a, 0xd7, 0xbd, 0xdf, 0xff, 0xd3, 0x9c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x6e, 0x73, 0x69, 0x4a, 0x6a, 0x52, 0x8a, 0x52, 0xab, 0x5a, 0xeb, 0x5a, 0x6a, 0x52, 0x8a, 0x52, 0xab, 0x5a, 0x8a, 0x52, 0xaa, 0x52, 0x8a, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0x8a, 0x52, 0x69, 0x4a, 0x76, 0xb5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xaf, 0x7b, 0x6a, 0x52, 0x29, 0x4a, 0xaa, 0x52, 0x49, 0x4a, 0x28, 0x42, 0x8a, 0x52, 0xab, 0x5a, 0xaa, 0x52, 0x8a, 0x52, 0x8a, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0x8a, 0x52, 0x28, 0x42, 0x55, 0xad, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x7e, 0xf7, 0x59, 0xce, 0xab, 0x5a, 0x29, 0x4a, 0xab, 0x5a, 0xab, 0x5a, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0x69, 0x4a, 0x0c, 0x63, 0x79, 0xce, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x7a, 0xd6, 0x6a, 0x52, 0x29, 0x4a, 0xab, 0x5a, 0xaa, 0x52, 0x8a, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0x8a, 0x52, 0xe7, 0x39, 0x76, 0xb5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x39, 0xce, 0xab, 0x5a, 0x08, 0x42, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0x8a, 0x52, 0x8a, 0x52, 0xcb, 0x5a, 0x6a, 0x52, 0xc7, 0x39, 0xb2, 0x94, 0x7e, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9a, 0xd6, 0xab, 0x5a, 0x49, 0x4a, 0xab, 0x5a, 0xab, 0x5a, 0xaa, 0x52, 0x49, 0x4a, 0x6a, 0x52, 0x8a, 0x52, 0x51, 0x8c, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9a, 0xd6, 0x10, 0x84, 0x8a, 0x52, 0x69, 0x4a, 0x4d, 0x6b, 0xb2, 0x94, 0xe8, 0x41, 0x8a, 0x52, 0xdb, 0xde, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9a, 0xd6, 0xe8, 0x41, 0xcb, 0x5a, 0xfc, 0xe6, 0xff, 0xff, 0x92, 0x94, 0x8a, 0x52, 0xba, 0xd6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x59, 0xce, 0xc7, 0x39, 0x1c, 0xe7, 0xff, 0xff, 0xff, 0xff, 0x9e, 0xf7, 0x0c, 0x63, 0x9a, 0xd6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd7, 0xbd, 0x51, 0x8c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbe, 0xf7, 0x0c, 0x63, 0xf8, 0xc5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x59, 0xce, 0x86, 0x31, 0x1c, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xec, 0x62, 0x49, 0x4a, 0x3d, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Red: 5 bit, Green: 6 bit, Blue: 5 bit BUT the 2 bytes are swapped*/
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9c, 0xd3, 0x29, 0x25, 0x4a, 0x69, 0x62, 0xec, 0x5a, 0xcb, 0x5a, 0xcb, 0x5a, 0xcb, 0x4a, 0x49, 0x73, 0x6e, 0xff, 0xdf, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9c, 0xb3, 0x4a, 0x49, 0x94, 0xb2, 0x7b, 0xef, 0x42, 0x08, 0x52, 0x8a, 0x4a, 0x69, 0x52, 0x6a, 0x52, 0x6a, 0x52, 0x8a, 0x73, 0x6e, 0xa5, 0x14, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0x5a, 0xab, 0x39, 0xc7, 0xd6, 0xba, 0xa5, 0x14, 0x41, 0xe8, 0x52, 0xaa, 0x5a, 0xab, 0x52, 0xaa, 0x5a, 0xcb, 0x52, 0x6a, 0x4a, 0x49, 0x6b, 0x4d, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0x63, 0x2c, 0x4a, 0x69, 0x4a, 0x69, 0x4a, 0x69, 0x52, 0xaa, 0x52, 0xaa, 0x5a, 0xab, 0x52, 0xaa, 0x5a, 0xab, 0x52, 0x8a, 0x52, 0x8a, 0x73, 0x8e, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0x63, 0x0c, 0x4a, 0x49, 0x52, 0x8a, 0x52, 0x6a, 0x5a, 0xab, 0x52, 0x8a, 0x52, 0x6a, 0x52, 0x6a, 0x52, 0x8a, 0x4a, 0x49, 0x4a, 0x69, 0x6b, 0x6d, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0x63, 0x0c, 0x4a, 0x49, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0x8a, 0x5a, 0xab, 0x5a, 0xcb, 0x5a, 0xcb, 0x5a, 0xcb, 0x52, 0xaa, 0x4a, 0x49, 0x73, 0x8e, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0x6b, 0x2d, 0x4a, 0x49, 0x5a, 0xab, 0x5a, 0xcb, 0x42, 0x08, 0x84, 0x10, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xf7, 0xbe, 0xff, 0xdf, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0x63, 0x0c, 0x4a, 0x49, 0x5a, 0xab, 0x5a, 0xab, 0x4a, 0x49, 0x62, 0xec, 0x94, 0x92, 0x94, 0x72, 0x9c, 0xd3, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 
  0x9c, 0xb3, 0x9c, 0xb3, 0xf7, 0xbe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb5, 0x76, 0x52, 0x6a, 0x52, 0x8a, 0x52, 0x8a, 0x52, 0x6a, 0x9c, 0xd3, 0xef, 0x3d, 0xbd, 0xb7, 0xad, 0x55, 0xbd, 0xd7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x52, 0x8a, 0x73, 0x8e, 0xef, 0x7d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0x7d, 0x94, 0xb2, 0x5a, 0xcb, 0x4a, 0x49, 0x5a, 0xab, 0x52, 0x8a, 0x4a, 0x69, 0xad, 0x75, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x63, 0x0c, 0x63, 0x0c, 0xbd, 0xd7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0x5d, 0xad, 0x55, 0x5a, 0xeb, 0x39, 0xe7, 0x52, 0xaa, 0x5a, 0xab, 0x52, 0xaa, 0x52, 0x8a, 0x52, 0x8a, 0x83, 0xf0, 0xad, 0x55, 0xd6, 0x9a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x6b, 0x6d, 0x42, 0x08, 0x4a, 0x49, 0xce, 0x79, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x7e, 0x8c, 0x31, 0x39, 0xe7, 0x52, 0x6a, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0x6a, 0x6b, 0x6d, 0x6b, 0x2d, 0x7b, 0xaf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x73, 0xae, 0x52, 0xaa, 0x39, 0xc7, 0x52, 0xaa, 0xc6, 0x18, 0xef, 0x7d, 0x84, 0x30, 0x39, 0xc7, 0x52, 0x6a, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0x8a, 0x52, 0xaa, 0x52, 0x8a, 0x4a, 0x49, 0xbd, 0xd7, 0xff, 0xdf, 0x9c, 0xd3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x73, 0x6e, 0x4a, 0x69, 0x52, 0x6a, 0x52, 0x8a, 0x5a, 0xab, 0x5a, 0xeb, 0x52, 0x6a, 0x52, 0x8a, 0x5a, 0xab, 0x52, 0x8a, 0x52, 0xaa, 0x52, 0x8a, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0x8a, 0x4a, 0x69, 0xb5, 0x76, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x7b, 0xaf, 0x52, 0x6a, 0x4a, 0x29, 0x52, 0xaa, 0x4a, 0x49, 0x42, 0x28, 0x52, 0x8a, 0x5a, 0xab, 0x52, 0xaa, 0x52, 0x8a, 0x52, 0x8a, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0x8a, 0x42, 0x28, 0xad, 0x55, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xf7, 0x7e, 0xce, 0x59, 0x5a, 0xab, 0x4a, 0x29, 0x5a, 0xab, 0x5a, 0xab, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x4a, 0x69, 0x63, 0x0c, 0xce, 0x79, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xd6, 0x7a, 0x52, 0x6a, 0x4a, 0x29, 0x5a, 0xab, 0x52, 0xaa, 0x52, 0x8a, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0x8a, 0x39, 0xe7, 0xb5, 0x76, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xce, 0x39, 0x5a, 0xab, 0x42, 0x08, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0xaa, 0x52, 0x8a, 0x52, 0x8a, 0x5a, 0xcb, 0x52, 0x6a, 0x39, 0xc7, 0x94, 0xb2, 0xf7, 0x7e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd6, 0x9a, 0x5a, 0xab, 0x4a, 0x49, 0x5a, 0xab, 0x5a, 0xab, 0x52, 0xaa, 0x4a, 0x49, 0x52, 0x6a, 0x52, 0x8a, 0x8c, 0x51, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd6, 0x9a, 0x84, 0x10, 0x52, 0x8a, 0x4a, 0x69, 0x6b, 0x4d, 0x94, 0xb2, 0x41, 0xe8, 0x52, 0x8a, 0xde, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd6, 0x9a, 0x41, 0xe8, 0x5a, 0xcb, 0xe6, 0xfc, 0xff, 0xff, 0x94, 0x92, 0x52, 0x8a, 0xd6, 0xba, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xce, 0x59, 0x39, 0xc7, 0xe7, 0x1c, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x9e, 0x63, 0x0c, 0xd6, 0x9a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbd, 0xd7, 0x8c, 0x51, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xbe, 0x63, 0x0c, 0xc5, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xce, 0x59, 0x31, 0x86, 0xe7, 0x1c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0x62, 0xec, 0x4a, 0x49, 0xef, 0x3d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
#endif
#if LV_COLOR_DEPTH == 32
  /*Pixel format: Fix 0xFF: 8 bit, Red: 8 bit, Green: 8 bit, Blue: 8 bit*/
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x98, 0x98, 0x98, 0xff, 0x25, 0x25, 0x25, 0xff, 0x4a, 0x4a, 0x4a, 0xff, 0x5c, 0x5c, 0x5c, 0xff, 0x58, 0x58, 0x58, 0xff, 0x59, 0x59, 0x59, 0xff, 0x59, 0x59, 0x59, 0xff, 0x47, 0x47, 0x47, 0xff, 0x6d, 0x6d, 0x6d, 0xff, 0xf6, 0xf6, 0xf6, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x94, 0x94, 0x94, 0xff, 0x46, 0x46, 0x46, 0xff, 0x92, 0x92, 0x92, 0xff, 0x7a, 0x7a, 0x7a, 0xff, 0x3e, 0x3e, 0x3e, 0xff, 0x4e, 0x4e, 0x4e, 0xff, 0x4b, 0x4b, 0x4b, 0xff, 0x4c, 0x4c, 0x4c, 0xff, 0x4c, 0x4c, 0x4c, 0xff, 0x4e, 0x4e, 0x4e, 0xff, 0x6d, 0x6d, 0x6d, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0xf5, 0xf5, 0xff, 0x54, 0x54, 0x54, 0xff, 0x38, 0x38, 0x38, 0xff, 0xd3, 0xd3, 0xd3, 0xff, 0xa0, 0xa0, 0xa0, 0xff, 0x3c, 0x3c, 0x3c, 0xff, 0x53, 0x53, 0x53, 0xff, 0x54, 0x54, 0x54, 0xff, 0x53, 0x53, 0x53, 0xff, 0x56, 0x56, 0x56, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0x46, 0x46, 0x46, 0xff, 0x66, 0x66, 0x66, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0x63, 0x63, 0x63, 0xff, 0x4a, 0x4a, 0x4a, 0xff, 0x4a, 0x4a, 0x4a, 0xff, 0x4b, 0x4b, 0x4b, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x54, 0x54, 0x54, 0xff, 0x52, 0x52, 0x52, 0xff, 0x54, 0x54, 0x54, 0xff, 0x4e, 0x4e, 0x4e, 0xff, 0x51, 0x51, 0x51, 0xff, 0x6f, 0x6f, 0x6f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0x60, 0x60, 0x60, 0xff, 0x49, 0x49, 0x49, 0xff, 0x50, 0x50, 0x50, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0x54, 0x54, 0x54, 0xff, 0x50, 0x50, 0x50, 0xff, 0x4c, 0x4c, 0x4c, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0x4e, 0x4e, 0x4e, 0xff, 0x48, 0x48, 0x48, 0xff, 0x4a, 0x4a, 0x4a, 0xff, 0x6a, 0x6a, 0x6a, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf6, 0xf6, 0xf6, 0xff, 0x61, 0x61, 0x61, 0xff, 0x49, 0x49, 0x49, 0xff, 0x53, 0x53, 0x53, 0xff, 0x52, 0x52, 0x52, 0xff, 0x50, 0x50, 0x50, 0xff, 0x55, 0x55, 0x55, 0xff, 0x58, 0x58, 0x58, 0xff, 0x59, 0x59, 0x59, 0xff, 0x59, 0x59, 0x59, 0xff, 0x52, 0x52, 0x52, 0xff, 0x48, 0x48, 0x48, 0xff, 0x70, 0x70, 0x70, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf6, 0xf6, 0xf6, 0xff, 0x64, 0x64, 0x64, 0xff, 0x49, 0x49, 0x49, 0xff, 0x54, 0x54, 0x54, 0xff, 0x57, 0x57, 0x57, 0xff, 0x3f, 0x3f, 0x3f, 0xff, 0x7e, 0x7e, 0x7e, 0xff, 0xf5, 0xf5, 0xf5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xf4, 0xf4, 0xf4, 0xff, 0xf3, 0xf3, 0xf3, 0xff, 0xf6, 0xf6, 0xf6, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf8, 0xf8, 0xff, 0x60, 0x60, 0x60, 0xff, 0x47, 0x47, 0x47, 0xff, 0x55, 0x55, 0x55, 0xff, 0x54, 0x54, 0x54, 0xff, 0x49, 0x49, 0x49, 0xff, 0x5c, 0x5c, 0x5c, 0xff, 0x91, 0x91, 0x91, 0xff, 0x8d, 0x8d, 0x8d, 0xff, 0x97, 0x97, 0x97, 0xff, 0xf9, 0xf9, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x95, 0x95, 0x95, 0xff, 0x95, 0x95, 0x95, 0xff, 0xf2, 0xf2, 0xf2, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xac, 0xac, 0xac, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0x4f, 0x4f, 0x4f, 0xff, 0x51, 0x51, 0x51, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0x98, 0x98, 0x98, 0xff, 0xe4, 0xe4, 0xe4, 0xff, 0xb5, 0xb5, 0xb5, 0xff, 0xa9, 0xa9, 0xa9, 0xff, 0xb6, 0xb6, 0xb6, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x4f, 0x4f, 0x4f, 0xff, 0x71, 0x71, 0x71, 0xff, 0xeb, 0xeb, 0xeb, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xea, 0xea, 0xea, 0xff, 0x93, 0x93, 0x93, 0xff, 0x56, 0x56, 0x56, 0xff, 0x49, 0x49, 0x49, 0xff, 0x54, 0x54, 0x54, 0xff, 0x4e, 0x4e, 0x4e, 0xff, 0x4a, 0x4a, 0x4a, 0xff, 0xab, 0xab, 0xab, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x60, 0x60, 0x60, 0xff, 0x60, 0x60, 0x60, 0xff, 0xb8, 0xb8, 0xb8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe8, 0xe8, 0xe8, 0xff, 0xa7, 0xa7, 0xa7, 0xff, 0x5b, 0x5b, 0x5b, 0xff, 0x3b, 0x3b, 0x3b, 0xff, 0x52, 0x52, 0x52, 0xff, 0x54, 0x54, 0x54, 0xff, 0x52, 0x52, 0x52, 0xff, 0x50, 0x50, 0x50, 0xff, 0x50, 0x50, 0x50, 0xff, 0x7c, 0x7c, 0x7c, 0xff, 0xa9, 0xa9, 0xa9, 0xff, 0xcf, 0xcf, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x6b, 0x6b, 0x6b, 0xff, 0x3f, 0x3f, 0x3f, 0xff, 0x48, 0x48, 0x48, 0xff, 0xca, 0xca, 0xca, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xed, 0xed, 0xed, 0xff, 0x85, 0x85, 0x85, 0xff, 0x3b, 0x3b, 0x3b, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0x53, 0x53, 0x53, 0xff, 0x52, 0x52, 0x52, 0xff, 0x52, 0x52, 0x52, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x4c, 0x4c, 0x4c, 0xff, 0x6a, 0x6a, 0x6a, 0xff, 0x64, 0x64, 0x64, 0xff, 0x75, 0x75, 0x75, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x72, 0x72, 0x72, 0xff, 0x52, 0x52, 0x52, 0xff, 0x38, 0x38, 0x38, 0xff, 0x52, 0x52, 0x52, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xea, 0xea, 0xea, 0xff, 0x83, 0x83, 0x83, 0xff, 0x39, 0x39, 0x39, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0x52, 0x52, 0x52, 0xff, 0x53, 0x53, 0x53, 0xff, 0x52, 0x52, 0x52, 0xff, 0x51, 0x51, 0x51, 0xff, 0x52, 0x52, 0x52, 0xff, 0x4f, 0x4f, 0x4f, 0xff, 0x48, 0x48, 0x48, 0xff, 0xb7, 0xb7, 0xb7, 0xff, 0xf8, 0xf8, 0xf8, 0xff, 0x97, 0x97, 0x97, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x6c, 0x6c, 0x6c, 0xff, 0x4b, 0x4b, 0x4b, 0xff, 0x4c, 0x4c, 0x4c, 0xff, 0x4e, 0x4e, 0x4e, 0xff, 0x54, 0x54, 0x54, 0xff, 0x5a, 0x5a, 0x5a, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0x4e, 0x4e, 0x4e, 0xff, 0x54, 0x54, 0x54, 0xff, 0x51, 0x51, 0x51, 0xff, 0x52, 0x52, 0x52, 0xff, 0x51, 0x51, 0x51, 0xff, 0x52, 0x52, 0x52, 0xff, 0x52, 0x52, 0x52, 0xff, 0x4f, 0x4f, 0x4f, 0xff, 0x4b, 0x4b, 0x4b, 0xff, 0xac, 0xac, 0xac, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 
  0x75, 0x75, 0x75, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0x45, 0x45, 0x45, 0xff, 0x53, 0x53, 0x53, 0xff, 0x47, 0x47, 0x47, 0xff, 0x43, 0x43, 0x43, 0xff, 0x4e, 0x4e, 0x4e, 0xff, 0x54, 0x54, 0x54, 0xff, 0x52, 0x52, 0x52, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x52, 0x52, 0x52, 0xff, 0x52, 0x52, 0x52, 0xff, 0x53, 0x53, 0x53, 0xff, 0x51, 0x51, 0x51, 0xff, 0x42, 0x42, 0x42, 0xff, 0xa8, 0xa8, 0xa8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xed, 0xed, 0xed, 0xff, 0xc8, 0xc8, 0xc8, 0xff, 0x54, 0x54, 0x54, 0xff, 0x45, 0x45, 0x45, 0xff, 0x55, 0x55, 0x55, 0xff, 0x54, 0x54, 0x54, 0xff, 0x53, 0x53, 0x53, 0xff, 0x52, 0x52, 0x52, 0xff, 0x52, 0x52, 0x52, 0xff, 0x53, 0x53, 0x53, 0xff, 0x52, 0x52, 0x52, 0xff, 0x52, 0x52, 0x52, 0xff, 0x52, 0x52, 0x52, 0xff, 0x52, 0x52, 0x52, 0xff, 0x4a, 0x4a, 0x4a, 0xff, 0x5f, 0x5f, 0x5f, 0xff, 0xcb, 0xcb, 0xcb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcc, 0xcc, 0xcc, 0xff, 0x4c, 0x4c, 0x4c, 0xff, 0x45, 0x45, 0x45, 0xff, 0x55, 0x55, 0x55, 0xff, 0x52, 0x52, 0x52, 0xff, 0x51, 0x51, 0x51, 0xff, 0x52, 0x52, 0x52, 0xff, 0x53, 0x53, 0x53, 0xff, 0x52, 0x52, 0x52, 0xff, 0x52, 0x52, 0x52, 0xff, 0x53, 0x53, 0x53, 0xff, 0x50, 0x50, 0x50, 0xff, 0x3a, 0x3a, 0x3a, 0xff, 0xad, 0xad, 0xad, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0x54, 0x54, 0x54, 0xff, 0x41, 0x41, 0x41, 0xff, 0x53, 0x53, 0x53, 0xff, 0x52, 0x52, 0x52, 0xff, 0x53, 0x53, 0x53, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x56, 0x56, 0x56, 0xff, 0x4c, 0x4c, 0x4c, 0xff, 0x39, 0x39, 0x39, 0xff, 0x93, 0x93, 0x93, 0xff, 0xed, 0xed, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xce, 0xce, 0xce, 0xff, 0x54, 0x54, 0x54, 0xff, 0x49, 0x49, 0x49, 0xff, 0x54, 0x54, 0x54, 0xff, 0x54, 0x54, 0x54, 0xff, 0x53, 0x53, 0x53, 0xff, 0x47, 0x47, 0x47, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0x50, 0x50, 0x50, 0xff, 0x86, 0x86, 0x86, 0xff, 0xf4, 0xf4, 0xf4, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xce, 0xce, 0xce, 0xff, 0x7e, 0x7e, 0x7e, 0xff, 0x4f, 0x4f, 0x4f, 0xff, 0x4a, 0x4a, 0x4a, 0xff, 0x69, 0x69, 0x69, 0xff, 0x93, 0x93, 0x93, 0xff, 0x3c, 0x3c, 0x3c, 0xff, 0x50, 0x50, 0x50, 0xff, 0xd8, 0xd8, 0xd8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xce, 0xce, 0xce, 0xff, 0x3c, 0x3c, 0x3c, 0xff, 0x59, 0x59, 0x59, 0xff, 0xdc, 0xdc, 0xdc, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x8f, 0x8f, 0xff, 0x50, 0x50, 0x50, 0xff, 0xd2, 0xd2, 0xd2, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc8, 0xc8, 0xc8, 0xff, 0x38, 0x38, 0x38, 0xff, 0xdf, 0xdf, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xf1, 0xf1, 0xff, 0x5f, 0x5f, 0x5f, 0xff, 0xce, 0xce, 0xce, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb6, 0xb6, 0xb6, 0xff, 0x87, 0x87, 0x87, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xf3, 0xf3, 0xff, 0x5f, 0x5f, 0x5f, 0xff, 0xbd, 0xbd, 0xbd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc9, 0xc9, 0xc9, 0xff, 0x31, 0x31, 0x31, 0xff, 0xde, 0xde, 0xde, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf6, 0xf6, 0xf6, 0xff, 0x5c, 0x5c, 0x5c, 0xff, 0x46, 0x46, 0x46, 0xff, 0xe5, 0xe5, 0xe5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
#endif
};

const lv_img_dsc_t New_Dom = {
  .header.cf = LV_IMG_CF_TRUE_COLOR,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 24,
  .header.h = 24,
  .data_size = 576 * LV_COLOR_SIZE / 8,
  .data = New_Dom_map,
};
