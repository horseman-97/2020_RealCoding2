# Thread

### 20200812

## Pointer additional

```
#include <stdio.h>

int main(void)
{
    short n1=10, n2=20;
    int n3=0x10203040;
    short *p;
    p = &n1;
    printf("n1:%d, *p:%d\n", n1, *p);
    *p = 100;
    printf("n1:%d, *p:%d\n", n1, *p);
    (*p)++;
    printf("n1:%d, *p:%d\n", n1, *p);
    p = &n2;
    printf("n2:%d, *p:%d\n", n2, *p);
    p = &n3;
    printf("n3:%x, *p:%x\n", n3, *p);
    printf("n3:%x, *p:%x\n", n3, *(p+1));
    return 0;
}
```
On this code, `short n1 = 10` is as same as `short int n1 = 10;`. And 2 bytes space will be allocated to main memory.<br>
`short *p;` defined the pointer's type and its size. Size of data inside the address is 2bytes, and it will be increase 2bytes when `p++`.
<br>
The size of `int` in C language is not defined. You should use `sizeof()` for the exact measure of int size.
Because C language is based on hardware, usually int is 4 bytes, but it does not means 'always'.

```
#include <stdio.h>

int main(void) {
    int n1=10, n2=20, n3=30;
    int * p1=&n1;
    const int * p2=&n1;
    int * const p3=&n1;
    (*p1)++;
    (*p2)++;//error
    (*p3)++;

    p1 = &n2;
    p2 = &n2;
    p3 = &n2;//error
    
    return 0;
}
```

The value of the space which pointer `p2` pointing is int type, and we regard as constant.
Therefore, `int * p1 = &n1;` means const integer.<br>
We regard pointer `p3` as const. Therefore, the address value become const. 
So we cannot change the address which `n1` inside. 
<br>
Indeed, both `*(p2)++;` and `p3=&n2;` are error.
<Br>
`const` is recommended on authorization. Although it is not have forced unchangable method, it can be a strong recommendation that do not change the value which attached `const`.
As a powerful protection, we should use `const` if pointer or variable are static value.
<br>

## Concept of thread

For understanding thread, you should understand process concept first.<br>
Process means `a program in execution`. More detail, I can suggest you `an instance installed program executed and running` as a definition of process.<br>
By making process, operating system should get requrirement. This is called `system call`. After that, operating system converted from 
usermode to kernelmode. On the kernel mode, `system call handler` makes process. After that, controller passed to usermode again.<br>

Each process has their own `memory space` on the memory. It consists as 4 sections. These are `Code, Data, Heap, Stack`. I'll not explain about each sections role, but what you should remember
is that a new process needs a new memory space.<br>

So if you want to make a new process, it needs much cost. So some smart people find out the way making concurrency without makes a new process.<br>
By collecting only execution parts of a process, they solved it. We call this `thread`. Unlike process, threads from the same process are share address space.<br>
<br>
For using thread library, you should make a link by `-lpthread` command.<br>
Also, my `threadassignment.c` code is about multithreading. It uses threads because of concurrency. <br>
The biggest issue of this homework, and even multithreading is global variable. If I compile like this...
```
status = pthread_create(&tid, NULL, hello_thread, (void *) 15);
for(i=1; i<=5; i++) {
        printf("Main_Thread_%d!!\n", i);
        sleep(1);
}
```
There are critical problem exists. While main thread dead, child thread kill itself. Why?<br>
As I said before, global variable is shared by those 2 threads. but they do not share local variable.
If main thread dead, global variable memory becomes free by kernel, so child cannot use global variable.<br>
For prevent this issue, we should order to kernel do not free global variable.
```
pthread_exit(NULL);
```
This code keeps global variable on main thread and block memory break.<br>
This is the most important issue while you use global variable on multithreading environment.

### Simple discription of HW
<br>
Before we start, I want make some features clear. The term `parallelism` is different from `concurreny`. 
Concurrency means that suppose more than 1 task making process, we can say that those tasks are concurrent.
On the other hand, if you want to say parllelism, a system should be perform more than 1 task 'simultaneously'.<br>
<Br>
Our homework is parallel processing program. Also, it is task paralleism, but I will skip explaination about this.Program has 30 students score as a input, and should print out these scores.<br>
thread 1 prints average and sum of the scores, while thread 2 sorts the scores and print out.
