#pragma once

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*nnp_transform_2d)(const float*, float*, size_t, size_t, uint32_t, uint32_t, uint32_t, uint32_t);
typedef void (*nnp_transform_2d_with_bias)(const float*, float*, const float*, size_t, size_t, uint32_t, uint32_t);

void nnp_fft8x8_and_store__avx2(const float t[], float f[], size_t stride_t, size_t stride_f, uint32_t row_count, uint32_t column_count, uint32_t row_offset, uint32_t column_offset);
void nnp_fft8x8_and_stream__avx2(const float t[], float f[], size_t stride_t, size_t stride_f, uint32_t row_count, uint32_t column_count, uint32_t row_offset, uint32_t column_offset);
void nnp_fft8x8_and_macc__avx2(const float t[], float f[], const float x[], size_t stride_t, uint32_t row_count, uint32_t column_count, uint32_t row_offset, uint32_t column_offset);
void nnp_ifft8x8__avx2(const float f[], float t[], size_t stride_f, size_t stride_t, uint32_t row_count, uint32_t column_count, uint32_t row_offset, uint32_t column_offset);
void nnp_ifft8x8_with_bias__avx2(const float f[], float t[], const float bias[], size_t stride_f, size_t stride_t, uint32_t row_count, uint32_t column_count);

void nnp_fft16x16_and_store__avx2(const float t[], float f[], size_t stride_t, size_t stride_f, uint32_t row_count, uint32_t column_count, uint32_t row_offset, uint32_t column_offset);
void nnp_fft16x16_and_stream__avx2(const float t[], float f[], size_t stride_t, size_t stride_f, uint32_t row_count, uint32_t column_count, uint32_t row_offset, uint32_t column_offset);
void nnp_fft16x16_and_macc__avx2(const float t[], float f[], const float x[], size_t stride_t, uint32_t row_count, uint32_t column_count, uint32_t row_offset, uint32_t column_offset);
void nnp_ifft16x16__avx2(const float f[], float t[], size_t stride_f, size_t stride_t, uint32_t row_count, uint32_t column_count, uint32_t row_offset, uint32_t column_offset);
void nnp_ifft16x16_with_bias__avx2(const float f[], float t[], const float bias[], size_t stride_f, size_t stride_t, uint32_t row_count, uint32_t column_count);

void nnp_iwt8x8_3x3_and_store__avx2(const float d[], float wd[], size_t stride_d, size_t stride_wd, uint32_t row_count, uint32_t column_count, uint32_t row_offset, uint32_t column_offset);
void nnp_iwt8x8_3x3_and_stream__avx2(const float d[], float wd[], size_t stride_d, size_t stride_wd, uint32_t row_count, uint32_t column_count, uint32_t row_offset, uint32_t column_offset);
void nnp_kwt8x8_3x3_and_store__avx2(const float g[], float wg[], size_t stride_g, size_t stride_wg, uint32_t, uint32_t, uint32_t, uint32_t);
void nnp_kwt8x8_3x3_and_stream__avx2(const float g[], float wg[], size_t stride_g, size_t stride_wg, uint32_t, uint32_t, uint32_t, uint32_t);
void nnp_kwt8x8_3x3_and_mac__avx2(const float g[], float wg[], const float x[], size_t stride_g);
void nnp_kwt8x8_3Rx3R_and_store__avx2(const float g[], float wg[], size_t stride_g, size_t stride_wg, uint32_t, uint32_t, uint32_t, uint32_t);
void nnp_kwt8x8_3Rx3R_and_stream__avx2(const float g[], float wg[], size_t stride_g, size_t stride_wg, uint32_t, uint32_t, uint32_t, uint32_t);
void nnp_kwt8x8_3Rx3R_and_mac__avx2(const float g[], float wg[], const float x[], size_t stride_g);
void nnp_owt8x8_3x3__avx2(const float m[], float s[], size_t stride_m, size_t stride_s, uint32_t row_count, uint32_t column_count, uint32_t, uint32_t);
void nnp_owt8x8_3x3_with_bias__avx2(const float m[], float s[], const float bias[], size_t stride_m, size_t stride_s, uint32_t row_count, uint32_t column_count);

void nnp_fft8x8__psimd(const float t[], float f[], size_t stride_t, size_t stride_f, uint32_t row_count, uint32_t column_count, uint32_t row_offset, uint32_t column_offset);
void nnp_fft8x8_and_macc__psimd(const float t[], float f[], const float x[], size_t stride_t, uint32_t row_count, uint32_t column_count, uint32_t row_offset, uint32_t column_offset);
void nnp_ifft8x8__psimd(const float f[], float t[], size_t stride_f, size_t stride_t, uint32_t row_count, uint32_t column_count, uint32_t row_offset, uint32_t column_offset);
void nnp_ifft8x8_with_bias__psimd(const float f[], float t[], const float bias[], size_t stride_f, size_t stride_t, uint32_t row_count, uint32_t column_count);

void nnp_fft16x16__psimd(const float t[], float f[], size_t stride_t, size_t stride_f, uint32_t row_count, uint32_t column_count, uint32_t row_offset, uint32_t column_offset);
void nnp_fft16x16_and_macc__psimd(const float t[], float f[], const float x[], size_t stride_t, uint32_t row_count, uint32_t column_count, uint32_t row_offset, uint32_t column_offset);
void nnp_ifft16x16__psimd(const float f[], float t[], size_t stride_f, size_t stride_t, uint32_t row_count, uint32_t column_count, uint32_t row_offset, uint32_t column_offset);
void nnp_ifft16x16_with_bias__psimd(const float f[], float t[], const float bias[], size_t stride_f, size_t stride_t, uint32_t row_count, uint32_t column_count);

void nnp_iwt8x8_3x3__psimd(const float d[], float wd[], size_t stride_d, size_t stride_wd, uint32_t row_count, uint32_t column_count, uint32_t row_offset, uint32_t column_offset);
void nnp_kwt8x8_3x3__psimd(const float g[], float wg[], size_t stride_g, size_t stride_wg, uint32_t, uint32_t, uint32_t, uint32_t);
void nnp_kwt8x8_3x3_and_mac__psimd(const float g[], float wg[], const float x[], size_t stride_g);
void nnp_kwt8x8_3Rx3R__psimd(const float g[], float wg[], size_t stride_g, size_t stride_wg, uint32_t, uint32_t, uint32_t, uint32_t);
void nnp_owt8x8_3x3__psimd(const float m[], float s[], size_t stride_m, size_t stride_s, uint32_t row_count, uint32_t column_count, uint32_t, uint32_t);
void nnp_owt8x8_3x3_with_bias__psimd(const float m[], float s[], const float bias[], size_t stride_m, size_t stride_s, uint32_t row_count, uint32_t column_count);


/* Convolution */

void nnp_ft8x8gemmc__fma3(float acc[], const float x[], const float y[]);
void nnp_ft16x16gemmc__fma3(float acc[], const float x[], const float y[]);
void nnp_s8x8gemm__fma3(float acc[], const float x[], const float y[]);

#ifdef __cplusplus
} /* extern "C" */
#endif
