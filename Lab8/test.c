#include <stdio.h>
#include <assert.h>
#include <limits.h>

typedef unsigned float_bits;

/* Get bit length for integer i. Return 32 when i is negative. */
int bits_length(int i) {
    if ((i & INT_MIN) != 0) {
        return 32;
    }

    int length = 0;
    unsigned u = (unsigned)i;
    while(u >= (1 << length)) {
        length++;
    }
    return length;
}

/* Generage mask for length len. e.g. 3->0x7 */
unsigned generate_mask(int len) {
    return (unsigned)-1 >> (32-len);
}

float_bits float_i2f(int i) {
    unsigned sign, exp, frac, exp_frac;
    unsigned bias = 0x7F;

    /* i = 0 */
    if (i == 0) {
        sign = 0;
        exp = 0;
        frac = 0;
        return sign << 31 | exp << 23 | frac;
    }

    /* i = INT_MIN */
    if (i == INT_MIN) {
        sign = 1;
        exp = 31 + bias;
        frac = 0;
        return sign << 31 | exp << 23 | frac;
    }

    sign = 0;
    /* i is negative */
    if (i < 0) {
        sign = 1;
        i = -i;
    }

    int length = bits_length(i);
    int flength = length - 1;
    unsigned mask = generate_mask(flength);
    unsigned f = i & mask;
    exp = bias + length - 1;

    if (flength <= 23) {
        /* no overflow */
        frac = f << (23 - flength);
        exp_frac = exp << 23 | frac;
    } else {
        /* overflow */
        int offset = flength - 23;
        frac = f >> offset;
        exp_frac = exp << 23 | frac;
        int round_mid = 1 << (offset - 1);
        int round_part = f & generate_mask(offset);

        /* round to even */
        if (round_part < round_mid) {

        } else if (round_part > round_mid) {
            exp_frac += 1;
        } else {
            if ((frac & 0x1) == 1) {
                exp_frac += 1;
            }
        }
    }
    return sign << 31 | exp_frac;
}

int main() {
    /* Test bits_length */
    assert(bits_length(-1) == 32);
    assert(bits_length(INT_MIN) == 32);
    assert(bits_length(0) == 0);
    assert(bits_length(3) == 2);
    assert(bits_length(23) == 5);

    /* Test generate_mask */
    assert(generate_mask(3) == 0x7);
    assert(generate_mask(9) == 0x1FF);
    assert(generate_mask(31) == 0x7FFFFFFF);

    /* Test float_i2f */
    assert(float_i2f(0) == 0x0);
    assert(float_i2f(INT_MIN) == 0xCF000000);
    assert(float_i2f(0x00359141) == 0x4A564504);
    assert(float_i2f(-98765) == 0xC7C0E680);
    return 0;
}