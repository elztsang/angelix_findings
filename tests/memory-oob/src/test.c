#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ANGELIX_OUTPUT
#define ANGELIX_OUTPUT(type, expr, id) expr
#endif

int main(int argc, char**argv) {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x = atoi(argv[1]);      //index to access
    int y = -1;                 //default access is invalid

    if(x >= 0)
        y = arr[x];

    printf("%d\n", ANGELIX_OUTPUT(int, y, "stdout"));
    return 0;
}