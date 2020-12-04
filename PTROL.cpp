
// PTROL.cpp

#include <iostream>

#define BEGIN void test(); int main() { size_t t; std::cin >> t; while ( t --> 0 ) test(); } void test()

BEGIN {

	int a, b, c;
	std::cin >> a;

	for( int i = 0; i < a; i ++ ) {

		std::cin >> b;
		if( i ) std::cout << b << " "; else c = b;

	}

	std::cout << c << std::endl;

}
