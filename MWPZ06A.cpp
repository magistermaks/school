
#include <iostream>
#include <cmath>

int main() {

	int t, a, b, c;
	double result;

	std::cin >> t;

	while( t --> 0 ) {

		std::cin >> a >> b >> c;
		result = (a + b - c * b) * -12 / (c - 1.0);
		std::cout << std::floor(result + 0.5) << std::endl;

	}

	return 0;
}
