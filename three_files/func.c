//func.c
#include "func.h"
#include <stdio.h>

int func_name_or_id()
{
    #ifdef PRINT_ID
	printf("ID : 201620921\n");
	return 0;
    #endif
	printf("Name : Nam Do Hyeon\n");
	return 1;
}
