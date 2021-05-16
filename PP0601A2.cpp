// Certified MaMaWo Solution

#include <iostream>
#include <functional>
#include <vector>

void print( std::vector<int>& arr ) {
	for( int i : arr ) {
		std::cout << i << std::endl;
	}
}

int main() {

	int i = 42, c = 0;
	std::vector<int> array;

	while(c < 3) {
		int p = i;
		std::cin >> i;
		array.push_back(i);

		if( i == 42 && p != 42 ) c ++;
	}

	print(array);

}
