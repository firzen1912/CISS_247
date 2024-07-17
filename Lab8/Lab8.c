#include <stdio.h>
#include <stdlib.h>

/* access bit-level representation of a floating-point number */
typedef unsigned float_bits;

// function float_class()
//Write a function to identify the class of floating-point number represented by a float_bits parameter:
// parameters:
//      float_bits f
//return:
//      a negative integer(-1), if the floating-point number is a “special” (±∞, or NaN).
//      zero (0), if the floating-point number is denormalized.
//      a positive integer, if the floating-point number is normalized.
int float_class(float_bits f){
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    int is_nan = (exp == 0xFF) && (frac != 0);
    if (is_nan) {
        return -1;
    }
    return exp;
}

// function float_negate()
// this function will compute –f.  If f is Nan, the function should simply return f.
// parameters:
//     float_bits f
//return:
//      negated float_bits f

float_bits float_negate(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int is_nan = (exp == 0xFF) && (frac != 0);
    if (is_nan) {
        return f;
    }
    
    return (~sign << 31) | (exp << 23) | frac;
}

// function float_absval()
//Given a parameter f, this function will compute |f|.  If f is Nan, the function should simply return f.
// parameters:
//      float_bits f
//return:
//      absolute float_bits f

float_bits float_absval(float_bits f) {
    //unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int is_nan = (exp == 0xFF) && (frac != 0);
    if (is_nan) {
        return f;
    }

    return (0 << 31) | exp << 23 | frac;
}

// function float_twice()
//Given a parameter f, this function will compute 2 * f.  If f is Nan, the function should simply return f.
// parameters:
//      float_bits f
//return:
//      Twice of float_bits f

float_bits float_twice(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int is_nan_oo = (exp == 0xFF)&& (frac != 0);
    if (is_nan_oo) {
        return f;
    }

    exp += 1;

    return sign << 31 | exp << 23 | frac;
}

// function float_half()
//Given a parameter f, this function will compute 0.5 * f.  If f is Nan, the function should simply return f.
// parameters:
//      float_bits f
//return:
//      Half of float_bits f

float_bits float_half(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    
    int is_nan = (exp == 0xFF) && (frac != 0);
    if (is_nan) {
        return f;
    }

    exp -= 1;

    return sign << 31 | exp << 23 | frac;
}

int main(){
    float_bits Num;
    printf("Please input a Hexadecimal number\n");
    scanf("%X",&Num);

    printf("\nClass of the number is %d\n", float_class(Num));

    printf("\nNegate of the number is %X\n", float_negate(Num));

    printf("\nAbsolute of the number is %X\n", float_absval(Num));

    printf("\nTwice of the number is %X\n", float_twice(Num));

    printf("\nHalf of the number is %X\n", float_half(Num));

}
