
// EUCGAME.cpp

#include <iostream>

#define BEGIN void test(); int main() { size_t t; std::cin >> t; while ( t --> 0 ) test(); } void test()

BEGIN {

	unsigned long a, b;
	std::cin >> a >> b;

	while( a != b ) {

		if( a < b ) b -= a;
		if( a > b ) a -= b;

	}

	std::cout << a + b << std::endl;

}
