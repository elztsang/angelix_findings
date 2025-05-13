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

	if(ANGELIX_CHOOSE(bool, x >= 0, 28, 5, 28, 10, ((char*[]){"size", "x", "y"}), ((int[]){size, x, y}), 3))
		if (ANGELIX_CHOOSE(bool, 1, 29, 3, 29, 12, ((char*[]){"size", "x", "y"}), ((int[]){size, x, y}), 3)) y = arr[x];

	printf("%d\n", ANGELIX_OUTPUT(int, y, "stdout"));
	return 0;
}

