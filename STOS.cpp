
#include <iostream>
#include <string>
#define SUCCESS std::cout << ":)\n"
#define FAILURE std::cout << ":(\n"

int main() {

	int buf[10] = {0};
	int pos = 0;

	std::cout << "Use CTRL+C to exit." << std::endl;

	while(1) {

		char p;

		std::cin >> p;

		if( p == '+' ) {

			int v;

			std::cin >> v;
			if( pos < 10 ) {
				buf[pos ++] = v;
				SUCCESS;
			}else{
				FAILURE;
			}

		}

		if( p == '-' ) {

			if( pos > 0 ) {
				std::cout << buf[-- pos] << std::endl;
			}else{
				FAILURE;
			}

		}

	}



}
