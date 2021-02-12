#pragma once
#include "../Utility/Utility.hpp"

// Source
// Guide to Competitive Programming by Antti Laaksonen


// -------------- Signed vs Unsigned Bit Representation --------------------
// The most significant bit (far left) is used as the sign bit.  If the sign
// bit is 0, this means the number is positive.  If the signed bit is 1, this
// means the number is negative.

// E.g. 8bit signed number
// [sign, 64, 32, 16, 8, 4, 2, 1]
// [0   ,  0,   1, 1 ,0, 1, 0, 1] = + 53
// [1   ,  0,   1, 1, 0, 1, 0, 1] = -53
// Note that with a signed number, we can see the reduction in digits due
// to the leftmost bit being the sign instead of 128

// An unsigned variable of 'n' bits can be any interger from 0 to 2^n - 1

// ---------------- Relationship between signed and unsigned -----------------
// The signed numbeer "-x" equals the unsigned number: 2^n - x
// E.g. int x = -43
// unsigned int y = 2^32 - 43

// ------------------------------- Size --------------------------------------
// IF a number is larger than the upper bound of the bit representation, the
// number will overflow:
