/* Aliya Ghassaei and Nina Young
* Main program
*/
#include <iostream>
#include <fstream>


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

    int iterations = 1000000;
    double shortest_distance = 10000000;
    while (iterations) {
      auto ordering = random_permutation(cities_object.size());
      auto distance = cities_object.total_path_distance(ordering);
      if (distance < shortest_distance) {
        shortest_distance = distance;
        assert(shortest_distance != 0);
        std::cout << iterations << '\t' << shortest_distance << std::endl;
      }
      iterations -= 1;

    }
	}

   return 0;
}
