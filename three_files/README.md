# battle_c
## NamDohyeon - Team 3
Personal Project #2

# C compile and Execution
Preprocessing, Compile, Link (with library), Loader
# C preprocessor(CPP)

1. CPP can include files.
    
    - `#include` makes compiler add header file while compile.<br>
    - I can use `""` and `<>` for this. <br>
    - `<>` can be used for standard library header.<br>
    - `""` can be used for user-defined header.<br>
    
    ```
    #include <stdio.h>
    #include <math.h>
    #include "mydefined.h"
    ```

2. CPP can Define Macro

    - It can be used for defining a constant or parameterized macro.<br>
    
    ```
    //object
    //#define <identifier> <replacement token list>
    #define PI 3.14159

    //function-like macro
    //#define <identifier> <parameter list> <replacement token list>
    #define f(a) ((a) * (a))
    ```
    - Use `#define` for this. But this is very critical. So I need some practice for this.<br>
    
    ```
    //BAD example
    #define fa a*a
    b = f(20+13)
    //What you expected : (20+13)*(20+13)
    //What really happened : 20+13*20+13
    
    ```
    
    - NEVER use multiple name on Macro.<br>
    
    ````
    #define HE HI
    #define LLO _THERE
    #define HELLO "HI THERE"
    ...
    ```

3. CPP can do Conditional Compliation

    - I can compile section by section with `#ifdef` and `#endif`, etc.<br>
    - If directive starts with `#if`, it should be paired the one starts with `#end`<br>
    - In func.c you can check the usage of this.<br>
    
    ```
    //#if, #ifdef, #ifndef, #elif, #else, #endif
    #ifdef VERSION
    #if _VERSION >=3
        printf("Version is greater or equal than 3\n");
    #elif _ VERSION ==2
    #error VERSION 2 IS NOT SUPPORTED
    #endif
    #endif
    //#ifdef paired with the last #endif, #if paired with first #endif.
    //#elif also paired with #error.
    ```
# gcc Compile option(major 6)

![image](/uploads/0082faefd87276c0fd22a125248fa556/image.png)

1. -c : generate .o file.
    -This is for assemble.<br>
    If I has very long code but nothing change, I can use this option and compile more faster by  making this code .o file


2. -E : preprocessor.
    -If I include `math.h` in `file.c`, and make `gcc -E file.c` command, <br>
    `math.h` included and `math.h` preprocessing result will be out by stdout.


3. -g : debugging option


4. -O : Optimization. It should be used with optimize level.
    -It cannot be used with -g. If you done this, -O will be turn off.


5. -D : macro define


6. -o : Can send compile result to other file.


Other options, -std, -infile can be used.
Also, with -dM, `#define` can be defined with gcc compile.

Let's see one example. On this shot, printf is wrong on main.c. You can fix func(100) as fun1(100)

# In this file, how I can read func.c on main.c?

![image](/uploads/699f8d16b801fea24a9e467f35ba482b/image.png)



Answer: On C Compile process, there are link process, third chapter.
func1(100) needs link cause its extern int.
So the answer is, we can read this on link process.

If you want compile this, type `gcc main.c func.c` on prompt.

One of the bad habit of new beginner's is write down `#include<stdio.h>` everywhere.
In this code, only main.c needs <stdio.h> cause this code only have standard output.

# three files explanation

MY professor gave me a workout for practice this concept.

![image](/uploads/f4aa3590a685735fc8aeaaeb58aea462/image.png)

## func.h

in header file, I just declare function on here.<br>
Perfectly candid, I don't have to make func.h on here<br> 
if I put `extern int func_name_or_id()` on `func.c`.
But I made this for HW description

<pre>
<code>
//func.h
extern int func_name_or_id();
</code>
</pre>

## func.c

I defined function on here. <br>
And I will use `PRINT_ID` macro for conditional. For this, #ifdef and #endif will work by pair.<br>
If PRINT_ID already defined, print ID. If not, print name.<br>
If I print name, return 1. And for ID, I return 0.

<pre>
<code>
//func.c
#include "func.h"
#include <stdio.h>

int func_name_or_id()
{
    #ifdef PRINT_ID
	printf("ID : 201620921\n");
	return 0;
    #endif
	printf("Name : Nam Do Hyeon\n");
	return 1;
}
</code>
</pre>

## main.c

Nothing special on here. this is for compile. 

<pre>
</code>
//main.c
#include "func.h"
#include <stdio.h>

int main()
{
    func_name_or_id();
}
</code>
</pre>

## Compile 1
1. Type `gcc main.c func.c` on the git bash. 
2. Type `ls` 
    ![image](/uploads/e4e747409d8075480e46ef9298ae133f/image.png)
3. Type `./a.exe`

Result
    ![image](/uploads/6460bb521b618515b330d4b1350a18f7/image.png)

## Compile 2
All things are same, but try `gcc -DPRINT_ID main.c func.c` at first process.

Result
    ![image](/uploads/1a35eb3c417204d252453200648790bc/image.png)

## Why this happen?

What is `-D` option?<br> 
`gcc -DPRINT_ID` means define macro PRINT_ID. By define PRINT_ID macro, ID comes out instead of name.