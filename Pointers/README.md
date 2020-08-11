# Pointer

## Pointer Basic

Pointers are one of C's most important-and most often misunderstood-features.<br>
The below contents refer to `K.N.King C programming-A Modern Approach, 2nd edition.`

### Pointer Variables
In most modern computers, main memory is divided into bytes. And each bytes capable of storing 8 bits of information.<br>
Each byte has a unique address to distinguish it from the other bytes in memory. If there are `n bytes` in memory, we can think of addresses<br>
as numvers that range from `0 to n-1`.
<br>

Each variable in the program occupies one or more bytes of memory; the address of the first byte is said to be the address of the variable.<br>
When we store the address of a variable `i` in the pointer variable `p`, we say that `p points to i`. <br>
In other words, a pointer is nothing more than an address, and a pointer varible is just a variable that can store an address.<br>

<br>
Check out this picture.![image](/uploads/7452bf64077a851759c86e99d9fb21d9/image.png)
<br>

### The Address and Indirection Operators
To find the address of a variable, we use the &(address) operator. If x is a variable, then &x is the address of x in memory.<br>
To gain access to the object that a pointer points to, we use the *(indirection) operator. If p is a pointer, then *p represents the variable to which p currently points.<br>
Pointer is nothing but a data type for storing the memory address with specified data type. For this functions, pointer needs a space and a data type.<br>

```
int i, *p;
int * p = &i;
```
In this code, integer pointer type variable `p` points the address of `i`. This means `p points to i`.<br>
Also this codes are available too.
```
int i;
int *p = &i;

// Combine the two declaration together.
 int i, *p = &i;
```
### Operation * features
![image](/uploads/a4714c7a8b82ef08e556fef763fdd669/image.png)
`*` operator can be used to access what's stored in the address space. If I done `*p = i;`, then `*p` is alias for `i`.<br>
This is very important concept. Not only does `*p` have the same value as `i`, but changing the value of `*p` also changes the value of `i`.

```
p = &i
i = 1;
printf("%d\n", i);
printf("%d\n", *p);
*p = 2;
printf("%d\n", i);
printf("%d\n", *p);
```
The output of this code is 1, 1, 2, 2.

## Pointer practice codes.

### test0.c

```
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
    printf("%d %d\n", *pa, *pb);
	func(&b); 
	printf("%d %d\n", *pa, *pb);
	printf("%d %d %d\n", pa, pb, *(int *) pp);
	printf("%d %d\n", a, b);
	printf("%d, %d, %d, %d\n", a, &a, *(&a), *(int *)(long long)(&a) );
}
```
