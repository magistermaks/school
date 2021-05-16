
#include <iostream>
#include <vector>

int main() {

	int h, w, i;
	std::cin >> h >> w;

	std::vector<int> nums;

	i = w * h;
	while( i --> 0 ) {

		int j;
		std::cin >> j;
		nums.push_back(j);

	}

	for( int x = 0; x < w; x ++ ) {
		for( int y = 0; y < h; y ++ ) {
			std::cout << nums[y * w + x] << " ";
		}
		std::cout << std::endl;
	}

}
