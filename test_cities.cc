/* Aliya Ghassaei and Nina Young
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
  cities_file.open("challenge.tsv");
  cities_file>>cities;
  std::vector<Cities::coord_t> pairs = cities.get_pairs();

  // Verify that it was sucessfully created and that all_pairs starts out empty
  std::cout<<cities<<std::endl;
  assert(not pairs.empty());
  
  // Test random_permutation
  random_permutation(5);
  random_permutation(5);
  random_permutation(5);
  random_permutation(10);
  random_permutation(10);

  /*
auto fin = std::ifstream("five.tsv");
Cities cities;
fin >> cities;
std::cout << cities.path_distance({ 0, 1, 2, 3, 4 }) << "\n"; // Should be 48.8699
std::cout << cities.path_distance({ 3, 2, 4, 0, 1 }) << "\n"; // Should be 53.43
*/
}




