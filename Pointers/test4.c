#include <stdio.h>

int main()
{
	int a[10], b[30], c[40]; 
	int * t[3]; 
	t[0] = a; 
	t[1] = b; 
	t[2] = c; 
	t[1][35] = 200; 
	printf("%d\n", b[35]); 
	for (int i = 0 ; i < 40 ; i++)	
		printf("%d ", c[i]); 
}
