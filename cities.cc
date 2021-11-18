/* Aliya Ghassaei and Nina Young
* Implimentation for Cities class
*/
#include "cities.hh"

#include <cmath>
#include <cassert>
#include <iostream>
#include <numeric>
#include <random>
#include <chrono>
#include <algorithm>

Cities::permutation_t random_permutation(unsigned len) {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	static std::default_random_engine generator {seed};
	Cities::permutation_t permutation {len-1};
	std::iota(permutation.begin(), permutation.end(), 0);
	std::shuffle(permutation.begin(), permutation.end(), generator);

	for(unsigned i=0; i < len-1; i++){
   std::cout << permutation.at(i) << ' ';
 }
	return permutation;
}



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
