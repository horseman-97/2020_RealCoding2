#include <stdio.h>
void set_elmt(int *a)
{
    a[0] = 3;
}

int main()
{
	const int a = 10;
	int *b = &a;
	printf("%d \n", a); 
	set_elmt(b); 
	printf("%d \n", a); 
	int * const c = b;
	*c = 100; 
	printf("%d \n", a); 
}
