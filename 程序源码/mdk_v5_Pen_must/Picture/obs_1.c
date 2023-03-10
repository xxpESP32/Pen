#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_OBS_1
#define LV_ATTRIBUTE_IMG_OBS_1
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_OBS_1 uint8_t obs_1_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
  0xff, 0xff, 0xff, 0xff, 0x6e, 0x49, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x49, 0x49, 0x49, 0xb6, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x49, 0x6d, 0x49, 0xb6, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x49, 0x6d, 0x49, 0xb6, 0xff, 0x6e, 0x49, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x49, 0x6d, 0x49, 0xb6, 0xff, 0x6d, 0x49, 0xff, 
  0x6e, 0xb6, 0xff, 0xff, 0x49, 0x49, 0x49, 0xb6, 0xff, 0x6d, 0x49, 0xff, 
  0x49, 0x6d, 0xff, 0xff, 0x49, 0x6e, 0x49, 0xb7, 0xff, 0x6d, 0x49, 0xff, 
  0x49, 0x6e, 0xff, 0xff, 0x49, 0x49, 0x49, 0xb6, 0xff, 0x6d, 0x49, 0xff, 
  0x49, 0x92, 0xff, 0xff, 0x49, 0x6d, 0x49, 0x92, 0xff, 0x6e, 0x25, 0xff, 
  0x49, 0x6e, 0xff, 0xff, 0x49, 0x6d, 0x6d, 0x49, 0x49, 0x49, 0x92, 0xff, 
  0x49, 0x6e, 0xff, 0xff, 0x49, 0x6d, 0x49, 0x6e, 0xb6, 0xb7, 0xff, 0xff, 
  0x6d, 0x6d, 0x92, 0x6e, 0x6d, 0x6d, 0x49, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0x92, 0x6e, 0x6d, 0x49, 0x6d, 0x49, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x49, 0x6d, 0x6d, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x49, 0x49, 0x49, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x49, 0x6d, 0x49, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x49, 0x6e, 0x49, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x49, 0x6d, 0x49, 0xff, 0xff, 0xff, 0xff, 0xff, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x2d, 0x6b, 0xe8, 0x41, 0xcf, 0x7b, 0x3d, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x49, 0x4a, 0x8a, 0x52, 0x28, 0x42, 0x92, 0x94, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0x39, 0x0c, 0x63, 0x08, 0x42, 0xd3, 0x9c, 0xff, 0xff, 0xdf, 0xff, 0xbe, 0xf7, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x08, 0x42, 0xeb, 0x5a, 0x49, 0x4a, 0x14, 0xa5, 0xff, 0xff, 0x6e, 0x73, 0xe8, 0x41, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x69, 0x4a, 0x8a, 0x52, 0x08, 0x42, 0xb2, 0x94, 0xff, 0xff, 0xcb, 0x5a, 0x86, 0x31, 0xff, 0xff, 
  0x2c, 0x63, 0xf3, 0x9c, 0xff, 0xff, 0xff, 0xff, 0x08, 0x42, 0x6a, 0x52, 0x49, 0x4a, 0x14, 0xa5, 0xff, 0xff, 0xeb, 0x5a, 0x28, 0x42, 0xff, 0xff, 
  0x6a, 0x52, 0xeb, 0x5a, 0xff, 0xff, 0xff, 0xff, 0xc7, 0x39, 0x2d, 0x6b, 0x29, 0x4a, 0x14, 0xa5, 0xff, 0xff, 0xcb, 0x5a, 0x69, 0x4a, 0xff, 0xff, 
  0xc7, 0x39, 0x2c, 0x63, 0xff, 0xff, 0xff, 0xff, 0x28, 0x42, 0x69, 0x4a, 0x69, 0x4a, 0xf4, 0xa4, 0xff, 0xff, 0xab, 0x5a, 0x49, 0x4a, 0xff, 0xff, 
  0xe7, 0x39, 0xaf, 0x7b, 0xff, 0xff, 0xff, 0xff, 0x69, 0x4a, 0x8a, 0x52, 0x8a, 0x52, 0x30, 0x84, 0x1c, 0xe7, 0x4d, 0x6b, 0x65, 0x29, 0xff, 0xff, 
  0x29, 0x4a, 0x4d, 0x6b, 0xff, 0xff, 0xff, 0xff, 0xe8, 0x41, 0x0c, 0x63, 0xcb, 0x5a, 0x6a, 0x52, 0x6a, 0x52, 0x49, 0x4a, 0x30, 0x84, 0xff, 0xff, 
  0x08, 0x42, 0x2d, 0x6b, 0xff, 0xff, 0xff, 0xff, 0x69, 0x4a, 0xeb, 0x5a, 0x49, 0x4a, 0x4d, 0x6b, 0xf3, 0x9c, 0x55, 0xad, 0xff, 0xff, 0xff, 0xff, 
  0x8a, 0x52, 0xcb, 0x5a, 0x51, 0x8c, 0x2d, 0x6b, 0xcb, 0x5a, 0xec, 0x62, 0x08, 0x42, 0xfc, 0xe6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xbf, 0xff, 0xae, 0x73, 0x4d, 0x6b, 0xaa, 0x52, 0x6a, 0x52, 0xec, 0x62, 0x28, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6a, 0x52, 0xaa, 0x52, 0x8a, 0x52, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8a, 0x52, 0x28, 0x42, 0x49, 0x4a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x28, 0x42, 0xcb, 0x5a, 0x28, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x08, 0x42, 0x0c, 0x63, 0x08, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0x39, 0xeb, 0x5a, 0x49, 0x4a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Red: 5 bit, Green: 6 bit, Blue: 5 bit BUT the 2 bytes are swapped*/
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6b, 0x2d, 0x41, 0xe8, 0x7b, 0xcf, 0xef, 0x3d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x4a, 0x49, 0x52, 0x8a, 0x42, 0x28, 0x94, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x39, 0xe7, 0x63, 0x0c, 0x42, 0x08, 0x9c, 0xd3, 0xff, 0xff, 0xff, 0xdf, 0xf7, 0xbe, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x42, 0x08, 0x5a, 0xeb, 0x4a, 0x49, 0xa5, 0x14, 0xff, 0xff, 0x73, 0x6e, 0x41, 0xe8, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x4a, 0x69, 0x52, 0x8a, 0x42, 0x08, 0x94, 0xb2, 0xff, 0xff, 0x5a, 0xcb, 0x31, 0x86, 0xff, 0xff, 
  0x63, 0x2c, 0x9c, 0xf3, 0xff, 0xff, 0xff, 0xff, 0x42, 0x08, 0x52, 0x6a, 0x4a, 0x49, 0xa5, 0x14, 0xff, 0xff, 0x5a, 0xeb, 0x42, 0x28, 0xff, 0xff, 
  0x52, 0x6a, 0x5a, 0xeb, 0xff, 0xff, 0xff, 0xff, 0x39, 0xc7, 0x6b, 0x2d, 0x4a, 0x29, 0xa5, 0x14, 0xff, 0xff, 0x5a, 0xcb, 0x4a, 0x69, 0xff, 0xff, 
  0x39, 0xc7, 0x63, 0x2c, 0xff, 0xff, 0xff, 0xff, 0x42, 0x28, 0x4a, 0x69, 0x4a, 0x69, 0xa4, 0xf4, 0xff, 0xff, 0x5a, 0xab, 0x4a, 0x49, 0xff, 0xff, 
  0x39, 0xe7, 0x7b, 0xaf, 0xff, 0xff, 0xff, 0xff, 0x4a, 0x69, 0x52, 0x8a, 0x52, 0x8a, 0x84, 0x30, 0xe7, 0x1c, 0x6b, 0x4d, 0x29, 0x65, 0xff, 0xff, 
  0x4a, 0x29, 0x6b, 0x4d, 0xff, 0xff, 0xff, 0xff, 0x41, 0xe8, 0x63, 0x0c, 0x5a, 0xcb, 0x52, 0x6a, 0x52, 0x6a, 0x4a, 0x49, 0x84, 0x30, 0xff, 0xff, 
  0x42, 0x08, 0x6b, 0x2d, 0xff, 0xff, 0xff, 0xff, 0x4a, 0x69, 0x5a, 0xeb, 0x4a, 0x49, 0x6b, 0x4d, 0x9c, 0xf3, 0xad, 0x55, 0xff, 0xff, 0xff, 0xff, 
  0x52, 0x8a, 0x5a, 0xcb, 0x8c, 0x51, 0x6b, 0x2d, 0x5a, 0xcb, 0x62, 0xec, 0x42, 0x08, 0xe6, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xbf, 0x73, 0xae, 0x6b, 0x4d, 0x52, 0xaa, 0x52, 0x6a, 0x62, 0xec, 0x42, 0x28, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x52, 0x6a, 0x52, 0xaa, 0x52, 0x8a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x52, 0x8a, 0x42, 0x28, 0x4a, 0x49, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x42, 0x28, 0x5a, 0xcb, 0x42, 0x28, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x42, 0x08, 0x63, 0x0c, 0x42, 0x08, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x39, 0xe7, 0x5a, 0xeb, 0x4a, 0x49, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
