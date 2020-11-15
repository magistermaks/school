
// PP0504D.cpp

#include <iostream>

#define DAY (60 * 60 * 24)

int main(){

	size_t n, m, t;
	std::cin >> t;

	while( t --> 0 ){

		std::cin >> n >> m;

		int time, units = 0, residue = 0;

		for( size_t i = 0; i < n; i ++ ) {

			std::cin >> time;

			residue += DAY / time;
			units += residue / m;
			residue %= m;

		}

		if( residue > 0 ) {

			units ++;

		}

		std::cout << units << std::endl;

	}

	return 0;
}
