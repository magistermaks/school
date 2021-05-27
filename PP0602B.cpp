
#include <iostream>
#define BEGIN void test(); int main() { size_t t; std::cin >> t; while ( t --> 0 ) test(); } void test()

BEGIN {

	int Y, X;
	std::cin >> Y >> X;

	int arr[X][Y]; // x, y

	// read the array form input
	for( int yi = 0; yi < Y; yi ++ ) {
		for( int xi = 0; xi < X; xi ++ ) {
			std::cin >> arr[xi][yi];
		}
	}

	const int x = X - 1, y = Y - 1, first = arr[0][0];

	//  1 <-- 4  //
	//  |    /\  //
	//  \/    |  //
	//  2 --> 3  //

	for( int i = 0; i < x; i ++ ) arr[i][0] = arr[i + 1][0]; // 4 --> 1
	for( int i = 0; i < y; i ++ ) arr[x][i] = arr[x][i + 1]; // 3 --> 4
	for( int i = x; i > 0; i -- ) arr[i][y] = arr[i - 1][y]; // 2 --> 3
	for( int i = y; i > 0; i -- ) arr[0][y] = arr[0][y - 1]; // 1 --> 2

	arr[0][1] = first;

	// draw the rotated array
	for( int yi = 0; yi < Y; yi ++ ) {
		for( int xi = 0; xi < X; xi ++ ) {
			std::cout << arr[xi][yi] << " ";
		}
		std::cout << std::endl;
	}

}
