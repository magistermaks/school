
#include <iostream>
#include <vector>

#define BEGIN void test(); int main() { size_t t; std::cin >> t; while ( t --> 0 ) test(); } void test()

BEGIN {

	int t;
	std::cin >> t;

	std::vector<int> odd, even;

	for( int i = 1; i <= t; i ++ ) {

		int y;
		std::cin >> y;

		if( i % 2 ) {
			odd.push_back(y);
		}else{
			even.push_back(y);
		}

	}

	std::cout << std::endl;

	for( int i : even ) std::cout << i << " ";
	for( int i : odd ) std::cout << i << " ";

}
