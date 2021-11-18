#Aliya Ghassaei and Nina Young
#Modified from HW8 Makefile

# Getting a linker error?
CXX=clang++
CXXFLAGS=-Wall -Wextra -Werror -pedantic -std=c++17 -O0 -g
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)

all: test_cities tsp

test_cities: cities.o test_cities.o 
	$(CXX) $(LDFLAGS) -o $@ $^

tsp: tsp.o cities.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cc %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

clean:
	rm -rf *.o test_cities tsp

test: test_cities
	./test_cities
