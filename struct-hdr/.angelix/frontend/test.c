#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#ifndef ANGELIX_OUTPUT
#define ANGELIX_OUTPUT(type, expr, id) expr
#endif

char str_array[7][11] = {
        "okaydata",     //0 = good, 8
        "isbaddata",    //1 = good, 9
        "seven77",      //2 = bad, 7
        "gooddata",     //3 = good, 8
        "donotaccess",  //4 = good, 11
        "12",           //5 = bad, 2
        "four",         //6 = bad, 4
};


struct eth {
	int num1; //data, should be 0
	int num2; //data_end, should be < 8
};

void get_data(int which, int *data, int *data_end){

	*data = 0;
	*data_end = strlen(str_array[which]);
}

int main(int argc, char**argv) {
	int which, x, struct_size, data, data_end;
	{ angelix_trace(33, 2, 33, 22); which = atoi(argv[1]); };
	{ angelix_trace(34, 2, 34, 34); struct_size = sizeof(struct eth *); };
	{ angelix_trace(35, 2, 35, 7); x = -1; };

	//initialize so that angelix can use
	{ angelix_trace(38, 2, 38, 9); data = 0; };
	{ angelix_trace(39, 2, 39, 13); data_end = 0; };

//	data = (void *)(str_array[which]);
//	data_end = (void *)(str_array[which]) + (strlen(str_array[which])); //initializing them so that they can be used by angelix in repair
	{ angelix_trace(43, 2, 43, 34); get_data(which, &data, &data_end); };

	struct eth hdr;	//this is not memory allocated. not sure if i need to
	{ angelix_trace(46, 2, 46, 13); hdr.num1 = data; };
	{ angelix_trace(47, 2, 47, 13); hdr.num2 = data_end; };
	//fix: if(data + sizeof(struct eth*) < data_end);
//	if(data + sizeof(struct eth*) < data_end) printf("within bounds\n");
		{ angelix_trace(50, 3, 50, 11); x = hdr.num2; };	//good data
	printf("%d\n", ANGELIX_OUTPUT(int, x, "stdout"));

	return 0;
}
