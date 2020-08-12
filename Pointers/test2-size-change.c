#include <stdio.h>

int func(int a)
{
	int b[a]; 
	b[0] = 200; 
	printf("%d\n", b[0]); 
}

int main()
{
	int a = 1;
	int b = 2; 
	void *v = &a; 
	printf("v add %d \n", v);
	v++; 
	printf("v add %d \n", v);
	printf("%d %d\n", a, b);
	func(10); 
	printf("%d %d\n", a, b);
}
