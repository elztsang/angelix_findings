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
	size = atoi(argv[1]);
	x = atoi(argv[2]);
	y = -1;

	int arr[size];
	init_array(arr, size);

	if(x >= 0)
		y = arr[x];

	printf("%d\n", ANGELIX_OUTPUT(int, y, "stdout"));
	return 0;
}

