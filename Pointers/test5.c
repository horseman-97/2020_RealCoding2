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
	int a = 200; 
	int (*f[4])(int) = {f10, f5, f1, f22}; 
	printf("%d\n", f[2](10)); 
	
}
