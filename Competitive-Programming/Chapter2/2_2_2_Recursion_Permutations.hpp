#pragma once
#include <vector>
#include <algorithm>
#include "../Utility/Utility.hpp"

// Source:
// https://algotree.org/algorithms/recursive/permutations_recursion/

inline void generate_permutations(std::vector<int>& permutation, std::vector<int>& base_elements, std::vector<bool>& position_taken){

	if(permutation.size() == base_elements.size()){
		print_vector(permutation);
	} else{


		for(size_t i = 0; i < base_elements.size(); i++){

			// If position has been taken, move on to the next element
			if(position_taken.at(i)){
				continue;
			}

			// Set current position as taken
			position_taken.at(i) = true;

			// Add current element into the permutation vector
			permutation.push_back(base_elements.at(i));

			// Continue on to the next element(s)
			generate_permutations(permutation, base_elements, position_taken);

			// In order to reach this point, the stopping condition must
			// have been reached (far within the function calls)

			// Remove the last added element
			permutation.pop_back();

			// Set the position as not taken
			position_taken.at(i) = false;
						
		}		
		
	}

}

inline void recursion_permutations(){
	std::vector<int> base_elements {4, 8, 1, 3};
	std::vector<int> permutation;
	std::vector<bool> position_taken (base_elements.size(), false);
	generate_permutations(permutation, base_elements, position_taken);
}

// Using C++ standard library
// Source: http://www.cplusplus.com/reference/algorithm/next_permutation/

inline void recursion_permutations_2(){
	int myints[] = { 1,2,3 };
	std::sort(myints, myints + 3);;
	
	std::cout << "The 3! possible permutations with 3 elements:\n";
	do {
		std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
	} while (std::next_permutation(myints, myints + 3));

	std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
}