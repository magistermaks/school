
// PP0504D.cpp

#include <iostream>

typedef unsigned int uint;
typedef unsigned char byte;

void bytePrint( float f ) {

	byte* ptr = (byte*) &f;

	for( int i = sizeof(float) - 1; i >= 0; i -= sizeof(char) ) {
		std::cout << (uint) *(ptr + i) << " ";
	}

}

int main(){

	int t;
	float f;
	std::cin >> t;

	std::cout << std::hex << std::endl;

	while( t --> 0 ){

		std::cin >> f;
		bytePrint(f);
		std::cout << std::endl;

	}

	std::cout << std::dec;

	return 0;
}
