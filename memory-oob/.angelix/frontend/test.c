#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ANGELIX_OUTPUT
#define ANGELIX_OUTPUT(type, expr, id) expr
#endif

int test1(int x){
	int global_arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	return global_arr[x];
}

int main(int argc, char **argv) {
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int x = atoi(argv[1]);
	int y = -1;
	if(x >= 0)
		{ angelix_trace(19, 3, 19, 12); y = arr[x]; };
	printf("%d\n", ANGELIX_OUTPUT(int, y, "stdout"));
	return 0;
}
