# HW9 Traveling Salesperson Problem

Nina Young and Aliya Ghassaei

## TSP Problem

The traveling salesperson problem asks, given a list of x, y coordinates, what the shortest possible route is
to visit each location and return to the original location. This problem is NP-hard.

## Code Design
The program in tsp.cc searches for the best solution to this problem among a set of randomized solutions.
where the code goes, where everything matters

### `Cities` class

The ```Cities``` class holds information about the particiular x, y coordinates that the salesperson must visit in the problem. The coordinates, of type ```coord_t``` (```std::pair<int, int```), are stored as a vector in the private member ```all_pairs```. The bitshift operators `<<` and `>>` are overloaded such that Cities objects can be read/fill or output Cities objects from/to a stream like so:
	
	std::cin >> cities;       // Reads coordinates from a file and puts them into all_pairs
	std::cout << cities;      // Outputs x "\t" y "\n" for each coord in all_pairs  

### `total_path_distance`

```total_path_distance``` returns a ```double``` representing the total distance traversed if the cities are visited in a particular order determined by the argument  ```ordering```: a ```const``` reference to a vector of unsigned integers representing indicies of ```all_pairs```. The function iterates over all pairs (better phrasing) of coords as determined by ```ordering``` and for each pair, calculates the distance between the starting and ending location with a helper function ```single_path_distance```. 

### `reorder`

Reorder creates a new `Cities` object whose `all_pairs` member is the same as that of the previous `Cities` object except in a new order as determined by `ordering`.

### `random_permutation`

`random_permutation` was defined outside of the class and generates a random permutation of numbers for 0 to `len`.

### Other functions

Other functions we implimented in the Cities class were:

````int size()```` Returns the length of ```all_pairs```

````void push_city(Cities::coord_t coord)```` Adds a new city x, y location to the end of the vector ```all_pairs```

```std::vector<coord_t> get_pairs()``` Returns the private member ```all_pairs```.

## Running the program

To run the program on 5 cities, write the following into the commandline:
	
	make

	./tsp five.tsv

To run the code on 50 cities, replace the second line with ```./tsp challenge.tsv```. 

After either version, ```tsp.cc``` will write the ordering of the cities with the shortest distance to ```shortest.tsv```

	cat shortest.tsv

	1       2       3       0       4       5

## Visualizations and Results

For 5 cities, the shortest path to take was 
	
	insert here whichever one you ploted here and final distance

! [](name-of-gif-file.gif)


For 50 cities, the shortest path to take was

	put here

! [](name-of-gif-file.gif)
