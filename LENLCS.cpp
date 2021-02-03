
// LENLCS.cpp

#include <iostream>
#include <algorithm>
#define BEGIN void test(); int main() { size_t t; std::cin >> t; while ( t --> 0 ) test(); } void test()

int lcs( std::string X, std::string Y, int m, int n ) {
    if( m == 0 || n == 0 ) {
        return 0;
    } else if( X[m-1] == Y[n-1] ) {
        return 1 + lcs(X, Y, m-1, n-1);
    }

    return std::max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}

BEGIN {
	std::string a, b;
	std::cin >> a >> b;

	std::cout << lcs( a, b, a.size(), b.size() );
}
