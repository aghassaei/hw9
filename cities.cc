/*
 * Implimentation for Cities class
 */

#include <cmath>
#include <cassert>
#include <iostream>
#include <numeric>
#include <random>
#include <chrono>
#include <algorithm>

#include "cities.hh"

std::ostream& operator<<(std::ostream& out_stream, const Cities& cities ) {
			for (auto city : cities.all_pairs){
					out_stream<<city.first<<'\t'<<city.second<<std::endl;
			}

			 return out_stream;
		}

std::istream& operator>>(std::istream& in_stream, Cities& cities ) {
			 while (!in_stream.eof()){
				 Cities::coord_t city;
					in_stream>>city.first>>city.second;
					cities.push_city(city);
			 }
			 return in_stream;
		}


Cities::permutation_t random_permutation(unsigned len) {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	static std::default_random_engine generator {seed};
	Cities::permutation_t permutation (len);
	std::iota(permutation.begin(), permutation.end(), 0);
	std::shuffle(permutation.begin(), permutation.end(), generator);

	// below is for testing that the permutation permutes randomly each time
	// for(int i=0; i < permutation.size(); i++){
	// std::cout << permutation[i] << ' ';
	// }

	return permutation;
}

int Cities::size() {
	return all_pairs.size();
}

std::vector<Cities::coord_t> Cities::get_pairs() {
	return all_pairs;
}

void Cities::push_city(Cities::coord_t coord) {
	all_pairs.push_back(coord);
}

//helper function for total_path_distance that finds the distance between two cities
double Cities::single_path_distance(const coord_t city1, const coord_t city2) const {
	double delta_x = double(city1.first) - double(city2.first);
	double delta_y = double(city1.second) - double(city2.second);
	double distance = std::hypot(delta_x, delta_y);
	assert(distance != 0);
	return distance;
}

//TOTAL PATH DISTANCE
//compute the total distance of traversing all the cities in the order defined by the permutation.
double Cities::total_path_distance(const permutation_t& ordering) const{
	assert(not ordering.empty()); // Make sure that ordering isn't an empty vector
	double total_distance = 0;

	for (unsigned i=0; i < ordering.size()-1; i++){
		assert(ordering[i] != ordering[i+1]);
		int index = ordering[i];
		int next_index = ordering[i+1];
		auto distance = single_path_distance(all_pairs[index], all_pairs[next_index]);
		total_distance += distance;
	}
//Don't forget to add the distance going back from the last city in the permutation to the first one.
	auto last_city_distance = single_path_distance(all_pairs[ordering[0]], all_pairs[ordering[ordering.size()-1]]);
	total_distance += last_city_distance;
	return total_distance;
}

//REORDER
//It should return a new Cities object where the internal representation
//of the cities reflects the order as indexed by the permutation. So, for
//example, if the first element of the permutation is '3', then the first coordinate
//pair of the new cities object is the fourth pair in the original object (indices start at 0).
Cities Cities::reorder(const permutation_t& ordering) const{
	Cities new_cities = Cities();
	const std::vector<coord_t>& prev_all_pairs = all_pairs;
	for (auto i: ordering){
		new_cities.push_city(prev_all_pairs[i]);
	}
	return new_cities;
}
