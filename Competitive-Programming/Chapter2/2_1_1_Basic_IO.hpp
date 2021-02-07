#pragma once
#include <iostream>
#include <string>


// ---------------------------- Basic IO ----------------------------

inline void input_output1(){
	int a, b;
	std::string x;
	std::cin >> a >> b >> x;
	std::cout << a << " " << b << " " << x << "\n";
}

// Faster IO (Placed at the beginnning of IO code)
// Note: incompatible with xiosbase
// std::ios_base::sync_with_stdio(0);
// std::cin.tie(0);

// "\n" is faster than std::endl because std::endl causes a flush operation

// Instead of cin/cout, the C functions scanf and printf can be used.  These
// are usually faster. (scanf_s is used in visual studio)
inline void input_output2(){
	int a, b;
	scanf_s("%d %d", &a, &b);
	printf("%d %d\n", a, b);
}

// Read entire input line (including spaces)
inline void input_output3(){
	std::string s;
	std::getline(std::cin, s);
	printf("%s", s.c_str());
}

// Read all available data until there is nothing left in the input:
//while(std::cin >> x){
//	// Code here
//}

// TODO Add file IO
