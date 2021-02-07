#pragma once
#include <iostream>
#include <vector>
#include <string>

template <typename T>
inline void print_vector(std::vector<T> vec) {
	std::cout << "{";
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << std::to_string(vec.at(i));
		if(i != vec.size() - 1){
			std::cout << ", ";
		}
	}
	std::cout << "}\n";
}

