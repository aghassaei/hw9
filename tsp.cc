/* Aliya Ghassaei and Nina Young
* Main program
*/
#include <iostream>
#include <fstream>
#include <cassert>


#include "cities.hh"

int main(int argc, char *argv[]){
  assert(argc == 2);
	std::ifstream cities_file;
	cities_file.open(argv[1]);
	if (!cities_file){
	    std::cerr << "No file was provided";
	}
	else{
		Cities cities_object = Cities();
		cities_file>>cities_object;
    int iterations = 1000000; // Total number of iterations
    
    // Compute the first distance for a random ordering and save result in shortest_distance
    auto best_ordering = random_permutation(cities_object.size());
    auto shortest_distance = cities_object.total_path_distance(best_ordering);
    iterations -= 1;

    // Continue iterating and compare current distance to shortest distance, updating shortest distance if necessary
    while (iterations) {

      // Create new ordering and calculate new distance
      auto ordering = random_permutation(cities_object.size());
      auto distance = cities_object.total_path_distance(ordering);

      // Compare new distance to current shortest distance
      if (distance < shortest_distance) {
        shortest_distance = distance;
        best_ordering = ordering;
        assert(shortest_distance != 0); // 
        std::cout << iterations << '\t' << shortest_distance << std::endl;
      }
      iterations -= 1;
    }
    // Save results to file "shortest.tsv"
    std::ofstream results_file;
    results_file.open("shortest.tsv");

    // need to fix this bc its not valid to push a vector into an ofstream this way
    results_file<<best_ordering;
	}
  
   return 0;
}
