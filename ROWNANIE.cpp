
#include <iostream>

int main() {

	std::cout << "Use CTRL+C to exit." << std::endl;
	double a, b, c;

	while(1) {
		std::cin >> a >> b >> c;
		double d = (b * b) - (4 * a * c);

		if( d < 0 ) std::cout << 0 << std::endl;
		if( d == 0 ) std::cout << 1 << std::endl;
		if( d > 0 ) std::cout << 2 << std::endl;
	}

}
