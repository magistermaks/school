
#include <iostream>
#define BEGIN void test(); int main() { size_t t; std::cin >> t; while ( t --> 0 ) test(); } void test()
std::string int2str(unsigned int value, unsigned int radix) {
    const char base36[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::string result;

    while (value > 0) {
        unsigned int remainder = value % radix;
        value /= radix;
        result.insert(result.begin(), base36[remainder]);
    }

    return result;
}

BEGIN {

	int value;
	std::cin >> value;
	std::cout << int2str(value, 16) << " " << int2str(value, 11) << std::endl;

}
