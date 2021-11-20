/*
 * API file for Travelling-Salesperson Cities class and utilities
 */

#pragma once

#include <vector>
#include <iostream>
#include <sstream>

// Representation of an ordering of cities
class Cities {
 public:
  // A pair of integral coordinates for each city
  using coord_t = std::pair<int, int>;

  // An ordering of cities. Each value represents a unique index
  // into the current city ordering in some container.
  using permutation_t = std::vector<unsigned int>;

  Cities() = default;

  friend std::ostream& operator<<(std::ostream& out_stream, const Cities& cities );

  friend std::istream& operator>>(std::istream& in_stream, Cities& cities );

  Cities reorder(const permutation_t& ordering) const;

  int size(); // returns how many cities are in the vector
  std::vector<coord_t> get_pairs(); // Returns all_pairs
  void push_city(Cities::coord_t coord); // adds a city to the end of the list
  double single_path_distance(const coord_t city1, const coord_t city2) const; //helper function, finds distance betw two cities

  double total_path_distance(const permutation_t& ordering) const; // Find the total distance of a given city traversal

private:
      std::vector<coord_t> all_pairs;
};

//random_permutation is outside the class
Cities::permutation_t random_permutation(unsigned len);
