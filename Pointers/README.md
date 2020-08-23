# Pointer

### 20200811

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
<br>
![image](/uploads/a4714c7a8b82ef08e556fef763fdd669/image.png)
<br>

If I define `int a = 100;`, it means we have `int` size(usually 4 bytes) room on the memory. 
And `&a` means an address of the space. If you want print this address, what should you do? <br>
Try `p = &a`. On this sentence, variable p has `int *` data type.<br>
`*p` means the value in the address value. In this case it will be 100.<br>

```
p = &i
i = 1;
printf("%d\n", i);
printf("%d\n", *p);
*p = 2;
printf("%d\n", i);
printf("%d\n", *p);
```
The output of this code is 1, 1, 2, 2.<br>

In conclusion, `*` operator can be used to access what's stored in the address space. If I done *p = i;, then *p is alias for i.<br>
This is very important concept. Not only does *p have the same value as i, but changing the value of *p also changes the value of i.<br>

Look at the increment parts. The data type of pointer can define the interval of data.<br>
For this, professor offered us an example code.<br>

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
    int *pa, *pb, pp;
	pa = &a; 
	pb = &b; 
	pp = (int) pa; 
	printf("%d %d\n", a, b);
    printf("%d %d\n", *pa, *pb);
	func(&b); 
	printf("%d %d\n", *pa, *pb);
	printf("%d %d %d\n", pa, pb, *(int *) pp);
	printf("%d %d\n", a, b);
	printf("%d, %d, %d, %d\n", a, &a, *(&a), *(int *)(long long)(&a) );
}
```
The result of this code is 
```
1 2
1 2
200 100
6422284 6422280 200
200 100
200, 6422284, 200, 200
```
`func` is the function which change pointer's value to 100, increase 1 pointer value , and change it also 200.
By using pointer, we can change value of `b` refer to its address value.<br>
We can make a question here. Why the value of `a` is also changed? There are no func(&a) on this code, but a values are change.<br>
This is memory hacking concept. On the stack memory, every memory is sequentially assigned. This can be check on fourth line output.<br>
The offset of `pa` and `pb` is 4, cause the int size is 4bytes on my computer OS. Therefore, `q++` of the `func` is the starting address of variable `a` and its value becomes 200.
<br>
Also, integer pointer can be integer, vice versa. 
`*(int *)pp` can return the value pp points.

## C memory models 

![image](/uploads/57bca0ab6eb72cda4b109e18cc5fe560/image.png)

In C language, variables can be defined by the scope and lifetime.<br>
 1. Automatic
    - It is local variable.
    - After the execution state leaves the function, automatic variable will lose its value.<br>
        This means that automatic variable can only keep its memory until the function execution time.
    - Stack has the automatic variable memory space.
    - The front keyword is `auto`, but usually we do not use it. `auto int i` and `int i` is same.
    
 2. Static
    - It is local variable.
    - Static variables can retain the value of the variable between different function calls.<br>
        In other words, static variable has its memory in the same place until program execution.
    - It does not disappear until the program ends. 
    - Main memory has the static variable memory space.
    
 3. Manual
    - Made by malloc = manual
    - This type can change size by memory copy and paste. 
    - The only way to change allocated memory.

<br>
![image](/uploads/8d00d5d787ef9940732e4347cb96b858/image.png)
<Br>
- startup : before main() called.
- Both `int a = 100;` and `static int a = 100;` are also available.
<br>
<br>
![image](/uploads/9077b765b40778270f17bafc8bd1846d/image.png)
<br>

If we define `int an_array[] = {0,1,2,3,4,5.....};` , Can you say the difference between `*(an_array+4)` and `*an_array+4`?
`*an_array` is 0, `*(an_array+4)` is 4. Why?<br> `int` type increases 4bytes when done `++` calculation.
`*(an_array+4)` means 16bytes increment, while `*an_array+4` means 4bytes increment.

<br>
![image](/uploads/f57505405db41ed3ec4ef945a18a1037/image.png)
<Br>
In this case, the term `adjective` means `const`. It means unchangable.<br>
- `int const A` : variable A is constant integer <br>
- `int const * A` :  Pointer variable which points constant integer.
    For example, If I declare `int const PI  = 3.14;`, I can define `int const *p = &PI;`.<br>
- `int * const A` : An integer pointer that does not change the address which pointer poining right now.
    On `int * const A = &p;`, &p cannot replaced by &q or other address.<br>
    However, the value in the address `&p` is changable.<br>




### test1.c

```
#include <stdio.h>

