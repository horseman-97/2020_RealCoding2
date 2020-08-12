#include <stdio.h>

int f10(int a)
{	return a+10; }
int f5(int a)
{	return a+5; }
int f1(int a)
{	return a+1; }
int f22(int a)
{	return a+22; }



int main()
{
	double (*f[10])(int const *a, double (*g[10])(double h)); 
	int (*q)(int, int, double); 

	int a = 200; 
	int (*ff)(int); 
	ff = f10; 
	printf("%d\n", ff(a)); 
	
}
