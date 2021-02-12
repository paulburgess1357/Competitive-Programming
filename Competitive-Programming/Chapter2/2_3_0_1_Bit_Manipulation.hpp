#pragma once
#include "../Utility/Utility.hpp"

// Source 
// https://www.cprogramming.com/tutorial/bitwise_operators.html

// ===================== Bitwise Precedence: =================

// Precedence   Operator                                        Associativity
// 1            ~  (Bitwise negation)                           Right to left
// 2            << (Bitwise LeftShift), >> (Bitwise RightShift) Left to Right
// 3            &  (Bitwise AND)                                Left to Right
// 4            ^  (Bitwise XOR)                                Left to Right
// 5            |  (Bitwise OR)                                 Left to Right

// ===========================================================


// --------------------- Bit Overview ---------------------
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
// Both positions need to be a 1 for the result position to be a 1.

// Bitwise AND "&"
// 01001000 &
// 00001011
// ___________
// 00001000

inline void bitwise_and(int num1, int num2){
	print(num1 & num2);
}


// ---------------------- Bitwise OR -------------------------
// Only one bit needs to be a 1 for the result position to be a 1.

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

// Check if car is in use
inline int is_in_use(int car_location){

	//I.E. 00000000
	char in_use = 0;	

	// Start with the number 1 (because this is a single bit)
	// Shift '1' over by 'car_location' slots (shifting left)
	// Car '0' is the rightmost bit.
	// Car '1' is the next bit to the left
	// Car '2' is the next bit to the left (from car 1) etc.

	// So we have:
	//                           in_use = 00000000 &
	// 1 bit =  00000001; Shift(ex. 3):   00001000
	// Result =                           00000000

	
	char result = in_use & 1 << car_location;

	// Left shift takes precedence over '&'
	// Shift left then do &
	return in_use & 1 << car_location;	
}

// The above allows us to check if a car is in use.  However, we still need to
// be able to set a car in use.  We can use the or "|" operator to do this

inline void set_in_use(int car_location){

	// I.E. 00000000
	char in_use = 0;

	// Set the 4th car in use:
	// 00000000
	// 00000001 << 4 = 00010000
	// in_use = 00010000;
	
	in_use = in_use | 1 << car_location;
	print(in_use);		
}

// At this point we can check if a car is in use and we can set a car in use.
// However, we need to be able to set a car to be NOT in use.  To do this, we
// need another operator


// --------------------- Bitwise Complement ------------------------
// The complement operator '~' flips every bit.  If you have a one it becomes
// a zero.  If you have a zero it becomes a one.  EVERY bit is changed.

// For example, you could find the largest value of an unsigned number.  The
// below would change all the bits to 1.
// unsigned int max = ~0;

// ** You cannot use ! and ~ interchangeably **.  When you take the logical
// NOT of a non-zero number, you get 0 (FALSE).

// Lets attempt to turn off a SINGLE bit (and leave all other bits unaffected)

// char 0: 00000000
// 1:      00000001
// car_location (4): Shift 1 over 4: 00010000
// Take existing car locations (say it looks like this: 01011100)
// ~00010000 (this will flip the bits:)
//
// 01011100 &
// 11101111
// __________
// 01001100
// We went from:
// 01011100 to:
// 01001100
// We turned off the 4th bit!
inline void turn_off(int car_location){
	char in_use = 0; // imagine this is actually: 01011100;

	// First shift (<<), then flip values(~), then AND:
	in_use = in_use & ~(1 << car_location);
}


// The above works.  If a car is in use, it will be turned off.  If a 
// car is NOT in use, it will remain a 0.
// e.g. slot 4 (not in use when running the function):
// 01010100 &
// 11110111 (already shifted 1 over 4 and take complement)
// ________
// 01010100 // Slot 4 remains off

// However, you can see this is a bit clunky.  It would be better to actually
// check if the car is in use.  This is where the bitwise exclusive-or (XOR)
// comes into play


// ------------------ Bitwise Exclusive-Or (XOR) -------------------------
// If BOTH inputs are 1 OR IF BOTH inputs 0, return 0

// 01110010 ^
// 10101010
// ________
// 11011000

// bit_value XOR 0 --> Returns the bit_value back to us;
// A = 1
// A XOR 0 = 1
// 
// bit_value XOR 1 --> Returns the opposite bit_value back to us
// A = 1;
// A XOR 1 = 0;

// How can this help us? XORing a bit with 0 results in the same bit.  Ideally,
// we'd like to call one function that flips the bit of the car we are interested
// in.  The remaining bits should remain unchanged.

void flip_bit(int car_location){

	char in_use = 0; // Imagine this is 01110101

	// Say we want to flip the 4th bit:
	// 01110101
	// 1 << car_location(4) = 00001000
	// _______________________________
	//
	// 01110101 ^
	// 00001000
	// __________
	// 01111101

	// First shift (<<) then XOR:
	in_use = in_use ^ 1 << car_location;	
}

// Summary
// When should you use bitwise operators?
// Save space
// Remove dependencies (e.g. ~0 to find the largest possible integer)
// Bit shifting to multiply by 2
// Compression or Encryptions