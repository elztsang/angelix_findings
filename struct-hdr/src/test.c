#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#ifndef ANGELIX_OUTPUT
#define ANGELIX_OUTPUT(type, expr, id) expr
#endif

char str_array[7][15] = {
        "okaydata",     //0 = good, 8
        "is999data",    //1 = good, 9
        "seven77",      //2 = bad, 7
        "gooddata",     //3 = good, 8
        "okay2access",  //4 = good, 11
        "12",           //5 = bad, 2
        "four",         //6 = bad, 4
};

struct eth {
    int num1;
    int num2;
};

void get_data(int which, int *data, int *data_end){
    *data = 0;
    *data_end = strlen(str_array[which]);
}

int main(int argc, char**argv) {
    int which, x, struct_size, data, data_end;
    which = atoi(argv[1]);
    struct_size = sizeof(struct eth*);
    x = -1; //default indicates bad data

    //initialize data, data_end so angelix can use them
    data = 0;
    data_end = 0;

    get_data(which, &data, &data_end);

    struct eth hdr;
    hdr.num1 = data;
    hdr.num2 = data_end;

    //fix: if (data + sizeof(struct eth*) < data_end);
    x = hdr.num2; //good data
    printf("%d\n", ANGELIX_OUTPUT(int, x, "stdout"));

    return 0;
}