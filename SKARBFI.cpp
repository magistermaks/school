
// SKARBFI.cpp

#include <iostream>

#define NORTH 0
#define SOUTH 1
#define WEST 2
#define EAST 3
#define SECRET_WORD "studnia"

#define STR_2( macro ) #macro
#define STR( macro ) STR_2( macro )

int main(){

	size_t t;
	std::cin >> t;

	while( t --> 0 ){

		size_t n;
		std::cin >> n;

		long x = 0, y = 0;

		while( n --> 0 ) {

			long a, b;
			std::cin >> a >> b;

			switch( a ) {

				case NORTH:
					y += b;
					break;

				case SOUTH:
					y -= b;
					break;

				case WEST:
					x -= b;
					break;

				case EAST:
					x += b;
					break;

			}

		}

		if( x == 0 && y == 0 ) {
			std::cout << SECRET_WORD << std::endl;
		}else{

			if( y != 0 ) {
				std::cout << (y > 0 ? STR(NORTH) : STR(SOUTH)) << " " << abs(y) << std::endl;
			}

			if( x != 0 ) {
				std::cout << (x > 0 ? STR(EAST) : STR(WEST)) << " " << abs(x) << std::endl;
			}

		}

	}

	return 0;
}
