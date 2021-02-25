
#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<std::vector<char>> map_type;

void draw( int s );
void triangle( map_type& map, int x1, int x2, int x3, int y1, int y2, int y3 );

int main() {

	int s;

	while(true) {
		std::cin >> s;
		if( s == 0 ) break;
		draw( s );
	}

}

void draw( int s ) {
	int a = abs(s);
	int b = a * 2;
	map_type map;

	for( int i = 0; i < b; i ++ ) {
		std::vector<char> line;
		for( int j = 0; j < b; j ++ ) {
			line.push_back('.');
		}
		map.push_back(line);
	}

	if( s > 0 ) {
		triangle( map, 0, a - 1, 0, 0, a - 1, a - 1 );
		triangle( map, a, a, b - 1, a, 0, 0 );
		triangle( map, 0, a - 1, a - 1, b - 1, a - 1, b - 1 );
		triangle( map, a - 1, b - 1, b - 1, a, a, b - 1 );
	}else{
		triangle( map, 0, a - 1, a - 1, 0, 0, a - 1 );
		triangle( map, a, b - 1, b - 1, a - 1, 0, a - 1 );
		triangle( map, 0, a - 1, 0, a, a, b - 1 );
		triangle( map, a, b - 1, a, a, b - 1, b - 1 );
	}

	for( int x = 0; x < b; x ++ ) {
		for( int y = 0; y < b; y ++ ) {
			std::cout << map[y][x];
		}

		std::cout << "\n";
	}
}

////////////////////////////////////////////////////
// The following code was taken from: TGL (ToyGL) //
// github.com/magistermaks/toygl                  //
////////////////////////////////////////////////////

inline int max_clamp( int value, int max ) {
	const int v = value < 0 ? 0 : value;
	return v > max ? max : v;
}

inline int max3( int a, int b, int c ) {
	return std::max( std::max( a, b ), c );
}

inline int min3( int a, int b, int c ) {
	return std::min( std::min( a, b ), c );
}

inline float cross( float x1, float y1, float x2, float y2, float x3, float y3 ) {
	return (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3);
}

void triangle( map_type& map, int x1, int x2, int x3, int y1, int y2, int y3 ) {

	const int siz = map.size() - 1;
	const int xmax = max_clamp( max3( x1, x2, x3 ), siz );
	const int xmin = max_clamp( min3( x1, x2, x3 ), siz );
	const int ymax = max_clamp( max3( y1, y2, y3 ), siz );
	const int ymin = max_clamp( min3( y1, y2, y3 ), siz );

	for( int x = xmax; x >= xmin; x -- ) {
		bool painted = false;

		for( int y = ymax; y >= ymin; y -- ) {

			// is point (x,y) inside given triangle?
			const bool b1 = cross( x, y, x1, y1, x2, y2 ) < 0;
			const bool b2 = cross( x, y, x2, y2, x3, y3 ) < 0;

			if( b1 == b2 ) {

				const bool b3 = cross( x, y, x3, y3, x1, y1 ) < 0;

				if( b2 == b3 ) {

					map[y][x] = '*';
					painted = true;

				}

			}else if( painted ) {
				break;
			}

		}
	}

}
