/* Aliya Ghassaei and Nina Young 
* Implimentation for Cities class
*/
#include <cmath>
#include <cassert>

#include "cities.hh"

Cities generate(string filename)
{
    cities_object = Cities();
    stream.open(filename);
    std::cin<<stream;
    assert(not cities_object.empty());
    return cities_object;
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