#endif
#if LV_COLOR_DEPTH == 32
  /*Pixel format: Fix 0xFF: 8 bit, Red: 8 bit, Green: 8 bit, Blue: 8 bit*/
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x65, 0x65, 0x65, 0xff, 0x3d, 0x3d, 0x3d, 0xff, 0x76, 0x76, 0x76, 0xff, 0xe5, 0xe5, 0xe5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0x47, 0x47, 0x47, 0xff, 0x4e, 0x4e, 0x4e, 0xff, 0x42, 0x42, 0x42, 0xff, 0x91, 0x91, 0x91, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3b, 0x3b, 0x3b, 0xff, 0x5e, 0x5e, 0x5e, 0xff, 0x40, 0x40, 0x40, 0xff, 0x99, 0x99, 0x99, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf6, 0xf6, 0xf6, 0xff, 0xf2, 0xf2, 0xf2, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3e, 0x3e, 0x3e, 0xff, 0x5b, 0x5b, 0x5b, 0xff, 0x46, 0x46, 0x46, 0xff, 0x9e, 0x9e, 0x9e, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6c, 0x6c, 0x6c, 0xff, 0x3d, 0x3d, 0x3d, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x4a, 0x4a, 0x4a, 0xff, 0x50, 0x50, 0x50, 0xff, 0x3e, 0x3e, 0x3e, 0xff, 0x93, 0x93, 0x93, 0xff, 0xff, 0xff, 0xff, 0xff, 0x59, 0x59, 0x59, 0xff, 0x31, 0x31, 0x31, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x63, 0x63, 0x63, 0xff, 0x9a, 0x9a, 0x9a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x3f, 0x3f, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0x49, 0x49, 0x49, 0xff, 0x9f, 0x9f, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x5a, 0x5a, 0x5a, 0xff, 0x42, 0x42, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x4d, 0x4d, 0x4d, 0xff, 0x5b, 0x5b, 0x5b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x38, 0x38, 0x38, 0xff, 0x65, 0x65, 0x65, 0xff, 0x44, 0x44, 0x44, 0xff, 0xa0, 0xa0, 0xa0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x56, 0x56, 0x56, 0xff, 0x4b, 0x4b, 0x4b, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x38, 0x38, 0x38, 0xff, 0x63, 0x63, 0x63, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x43, 0x43, 0x43, 0xff, 0x4b, 0x4b, 0x4b, 0xff, 0x4b, 0x4b, 0x4b, 0xff, 0x9d, 0x9d, 0x9d, 0xff, 0xff, 0xff, 0xff, 0xff, 0x54, 0x54, 0x54, 0xff, 0x48, 0x48, 0x48, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x3a, 0x3a, 0x3a, 0xff, 0x74, 0x74, 0x74, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x4b, 0x4b, 0x4b, 0xff, 0x51, 0x51, 0x51, 0xff, 0x4f, 0x4f, 0x4f, 0xff, 0x83, 0x83, 0x83, 0xff, 0xde, 0xde, 0xde, 0xff, 0x67, 0x67, 0x67, 0xff, 0x2b, 0x2b, 0x2b, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x44, 0x44, 0x44, 0xff, 0x67, 0x67, 0x67, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3c, 0x3c, 0x3c, 0xff, 0x5f, 0x5f, 0x5f, 0xff, 0x59, 0x59, 0x59, 0xff, 0x4c, 0x4c, 0x4c, 0xff, 0x4c, 0x4c, 0x4c, 0xff, 0x47, 0x47, 0x47, 0xff, 0x83, 0x83, 0x83, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x3e, 0x3e, 0x3e, 0xff, 0x64, 0x64, 0x64, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x4b, 0x4b, 0x4b, 0xff, 0x5a, 0x5a, 0x5a, 0xff, 0x48, 0x48, 0x48, 0xff, 0x67, 0x67, 0x67, 0xff, 0x9b, 0x9b, 0x9b, 0xff, 0xa8, 0xa8, 0xa8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x51, 0x51, 0x51, 0xff, 0x59, 0x59, 0x59, 0xff, 0x89, 0x89, 0x89, 0xff, 0x64, 0x64, 0x64, 0xff, 0x57, 0x57, 0x57, 0xff, 0x5d, 0x5d, 0x5d, 0xff, 0x3f, 0x3f, 0x3f, 0xff, 0xdc, 0xdc, 0xdc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xf4, 0xf4, 0xf4, 0xff, 0x72, 0x72, 0x72, 0xff, 0x68, 0x68, 0x68, 0xff, 0x52, 0x52, 0x52, 0xff, 0x4c, 0x4c, 0x4c, 0xff, 0x5c, 0x5c, 0x5c, 0xff, 0x42, 0x42, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x4c, 0x4c, 0x4c, 0xff, 0x53, 0x53, 0x53, 0xff, 0x50, 0x50, 0x50, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x4e, 0x4e, 0x4e, 0xff, 0x42, 0x42, 0x42, 0xff, 0x47, 0x47, 0x47, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x42, 0x42, 0x42, 0xff, 0x57, 0x57, 0x57, 0xff, 0x42, 0x42, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x41, 0x41, 0x41, 0xff, 0x61, 0x61, 0x61, 0xff, 0x40, 0x40, 0x40, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3b, 0x3b, 0x3b, 0xff, 0x5b, 0x5b, 0x5b, 0xff, 0x48, 0x48, 0x48, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
#endif
};

const lv_img_dsc_t obs_1 = {
  .header.cf = LV_IMG_CF_TRUE_COLOR,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 12,
  .header.h = 18,
  .data_size = 216 * LV_COLOR_SIZE / 8,
  .data = obs_1_map,
};
