
#include <iostream>

#define Z ;
#define Y {
#define S }
#define J std::
#define A registry[read()]
#define B( ... ) print(A __VA_ARGS__ A)
#define C( ARG ) if( op == ARG )
#define D( ARG ) (#ARG[0])
#define E( ARG ) C(D(ARG)) B(ARG)Z
#define F( T ) Y begin: T op Z J cin >> op Z
#define P( N ) Y J cout << N << J endl Z
#define G C(D(z)) A=read()Z E(+)E(-)E(*)E(/)E(%)
#define H goto begin Z S
#define X ()
#define U( N, T ) T N
#define R return op Z S

U(registry, int)[10] = Y 0 S Z
U(print, void) (int op) P(op) S
U(read, int) X F(int) R
U(main, int) X F(char) G H
