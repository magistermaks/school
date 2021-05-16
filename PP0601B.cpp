
// PP0601B.cpp

#include <iostream>

#define BEGIN void test(); int main() { size_t t; std::cin >> t; while ( t --> 0 ) test(); } void test()

BEGIN {

	int n, x, y;
	std::cin >> n >> x >> y;

	for( int i = 0; i < n; i ++ ) {

		if( i % x == 0 && i % y != 0 ) std::cout << i << ' ';

	}

	std::cout << std::endl;

}
