#include <stddef.h>

#include <nnpack/simd.h>


void nnp_c4gemm1x1__psimd(
	size_t k, size_t k_tile,
	const float a[restrict static 1],
	const float b[restrict static 1],
	float c[restrict static 1],
	size_t row_stride, size_t column_stride)
{
	v4f acc00r = v4f_zero(), acc00i = v4f_zero();
	do {
		const v4f a0r = v4f_ld(a + 0);
		const v4f a0i = v4f_ld(a + 4);

		const v4f b0r = v4f_ld(b + 0);
		acc00r += a0r * b0r;
		acc00i += a0i * b0r;
		const v4f b0i = v4f_ld(b + 4);
		acc00r -= a0i * b0i;
		acc00i += a0r * b0i;

		a += 8;
		b += 8;
	} while (--k);

	if (k_tile != 0) {
		v4f_st(c + 0, v4f_ld(c + 0) + acc00r);
		v4f_st(c + 4, v4f_ld(c + 4) + acc00i);
	} else {
		v4f_st(c + 0, acc00r);
		v4f_st(c + 4, acc00i);
	}
}

void nnp_c4gemm1x2__psimd(
	size_t k, size_t k_tile,
	const float a[restrict static 1],
	const float b[restrict static 1],
	float c[restrict static 1],
	size_t row_stride, size_t column_stride)
{
	v4f acc00r = v4f_zero(), acc00i = v4f_zero();
	v4f acc01r = v4f_zero(), acc01i = v4f_zero();
	do {
		const v4f a0r = v4f_ld(a + 0);
		const v4f a0i = v4f_ld(a + 4);

		const v4f b0r = v4f_ld(b + 0);
		const v4f b1r = v4f_ld(b + 8);
		acc00r += a0r * b0r;
		acc00i += a0i * b0r;
		acc01r += a0r * b1r;
		acc01i += a0i * b1r;
		const v4f b0i = v4f_ld(b +  4);
		const v4f b1i = v4f_ld(b + 12);
		acc00r -= a0i * b0i;
		acc00i += a0r * b0i;
		acc01r -= a0i * b1i;
		acc01i += a0r * b1i;

		a +=  8;
		b += 16;
	} while (--k);

	if (k_tile != 0) {
		v4f_st(c +  0, v4f_ld(c +  0) + acc00r);
		v4f_st(c +  4, v4f_ld(c +  4) + acc00i);
		v4f_st(c +  8, v4f_ld(c +  8) + acc01r);
		v4f_st(c + 12, v4f_ld(c + 12) + acc01i);
	} else {
		v4f_st(c +  0, acc00r);
		v4f_st(c +  4, acc00i);
		v4f_st(c +  8, acc01r);
		v4f_st(c + 12, acc01i);
	}
}

void nnp_c4gemm2x1__psimd(
	size_t k, size_t k_tile,
	const float a[restrict static 1],
	const float b[restrict static 1],
	float c[restrict static 1],
	size_t row_stride, size_t column_stride)
{
	v4f acc00r = v4f_zero(), acc00i = v4f_zero();
	v4f acc10r = v4f_zero(), acc10i = v4f_zero();
	do {
		const v4f a0r = v4f_ld(a +  0);
		const v4f a0i = v4f_ld(a +  4);
		const v4f a1r = v4f_ld(a +  8);
		const v4f a1i = v4f_ld(a + 12);

		const v4f b0r = v4f_ld(b + 0);
		acc00r += a0r * b0r;
		acc00i += a0i * b0r;
		acc10r += a1r * b0r;
		acc10i += a1i * b0r;
		const v4f b0i = v4f_ld(b + 4);
		acc00r -= a0i * b0i;
		acc00i += a0r * b0i;
		acc10r -= a1i * b0i;
		acc10i += a1r * b0i;

		a += 16;
		b +=  8;
	} while (--k);

	if (k_tile != 0) {
		v4f_st(c +  0, v4f_ld(c +  0) + acc00r);
		v4f_st(c +  4, v4f_ld(c +  4) + acc00i);
		v4f_st(c +  8, v4f_ld(c +  8) + acc10r);
		v4f_st(c + 12, v4f_ld(c + 12) + acc10i);
	} else {
		v4f_st(c +  0, acc00r);
		v4f_st(c +  4, acc00i);
		v4f_st(c +  8, acc10r);
		v4f_st(c + 12, acc10i);
	}
}

void nnp_c4gemm2x2__psimd(
	size_t k, size_t k_tile,
	const float a[restrict static 1],
	const float b[restrict static 1],
	float c[restrict static 1],
	size_t row_stride, size_t column_stride)
{
	v4f acc00r = v4f_zero(), acc00i = v4f_zero();
	v4f acc01r = v4f_zero(), acc01i = v4f_zero();
	v4f acc10r = v4f_zero(), acc10i = v4f_zero();
	v4f acc11r = v4f_zero(), acc11i = v4f_zero();
	do {
		const v4f a0r = v4f_ld(a +  0);
		const v4f a0i = v4f_ld(a +  4);
		const v4f a1r = v4f_ld(a +  8);
		const v4f a1i = v4f_ld(a + 12);

		const v4f b0r = v4f_ld(b + 0);
		const v4f b1r = v4f_ld(b + 8);
		acc00r += a0r * b0r;
		acc00i += a0i * b0r;
		acc01r += a0r * b1r;
		acc01i += a0i * b1r;
		acc10r += a1r * b0r;
		acc10i += a1i * b0r;
		acc11r += a1r * b1r;
		acc11i += a1i * b1r;
		const v4f b0i = v4f_ld(b +  4);
		const v4f b1i = v4f_ld(b + 12);
		acc00r -= a0i * b0i;
		acc00i += a0r * b0i;
		acc01r -= a0i * b1i;
		acc01i += a0r * b1i;
		acc10r -= a1i * b0i;
		acc10i += a1r * b0i;
		acc11r -= a1i * b1i;
		acc11i += a1r * b1i;

		a += 16;
		b += 16;
	} while (--k);

	if (k_tile != 0) {
		v4f_st(c +  0, v4f_ld(c +  0) + acc00r);
		v4f_st(c +  4, v4f_ld(c +  4) + acc00i);
		v4f_st(c +  8, v4f_ld(c +  8) + acc01r);
		v4f_st(c + 12, v4f_ld(c + 12) + acc01i);
		v4f_st(c + 16, v4f_ld(c + 16) + acc10r);
		v4f_st(c + 20, v4f_ld(c + 20) + acc10i);
		v4f_st(c + 24, v4f_ld(c + 24) + acc11r);
		v4f_st(c + 28, v4f_ld(c + 28) + acc11i);
	} else {
		v4f_st(c +  0, acc00r);
		v4f_st(c +  4, acc00i);
		v4f_st(c +  8, acc01r);
		v4f_st(c + 12, acc01i);
		v4f_st(c + 16, acc10r);
		v4f_st(c + 20, acc10i);
		v4f_st(c + 24, acc11r);
		v4f_st(c + 28, acc11i);
	}
}
