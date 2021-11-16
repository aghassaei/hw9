#Aliya Ghassaei and Nina Young
#Modified from HW8 Makefile
CXX=clang++
CXXFLAGS=-Wall -Wextra -pedantic -std=c++17 -O0 -g
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)

all: test_bitio encoder decoder

test_cities: cities.o test_cities.o
	$(CXX) $(LDFLAGS) -o $@ $^

tsp: tsp.o cities.o 
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cc %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

clean:
	rm -rf *.o test_bitio encoder decoder

test: test_cities
	./test_cities
