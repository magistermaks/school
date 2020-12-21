
// SPEC01.cpp

#include <iostream>

int main() {

    int n;
    std::cin >> n;

    int a[n][n] = {0}, sum = 0;

    for( int y = 0, x = 0; y < n; x < n - 1 ? x ++ : y +++ (x = 0) ) {

    	std::cin >> a[x][y];

    	for( int y1 = y, x1 = x; y1 >= 0; x1 > 0 ? x1 -- : y1 --- (x1 = x) ) {
    		for( int y2 = y1, x2 = x1; y2 <= y; x2 < x ? x2 ++ : y2 +++ (x2 = x1) ) {
    			sum += a[x2][y2];
    		}
    	}

    }

    std::cout << sum;
}