int main()
{       
    int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    void *b; 
    long long *c; 
    b = a;//Same as b = &a[0]; 
    c = b;
    printf("%d, %d\n", a, *a); 
    printf("%lld, %lld\n", c, *c);
    printf("%x, %lld\n", c, *c);
}
```
The result of this code is
```
6422256, 0
6422256, 1
```
`b` is void pointer type. And declare `b = a;`. 
Void pointer type can point to any address. And can avoid warning message from type casting problem.
Here is a very important point. On this code, the `b= a;` and ``b=&a[0]; are the same meaning.<br>
We can now access `a[0]` through p; for example, we can store the value 5 in `a[0]` by writing `*b = 5;`<Br>

```
#include <stdio.h>

int main()
{       
    int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    long long *c; 
    c = a;
    printf("%d, %d\n", a, *a); 
    printf("%x, %lld\n", c, *c);
    printf("%x, %lld, %lld\n", c+1, *(c+1), *c+1);
}
```
This code makes warning message becasue of `c=a;`, but anyway it can be execute. <br>
So we can change integer variable to long long type variable. However, this code building strategy is very bad.

```
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
    printf("%f : %d, %x \n", kk, *(int *)&kk, *(int *)&kk);
}
```
The result
```
6422260, 0
61fef4, 0
61fefc, 100000000
0.750000 : 1061158912, 3f400000 
```
`%x` is format specifier which generates hexadeciaml number. <br>
`kk` is float type. but the last line `*(int *)&kk` is different. It type-cast from floating pointer to integer pointer.
The value `0.750000` can be represented as hexadecimal and decimal forms. 
So the value `1061158912` and `3f400000` are the same. What we done right now is just print float type data, convert int * data type, and refer address space.
<br>

## test3.c
```
#include <stdio.h> 

int main()
{
	const int a = 99; 
	int const *b = &a; 

	*(int *)b = 200; 

 	printf("%d \n", a); 
}
```
The result is `200`.<br>
Although the `const` type qualifier exists, by type casting using pointer and reference, const variable can be changed.<br>
Why? `const` is adjective. It can add some attributes on the `noun`, but C language system cannot reject it.
This is why C language is difficult. Because it is basically operating language, it can control very deep side of structure.
<br>
```
#include <stdio.h>
void set_elmt(int *a)
{
    a[0] = 3;
}

int main()
{
	const int a = 10;
	int *b = &a;
	printf("%d \n", a); 
	set_elmt(b); 
	printf("%d \n", a); 
	int * const c = b;
	*c = 100; 
	printf("%d \n", a); 
}
```
Therefore, the result of this code is `10, 3, 100` Those are many possibilities that `const` qualified variables can be changed.<br>

## test4.c
```
#include <stdio.h>

int main()
{
	int a[10], b[30], c[40]; 
	int * t[3]; 
	t[0] = a; 
	t[1] = b; 
	t[2] = c; 
	t[1][0] = 200; 
	printf("%d\n", b[0]); 
}
```
The result : 200<br>
How about changing like this?

```
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
}
```
Array `b` has 30 spaces, so b's 35th space cannot be declared or used.
So it is out of bound and makes `Segmentation fault`, but sometimes it does not make error message.<br>
Because while making address space on memory, it usually makes spare address.

## Function Pointer
<br>
![image](/uploads/b9705de2aea787431808193d7203822e/image.png)
<br>

- `[return type][*function name][parameter types];`

```
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
```
This code was authorized by function pointer format, and result should be 11.<br>
If you put f[2](10.0), it automatically type cast and also print 11.<br>
Then why we should use function pointer? For this, we can handle many options without switch-case or if-else.<Br>


