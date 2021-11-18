/* Aliya Ghassaei and Nina Young
* Implimentation for Cities class
*/
#include <cmath>
#include <cassert>

#include "cities.hh"
#include <iostream>
#include <numeric>
#include <random>

<<<<<<< HEAD
//CONSTRUCTOR
Cities::Cities(std::istream& is, std::ostream& os)
	: is_(is), os_(os){}

Cities::permutation_t random_permutation(unsigned len) {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	static std::default_random_engine{seed};
	Cities::permutation_t permutation {len-1};
	std::iota(permutation.begin(), permutation.end(), 0);
	std::shuffle(permutation.begin(), permutation.end(), std::default_random_engine(seed);

	for(unsigned i=0; i < len-1; i++){
   std::cout << permutation.at(i) << ' ';
 }
	return permutation;
}
/*
=======
Cities generate(string filename)
{
    cities_object = Cities();
    //read in from filename
    //assert(not cities_object.empty());
    return cities_object;
  }


>>>>>>> 2b06db1b5d539a05b6ad1b8ef9919a0cdac87294
//TOTAL PATH DISTANCE
//compute the total distance of traversing all the cities in the order defined by the permutation.
//Don't forget to add the distance going back from the last city in the permutation to the first one.
double Cities::total_path_distance(const permutation_t& ordering) const{
	assert(not ordering.empty()); // Make sure that ordering isn't an empty vector
	double total_distance = 0;
	for (unsigned i=0; i<ordering.size(); i++){
		double delta_x = (all_pairs[i].first) - (all_pairs[i+1].first);
		double delta_y = (all_pairs[i].second) - (all_pairs[i+1].second);
		total_distance += std::hypot(delta_x, delta_y);
	}
	return total_distance;

}



/*
//REORDER
Cities::Cities Cities::reorder(const permutation_t& ordering) const{

}
*/
