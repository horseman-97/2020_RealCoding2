#include <stdio.h> 

int main()
{
	const int a = 99; 
	int const *b = &a; 

	*(int *)b = 200; 

 	printf("%d \n", a); 
}
