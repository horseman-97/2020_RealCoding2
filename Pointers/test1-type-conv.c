#include <stdio.h>

int main()
{       
    int a[10] = { 0, 0, 0, 1, 4, 5, 6, 7, 8, 9}; 
    //void *b; 
    long long *c; 
    //b = a;
    c = (long long *)a; 
    printf("%d, %d\n", a, *a); 
    printf("%x, %llx\n", c, *c); 
    printf("%x, %llx\n", c+1, *(c+1)); 
    float kk = 0.75f; 
    printf("%f : %d, %x\n", kk, *(int *)&kk );
}