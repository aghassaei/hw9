/* Aliya Ghassaei and Nina Young
* Testing Cities class, starting with code from the assignment
*/
#include <iostream>
<<<<<<< HEAD
#include "cities.hh"

int main()
{
  random_permutation(5);
  random_permutation(5);
  random_permutation(5);
  random_permutation(10);
  random_permutation(10);
}
=======
#include <cassert>

#include "cities.hh"

///test if city construction works



>>>>>>> 2b06db1b5d539a05b6ad1b8ef9919a0cdac87294
/*
auto fin = std::ifstream("five.tsv");
Cities cities;
fin >> cities;
std::cout << cities.path_distance({ 0, 1, 2, 3, 4 }) << "\n"; // Should be 48.8699
std::cout << cities.path_distance({ 3, 2, 4, 0, 1 }) << "\n"; // Should be 53.43
*/
<<<<<<< HEAD
=======

int main(){
	// Construct a city
	

	//use bitshift to pull cities 
	assert(not cities.all_pairs.empty()); // Make sure cities constructed itself correctly
	std::cout<<cities<<std::endl;
}
>>>>>>> 2b06db1b5d539a05b6ad1b8ef9919a0cdac87294
