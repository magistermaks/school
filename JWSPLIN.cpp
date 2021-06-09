#include <iostream>

int main() {

	int t;
	std::cin >> t;

	while( t --> 0 ) {

		int a11, a12, a21, a22, a31, a32;

		std::cin >> a11 >> a12 >> a21 >> a22 >> a31 >> a32;
		int det = a11 * a22 + a12 * a31 + a21 * a32 - (a22 * a31 + a11 * a32 + a12 * a21);
		std::cout << (det == 0 ? "TAK" : "NIE") << std::endl;

	}
}
