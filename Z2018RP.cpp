
// Z2018RP.cpp

#include <iostream>
#include <algorithm>
#include <vector>

int max = 1;

int lis( int arr[], int n) {
	if( n == 1 ) return 1;
	int a, b = 1;

	for( int i = 1; i < n; i++ ) {
		a = lis(arr, i);
		if( arr[i - 1] < arr[n - 1] && a + 1 > b ) {
            b = a + 1;
		}
	}

	if( max < b ) max = b;
    return b;
}

int main() {
	std::vector<int> array;
	int count = 0;
	std::cin >> count;

	array.reserve(count);
	while( count --> 0 ) {
		int val;
		std::cin >> val;
		array.push_back(val);
	}

	lis( array.data(), array.size() );
	std::cout << max;
}
