#pragma once
#include <iostream>

// Source
// Guide to Competitive Programming by Antti Laaksonen

// -------------------- Integers -----------------

// Most common type in competitive programming:
// 32bit int: -2^31...2^31;
// When 32bit isn't enough, it is common to use the 64bit long long:
// e.g.: long long x = 123456789123456789LL

// Common Error:
inline void numeric_1(){
	int a = 123456789;
	long long b = a * a;
	std::cout << b << "\n"; // -1757895781
}

// The above is incorrect because both numbers in the expression are ints!
// This will result in the type int.  The correct way to do the above is to
// change a to long long.

// Rarely 64bit is not enough.  In those cases, the g++ compiler provides the
// 128bit type:
// __int128_t: -2^127...2^d127;


// -------------- Modular Arithmetic --------------

// There are times when the answer to a problem is a very large number, but it
// is enough to output it (modulo m) -> The remainder.  If the answer is very
// large, it sometimes is enough to simply output the remainder and use types
// int or long long.

// x mod m
// 17 mod 5 = 2; 17/5 == 3 rm 2.

// Modulo Properties:
// (a + b) mod m = (a mod m + b mod 5) mod m;
// (a - b) mod m = (a mod m - b mod 5) mod m;
// (a * b) mod m = (a mod m * b mod 5) mod m;
//
// E.g.
// (a  +  b) mod m = (a  mod m + b  mod 5) mod m;
// (10 + 12) mod 3 = (10 mod 3 + 12 mod 3) mod 3
// LHS: 22 mod 3 == 1;
// RHS: (10 mod 3) == 1; 12 mod 3 == 0; (1+0) mod 3 == 1;

// The aboe shows we can take the remainder after every operation and the
// numbers will never become too large.

// Negative numbers
// Usually you want the remainder to be between 0 and m - 1.  However, C++
// will output the remainder of a negative number as 0 or negative.  A simple
// solution:
// x = x % m;
// if(x < 0) x += m;
// The above is only necessary when there is subtraction in the code and the
// remainder may become negative


// -------------- Floating Point Numbers --------------

// Typically the 64bit double or the 80bit long double is used
// The easiest way to output is to format the number of decimal places in the
// string using printf

inline void numeric_2(){
	double x = 1.456789456;
	printf("%.9f\n", x);
}

// Rounding errors
// x should be one below, but we see its slightly smaller than 1:
inline void numeric_3(){
	double x = 0.3 * 3 + 0.1;
	printf("%.20f\n", x);
}
// The above shows that it is risky to use the == operator on floats, as the 
// precision error will make them appear not equal.  To compare floats instead,
// assume the two numbers are euqal if they difference is less than alpha,
// where alpha is a small number: E.g. alpha = 10^-9;

inline bool numeric_4_are_floats_equal(float float_one, float float_two){
	return abs(float_one - float_two) < 1e-9;
}