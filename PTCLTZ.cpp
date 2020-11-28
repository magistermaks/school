
// PTCLTZ.cpp

#include <iostream>
#include <cmath>

#define BEGIN void test(); int main() { size_t t; std::cin >> t; while ( t --> 0 ) test(); } void test()

BEGIN {

	int n, m;
	std::cin >> n;

	for( m = 0; n != 1; m ++ ) {

		n = ( n % 2 == 0 ) ? n / 2 : 3 * n + 1;

	}

	std::cout << m << std::endl;

}
