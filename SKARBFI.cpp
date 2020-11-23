
// SKARBFI.cpp

#include <iostream>
#include <cmath>

#define NORTH 0
#define SOUTH 1
#define WEST 2
#define EAST 3
#define SECRET_WORD "studnia"

#define __STR( macro ) #macro
#define STR( macro ) __STR( macro )
#define BEGIN void test(); int main() { size_t t; std::cin >> t; while ( t --> 0 ) test(); } void test()

BEGIN {

	long n = 0, x = 0, y = 0;
	std::cin >> n;

	while( n --> 0 ) {

		long a, b;
		std::cin >> a >> b;

		switch( a ) {
			case NORTH: y += b; break;
			case SOUTH: y -= b; break;
			case WEST: x -= b; break;
			case EAST: x += b; break;
		}

	}

	if( x == 0 && y == 0 ) {
		std::cout << SECRET_WORD << std::endl;
	}

	if( y != 0 ) {
		std::cout << (y > 0 ? STR(NORTH) : STR(SOUTH)) << " " << std::abs(y) << std::endl;
	}

	if( x != 0 ) {
		std::cout << (x > 0 ? STR(EAST) : STR(WEST)) << " " << std::abs(x) << std::endl;
	}

}
