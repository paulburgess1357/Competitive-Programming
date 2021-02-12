#pragma once
#include "Utility/Utility.hpp"
#include <vector>

// Source
// https://algotree.org/algorithms/recursive/subsets_recursion/

// Generate all subsets of a set of n elements using recursion
// Superset = {1, 2}
// Subset 1: {1, 2}
// Subset 2: {1}
// Subset 3: {2}
// Subset 4: {}

// Superset of size N.
// 1.   Generate_Subsets(int R)
// 2.       If(R == N + 1)
// 3.          Print the subset V.
// 4.       Else
// 5.           // Include R in the subset and generate next subset
//              V.push_back(R);
//              Generate_Subsets(R + 1);
//              // Do not include R in the subset and generate next subset
//              V.pop_back();
//              Generate_Subsets(R + 1);

// For example:
// Superset { 1, 2 }
// N = 2 (size of superset)
// Function starts at 1:
// Comments display current subset value:
// ******* {} ********


// 1) Call Generate_Subsets with 1 
//    Push 1 into the subset; ****** { 1 } ******
//    1.1.0) Call Generate_Subsets with 2
//         Push 2 into the subset; ****** { 1 , 2 } ******
//         1.2.0) Call Generate_Subsets with 3
//              Since 3 is > 2: Print the subset ----------> Prints { 1, 2 }
//              Return (to 1.1.0)
//    1.1.0 cont. ) Pop 2 from the subset; ****** { 1 } ******
//         1.1.1) Call Generate Subsets with 3
//         Since 3 is > 2: Print the subset ---------------> Prints { 1 }
//         Return to 1.1.0
//    Return to 1
//    
//    Pop 1 from the subset; ****** { } ******
//    1.1.1) Call Generate Subsets with 2
//           Push 2 into the subset; ****** { 2 } ******
//           1.1.2) Call Generate Subsets with 3
//                  Since 3 > 2: Print the subset ----------> Prints { 2 }
//                  Return to 1.1.1
//           Pop 2 from the subset; ****** {  } ******
//           1.1.3) Call Generate Subsets with 3
//                  Since 3 > 2: Print the subset ----------> Prints { } (empty)       


// vec:        Vector used to store subset values.  Values are added and removed
//             since we are only printing them.  In practice, you may want to
//             actually store these values
// val:        Starting value of the recursive function.  Val gets added to the
//             vector unless it is larger than set_size
// set_size:   This is the size of the set.  When we add values, we check that the
//             added value is not > than the set size (in this example, sets start
//             from 1...set_size).
//             {1, 2}: set_size = 2
//             {1, 2, 3}: set_size = 3;

inline void generate_subsets(std::vector<int>& vec, int val, int set_size){

	if(val == set_size + 1){
		print_vector(vec);
	} else{
		vec.push_back(val);
		generate_subsets(vec, val + 1, set_size);
		vec.pop_back();
		generate_subsets(vec, val + 1, set_size);
	}
	
}

inline void recursion_subset_elements(int set_size) {
	std::vector<int> subset_values;
	generate_subsets(subset_values, 1, set_size);
}