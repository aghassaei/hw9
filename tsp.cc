/* Aliya Ghassaei and Nina Young
* Main program
*/
#include <iostream>
#include <fstream>


#include "cities.hh"

int main(int argc, char *argv[]){
	std::ifstream cities_file;
	cities_file.open(argv[1]);
	if (!cities_file){
	    std::cerr << "No file was provided";
	} 
	else{
		cities_object = Cities();
		std::cin<<cities_file;
		assert(not cities_object.all_pairs.empty()); // Make sure that << operator worked correctly
	}

	
   return 0;
}