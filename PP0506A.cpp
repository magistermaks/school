
// PP0506A.cpp

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

struct point {
	char name[11];
	int x;
	int y;
	float d;
};

float dist( int x, int y ) {
	return std::sqrt( std::pow(x, 2) + std::pow(y, 2) );
}

int main(){

	size_t c, t;
	std::cin >> t;

	while( t --> 0 ){

		std::cin >> c;

		std::vector<point> points;
		points.reserve(c);

		while( c --> 0 ) {

			point p;
			std::cin >> p.name;
			std::cin >> p.x;
			std::cin >> p.y;
			p.d = dist( p.x, p.y );
			points.push_back(p);

		}

		std::sort(points.begin(), points.end(), [](const point& a, const point& b) {
			return a.d < b.d;
		});

		for( point& p : points ) {
			std::cout << p.name << " " << p.x << " " << p.y << std::endl;
		}

	}

	return 0;
}
