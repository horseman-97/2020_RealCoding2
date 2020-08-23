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
	int *pa, *pb, pp; 
	pa = &a; 
	pb = &b; 
	pp = (int) pa; 
	printf("a: %d, b: %d, pp: %d\n", a, b, pp);
	printf("*pa: %d, *pb: %d, pa: %d, pb: %d, *(*int *)pp: %d\n", *pa, *pb, pa, pb, *(int *)pp);
	func(&b); 
	printf("a: %d, b: %d, pp: %d\n", a, b, pp);
	printf("*pa: %d, *pb: %d, pa: %d, pb: %d, *(int *): %d\n", *pa, *pb, pa, pb, *(int *) pp);
	printf("(int *): %d, *(int *): %d\n", (int *)pp, *(int *)pp);
	printf("a: %d, &a: %d, *(&a): %d, *(int *)(long long): %d\n", a, &a, *(&a), *(int *)(long long)(&a) );
}
