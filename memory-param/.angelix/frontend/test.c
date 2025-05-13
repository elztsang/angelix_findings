#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ANGELIX_OUTPUT
#define ANGELIX_OUTPUT(type, expr, id) expr
#endif

void init_array(int arr[], int size) {

	int i = 0;

	while (i < size) {
		arr[i] = i;
		i++;
	}
}

int main(int argc, char **argv) {
	int size, x, y;
	{ angelix_trace(21, 2, 21, 21); size = atoi(argv[1]); };
	{ angelix_trace(22, 2, 22, 18); x = atoi(argv[2]); };
	{ angelix_trace(23, 2, 23, 7); y = -1; };

	int arr[size];
	{ angelix_trace(26, 2, 26, 22); init_array(arr, size); };

	if(({ angelix_trace(28, 5, 28, 10); x >= 0; }))
		{ angelix_trace(29, 3, 29, 12); y = arr[x]; };

	printf("%d\n", ANGELIX_OUTPUT(int, y, "stdout"));
	return 0;
}

