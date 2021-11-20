/*
 * Testing Cities class, starting with code from the assignment
 */
#include <iostream>
#include <fstream>
#include <cassert>

#include "cities.hh"

int main()
{
  // Create a Cities object
  Cities cities = Cities();

  // Read in coordinates from five.tsv and populate all_pairs
  std::ifstream cities_file;
  cities_file.open("five.tsv");
  cities_file >> cities;
  std::vector<Cities::coord_t> pairs = cities.get_pairs();

  // Verify that it was sucessfully created and that all_pairs is not empty
  std::cout << cities << std::endl;
  assert(not pairs.empty());
  
  // Test random_permutation
  random_permutation(5);
  random_permutation(5);
  random_permutation(5);
  random_permutation(10);
  random_permutation(10);

  // Test total_path_distance
  std::cout << cities.total_path_distance({ 0, 1, 2, 3, 4 }) << "\n"; // Should be 48.8699 (we get 56.4447)
  std::cout << cities.total_path_distance({ 3, 2, 4, 0, 1 }) << "\n"; // Should be 53.43 (we get 46.2199S)

}




