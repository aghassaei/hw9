/* Aliya Ghassaei and Nina Young
* Testing Cities class, starting with code from the assignment
*/
#include <iostream>
#include <cassert>

#include "cities.hh"

///test if city construction works



/*
auto fin = std::ifstream("five.tsv");
Cities cities;
fin >> cities;
std::cout << cities.path_distance({ 0, 1, 2, 3, 4 }) << "\n"; // Should be 48.8699
std::cout << cities.path_distance({ 3, 2, 4, 0, 1 }) << "\n"; // Should be 53.43
*/

int main(){
	// Construct a city
	

	//use bitshift to pull cities 
	assert(not cities.all_pairs.empty()); // Make sure cities constructed itself correctly
	std::cout<<cities<<std::endl;
}