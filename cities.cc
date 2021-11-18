/* Aliya Ghassaei and Nina Young
* Implimentation for Cities class
*/

#include "cities.hh"
#include <iostream>
#include <numeric>
#include <random>

//CONSTRUCTOR
Cities::Cities(std::istream& is, std::ostream& os)
	: is_(is), os_(os){}

Cities::permutation_t random_permutation(unsigned len) {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	static std::default_random_engine{seed};
	Cities::permutation_t permutation {len-1};
	std::iota(permutation.begin(), permutation.end(), 0);
	std::shuffle(permutation.begin(), permutation.end(), std::default_random_engine(seed));

	for(unsigned i=0; i < len-1; i++){
   std::cout << permutation.at(i) << ' ';
 }
	return permutation;
}
/*
//TOTAL PATH DISTANCE
//should there be two consts in here
//compute the total distance of traversing all the cities in the order defined by the permutation.
//Don't forget to add the distance going back from the last city in the permutation to the first one.
double Cities::total_path_distance(const permutation_t& ordering) const{

}
*/

/*
//REORDER
Cities::Cities Cities::reorder(const permutation_t& ordering) const{

}
*/
