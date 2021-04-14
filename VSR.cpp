
#include <iostream>
#define BEGIN void test(); int main() { size_t t; std::cin >> t; while ( t --> 0 ) test(); } void test()

BEGIN {

	int n;
	float v = 0;

	std::cin >> n;

	for( int i = 0; i < n; i++ ) {
		float vel;
		std::cin >> vel;
		v += 1.0f / vel;
	}

	std::cout << n / v << std::endl;

}
