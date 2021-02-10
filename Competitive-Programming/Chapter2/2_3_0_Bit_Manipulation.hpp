#pragma once
#include <iostream>
#include "../Utility/Utility.hpp"

// Source
// https://www.cprogramming.com/tutorial/bitwise_operators.html

// ===================== Bitwise Precedence: =================

// Precedence   Operator	                    Associativity
// 1 	        ~  (Bitwise negation)	        Right to left
// 2            << (Bitwise LeftShift), >> (Bitwise RightShift)	Left to Right
// 3            &  (Bitwise AND)	            Left to Right
// 4            ^  (Bitwise XOR)	            Left to Right
// 5            |  (Bitwise Or)	                Left to Right

// ===========================================================

// Bit Overview:
// Base 2 (0 or 1)
// Bit basics
// [2^8    2^7    2^6   2^5   2^4   2^3  2^2  2^1  2^0 ]
// [256,   128,   64,   32,   16,   8,   4,   2,   1   ]

// E.g.
// [0,       0,    0,   1,    0,    1,   1,   0,   1   ]
// = 101101
// = 32 + 8 + 4 + 1
// = 45

// -------------- Left and Right Shift Operators --------------

// Operations are performed at the byte level.  Every bitwise operator will
// be applied to an entire byte.  You can still change a single bit at a time.

// Left Shift Operator "<<"
// Moves all bits of a number a specified number of places to the left
// [variable] <<[number of places]
// [00001000]<<[2] = [00100000]

inline void bit_left_shift(int number, int shift_num){
	print("Before: ");
	print(number);
	number = number << shift_num;
	print("After: ");
	print(number);	
}

// What happens if you only have a single byte?
// E.g. 128: 10000000

// Right Shift Operator ">>"

// Shifting left by one is the same as multiplying a number by 2
// Shifting right by one is the same as dividing an INTEGER by 2
// left and right shifting will generally be faster than multiplying


// --------------------- Bitwise AND ------------------------

// Bitwise AND "&"
// 01001000 &
// 00001011
// ___________
// 00001000

inline void bitwise_and(int num1, int num2){
	print(num1 & num2);
}

// ---------------------- Bitwise OR -------------------------

// Bitwise OR "|"
// 01001000
// 10111000
// ______________
// 11111000

inline void bitwise_or(int num1, int num2){
	print(num1 | num2);
}

// Example Use Cases
// Say you had 8 cars you wanted to keep track of

// Say we want to know the status of the '?' car:
// XX?XXXXX
// Using the AND Operator we could do this:
// XX1XXXXX &
// 00100000
// ____________
// 00100000

// The above allows us to find the bit in the nth position.  We get a
// non-zero number if, and only if the bit is a 1.  The next thing to do
// is convert it to a number:
// in_use & 1 << car_num;



int is_in_use(int car_location){

	char in_use = 0;	
	return in_use & 1 << car_location;
	
}