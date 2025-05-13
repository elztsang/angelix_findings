#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ANGELIX_OUTPUT
#define ANGELIX_OUTPUT(type, expr, id) expr
#endif

void init_array(int arr[], int size){
    int i = 0;

    while (i < size) {      //using a for-loop gave me issues
        arr[i] = i;
        i++;
    }
}

int main(int argc, char**argv) {
    int size, x, y;
    size = atoi(argv[1]);   //size of VLA
    x = atoi(argv[2]);      //index to access
    y = -1;                 //default access is invalid

    int arr[size];          //throws an error on some machines, but this is valid and compiles.
    init_array(arr, size);

    if(x >= 0)
        y = arr[x];

    printf("%d\n", ANGELIX_OUTPUT(int, y, "stdout"));

    return 0;
}