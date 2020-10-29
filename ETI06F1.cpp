
// ETI06F1.cpp

#include <iomanip>
#include <iostream>
#include <cmath>

#define PI 3.141592654

int main() {

	double r, d;
	std::cin >> r;
	std::cin >> d;

	std::cout << std::fixed << std::setprecision(2) << ( std::pow(r, 2) - std::pow(d/2 , 2) ) * PI;

}
