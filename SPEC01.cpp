
#include <vector>
#include <iostream>

std::vector<std::vector<int>> map;

long area_sum( int x1, int y1, int x2, int y2 ) {
	long sum = 0;

	for( int x = x1; x < x2; x ++ ) for( int y = y1; y < y2; y ++ ) {
		sum += map[y][x];
	}

	return sum;
}

long recursive_sum( int x1, int y1, int x2, int y2 ) {

	if( y2 - y1 <= 1 || x2 - x1 <= 1 ) return map[y1][x1];

	int stripes = 0;

	for( int x = x1; x < x2; x ++ ) {
		stripes += area_sum( x, y1, x + 1, y2 );
	}

	for( int y = y1; y < y2; y ++ ) {
		stripes += area_sum( x1, y, x2, y + 1 );
	}

	return  + recursive_sum( x1, y1, x2 - 1, y2 - 1 )
			+ recursive_sum( x1 + 1, y1 + 1, x2, y2 )
			+ recursive_sum( x1 + 1, y1, x2, y2 - 1 )
			+ recursive_sum( x1, y1 + 1, x2 - 1, y2 )
			+ stripes + area_sum( x1, y1, x2, y2 );

}

int main () {

	int s;
	std::cin >> s;

	for( int a = 0; a < s; a ++ ) {
		std::vector<int> v2;

		for( int b = 0; b < s; b ++ ) {
			int v;
			std::cin >> v;
			v2.push_back( v );
		}

		map.push_back( v2 );
	}

	std::cout << recursive_sum( 0, 0, s, s ) << std::endl;

}
