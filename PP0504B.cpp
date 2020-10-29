
// PP0504B.cpp

#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

char* string_merge( char* str_a, char* str_b ) {

	int len_a = strlen( str_a );
	int len_b = strlen( str_b );
	int len = MIN( len_a, len_b );
	char* str = (char*) malloc( len * 2 + 1 );

	for( int i = 0; i < len; i ++ ) {

		int j = i * 2;
		str[j + 0] = str_a[i];
		str[j + 1] = str_b[i];

	}

	str[len * 2] = 0;

	return str;
}

int main(){

	int n;
	char* buf = NULL;
	unsigned long s = 0;

	scanf("%d", &n);
	getline( &buf, &s, stdin);

	while(n --> 0){

		char* str_a = NULL;
		char* str_b = NULL;

		s = 0;
		int len_a = getdelim( &str_a, &s, ' ', stdin);

		s = 0;
		int len_b = getline( &str_b, &s, stdin);

		str_a[len_a - 1] = 0;
		str_b[len_b - 1] = 0;

		char* str = string_merge(str_a, str_b);
		printf("%s", str);
		printf("\n");

		free(str);
		free(str_a);
		free(str_b);

	}

	free(buf);

	return 0;
}
