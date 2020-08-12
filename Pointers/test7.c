#include <stdio.h>

float f_f() {return 100.0; }
int f_i() {return 100; }


int main()
{
	int (*f)(void); 
	float (*ff)(void); 
	f = f_i; 
	printf("%d\n", f()); 
	ff = f_f; 
	printf("%f\n", ff()); 
}
