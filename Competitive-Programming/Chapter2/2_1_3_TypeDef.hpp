#pragma once
#include <vector>
#include <utility>


// ----------------------------- Typedef -----------------------------

// Rather than using long long, we can shorten this:
typedef long long ll;

inline void typedef_1(){
	ll a = 123456789;
	ll b = 123456789;
	std::cout << a * b << "\n";	
}

// typedef can be used for complex types
typedef std::vector<int> vi;
typedef std::pair<int, int> pi;

