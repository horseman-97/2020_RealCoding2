#include <stdio.h>

int main()
{       
    int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    //void *b; 
    long long *c; 
    //b = a;
    //c = b;
    c = a;
    printf("%d, %d\n", a, *a); 
    printf("%x, %lld\n", c, *c);
    printf("%x, %lld, %lld\n", c+1, *(c+1), *c+1);
}