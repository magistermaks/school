
// ETI07E7.cpp

#include <iostream>
#include <cmath>

// uncomment this line for funny output
// #define DEBUG

#ifdef DEBUG
#include <bitset>
#endif

typedef unsigned long long bitfield;

struct pair {
	int weight, value, offset;
};

// forward definitions
bool validate( bitfield selection, pair* input, int count, int max_a, int max_b, bitfield* key, pair** output );
void output( bitfield key, pair* array, int count );

int main() {

	int n, a, b;
	std::cin >> n >> a >> b;

	pair* array = new pair[n];

	for( int i = 0; i < n; i ++ ) {
		pair p;
		p.offset = i + 1;
		std::cin >> p.value >> p.weight;
		array[i] = p;
	}

	int maximum = a + b;
	bitfield iter = std::pow(2, n) - 1;
	int size = 0;

	// results
	int high = 0;
	bitfield key = 0;
	pair* result = nullptr;

#ifdef DEBUG
	std::cout <<"Search pool size: " << iter << std::endl;
#endif

	while( iter ) {

		int weight = 0;
		int value  = 0;
		int offset = 0;
		int count  = 0;

		for( bitfield mask = 1; mask > 0; mask *= 2 ) {
			if( mask & iter ) {
				pair* p = &array[offset];
				weight += p->weight;
				value  += p->value;

				count ++;
			}

			offset ++;
		}

		if( weight <= maximum && value > high ) {
#ifdef DEBUG
			std::cout << "Potential mask found! at: " << std::bitset<sizeof(bitfield) * 8>(iter) << ", value: " << value << std::endl;
#endif

			if( validate( iter, array, count, a, b, &key, &result ) ) {
				high = value;
				size = count;
			}

		}

		iter --;
	}

	if( high > 0 ) {
#ifdef DEBUG
		std::cout << "Solution found!" << std::endl;
#endif
		std::cout << high << std::endl;
		output( key, result, size );
	}else{
		std::cout << "No solution found!" << std::endl;
	}

	delete[] array;
	return 0;

}

bool validate( bitfield selection, pair* input, int count, int max_a, int max_b, bitfield* key, pair** output ) {

	pair* array = new pair[count];

	int outer_offset = 0;
	int inner_offset = 0;

#ifdef DEBUG
	std::cout <<" * Using pairs:";
	int debug_weight = 0;
#endif

	for( bitfield mask = 1; mask > 0 && inner_offset < count; mask *= 2 ) {
		if( mask & selection ) {
			array[inner_offset ++] = input[outer_offset];

#ifdef DEBUG
			std::cout << " " << input[outer_offset].value << ":" << input[outer_offset].weight;
			debug_weight += input[outer_offset].weight;
#endif
		}

		outer_offset ++;
	}

	bitfield iter = std::pow(2, count) - 1;
	bool flag = false;

#ifdef DEBUG
	std::cout << ", target: " << debug_weight << std::endl;
	std::cout << " * Using iter: " << std::bitset<sizeof(bitfield) * 8>(iter) << std::endl;
#endif

	while( iter ) {

		int weight_a = 0;
		int weight_b = 0;
		int offset = 0;

		for( bitfield mask = 1; mask > 0 && offset < count; mask *= 2 ) {
			if( mask & iter ) {
				weight_a += array[offset].weight;
			}else{
				weight_b += array[offset].weight;
			}

			offset ++;
		}

#ifdef DEBUG
		std::cout <<"    * Tested: " << weight_a << "/" << weight_b << std::endl;
#endif

		if( weight_a <= max_a && weight_b <= max_b ) {

			if( *output != nullptr ) {
				delete[] *output;
			}

			*output = array;
			*key = iter;

			flag = true;
			break;
		}

		iter --;
	}

#ifdef DEBUG
		std::cout << " * Mask " << (flag ? "verified" : "discarded") << "!" << std::endl << std::endl;
#endif

	if( !flag ) {
		delete[] array;
	}

	return flag;
}

void output( bitfield key, pair* array, int count ) {

	int offset = 0;

	for( bitfield mask = 1; mask > 0 && offset < count; mask *= 2 ) {
		if( (mask & key) != 0 ) {
			std::cout << /* array[offset].value << ":" << array[offset].weight << ":" << */ array[offset].offset << " ";
		}

		offset ++;
	}

	std::cout << std::endl;

	offset = 0;

	for( bitfield mask = 1; mask > 0 && offset < count; mask *= 2 ) {
		if( (mask & key) == 0 ) {
			std::cout << /* array[offset].value << ":" << array[offset].weight << ":" << */ array[offset].offset << " ";
		}

		offset ++;
	}

	std::cout << std::endl;

}

