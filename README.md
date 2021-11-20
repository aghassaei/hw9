# HW9 Traveling Salesperson Problem

Nina Young and Aliya Ghassaei

## TSP Problem

The traveling salesperson problem asks, given a list of x, y coordinates, what the shortest possible route is
to visit each location and return to the original location. This problem is NP-hard.

## Code Design
The program in tsp.cc searches for the best solution to this problem among a set of randomized solutions.
where the code goes, where everything matters

#### Cities class

The ```Cities``` class holds information about the particiular x, y coordinates that the salesperson must visit in the problem. The coordinates, of type ```coord_t``` (```std::pair<int, int```), are stored as a vector in the private member ```all_pairs```. The bitshift operators `<<` and `>>` are overloaded such that Cities objects can be read/fill or output Cities objects from/to a stream like so:
	
	std::cin >>cities;
	std::cout << cities; 

#### Total path distance function

describe

helper function

#### reorder

sdaf

#### random permutation

outside of the class

#### randomized search

#### Other functions

Other functions we implimented in the Cities class were:

````int size()```` Returns the length of ```all_pairs```

````void push_city(Cities::coord_t coord)```` Adds a new city x, y location to the end of the vector ```all_pairs```

#### Running the program

To run the program on 5 cities, write the following into the commandline:
	
	make

	./tsp five.tsv

To run the code on 50 cities, replace the second line with ```./tsp challenge.tsv```. 

After either version, ```tsp.cc``` will write the ordering of the cities with the shortest distance to ```shortest.tsv```

	cat shortest.tsv
	
	1       2       3       0       4       5

## Visualizations and Results

djfhaksdha


