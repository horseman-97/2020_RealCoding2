#include <stdio.h>

void func(int *p)
{
	int *q = p; 
	*q = 100; 
	q++;
	*q = 200; 
}

int main()
{
	int a = 1;
	int b = 2; 
	int *pa, *pb; 
	long long pp; 
	pa = &a; 
	pb = &b; 
	pp = (long long) pa; 
	printf("%d %d\n", a, b);
	func(&b); 
	printf("%d %d\n", *pa, *pb);
	printf("%d %d %d\n", pa, pb, *(int *) pp);
	printf("%d %d\n", a, b);
	printf("%d, %d, %d, %d\n", a, &a, *(&a), *(int *)(long long)(&a) );
}
