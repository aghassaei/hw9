/*
 * API file for Travelling-Salesperson Cities class and utilities
 */

#pragma once

#include <vector>
#include <iostream>

// Representation of an ordering of cities
class Cities {
 public:
  // A pair of integral coordinates for each city
  using coord_t = std::pair<int, int>;

  // An ordering of cities. Each value represents a unique index
  // into the current city ordering in some container.
  using permutation_t = std::vector<unsigned int>;

  // CONSTRUCTOR (added by us)
  // Takes a reference to an istream and ostream
  Cities(std::istream& is, std::ostream& os);

  //OVERLOADING OPERATORS >> and <<
  //from link on assignment
  //method or free?

  friend std::ostream& operator<<(std::ostream& out_stream, const Cities& City ) { 
         out_stream << City;
         return out_stream;            
      }

   friend std::istream& operator>>(std::istream& in_stream, Cities& city_object ) { 
         in_stream >> city_object;
         return in_stream;            
      }

  // Given a permutation, return a new Cities object where the order of the
  // cities reflects the original order of this class after reordering with
  // the given ordering. So for example, the ordering { 1, 0 } simply swaps
  // the first two elements (coordinates) in the new Cities object.
  Cities reorder(const permutation_t& ordering) const;

  // For a given permutation of the cities in this object,
  // compute how long (distance) it would take to traverse all the cities in the
  // order of the permutation, and then returning to the first city.
  // The distance between any two cities is computed as the Euclidean 
  // distance on a plane between their coordinates.
  double total_path_distance(const permutation_t& ordering) const;

//Added by us
private:
    std::istream& is_;
    std::ostream& os_;

};
