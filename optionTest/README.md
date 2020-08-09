## 2020806

# Compiler and Interpreter

Both Compiler and Interpreter translate source file to machine language.<br>
Therefore, their result format is both same as binary.

However, Compiler and Interpreter have difference as translating process.<br>

1. Compiler's translates at once, while interpreter translates row by row.
2. Compiler converts before program runs, whereas interpreter converts during program runs.
3. The most critical difference is that compiler generate intermediate code, on the other hand, interpreter does not gererate it.<br>
    The reason why interpreter does not generate intermediate is that .....
4. Compiler's execution time is shorter than interpreter.
5. Interpreter's translate time is shorter than compiler.

# GCC Compile commands

gcc has some compile options. Programmer can use this option for handling compile process.<br>
For example...

remind this picture while reading statement below.

# gcc compile option

1. `gcc -E` : Pre-processing.
    - It moves until preprocessing and does not compile and assemble.<br>
    - In other words, it generates only the preprocessor output.<br>
    This option produces the standard output.<br>
    ex) `gcc -E 00.option-o.c`
    
    ![image](/uploads/184118ec25ddad0e759c5c5a0ece5483/image.png)
    <br>
    ![image](/uploads/c959727113d0f8765df0edb7bafb2580/image.png)

    - You can make .i file by using `>`. `>` does standard out converting.<br>
    ex) gcc -E 00.option-o.c > 00.option-o.i
    - As the result, 00.option-o.i generated on the list.
    - And the result is same with the normal `-E` option.
    
    ![image](/uploads/7a9845b7e50381162ac5d733ad4ef76d/image.png)
  
    ![image](/uploads/1a25011ba83d459f98bcb70dfb85acb1/image.png)

2. `gcc -S`  : Compile
    - It moves until compile and does not assemble and link.<br>
    - In other words, It generates only the assembly code.<br>
    ex) `gcc -S 00.option-o.c`

    - It generates .s file on the directory.
    ![image](/uploads/168deb405c976a9065d2b348edaf28d3/image.png)
    ![image](/uploads/bb03a4eb14518d18e55501154d3ff5c7/image.png)

3. `gcc -c` : Assemble
    - It moves until assemble and does not link.<br>
    - Compile source file to object file without linking.<br>
    ex) `gcc -c 00.option-o.c`

    - It generates .o file on the directory.
    ![image](/uploads/633178b569bf45e15e97315893f1ca6a/image.png)
    
### Other useful gcc compile options
1. `gcc -o` : set output file and its name.
    - `gcc -o [output file] [.c file]`<br>
    - `gcc [.c file] -o [output file]`<br>
    ex) Both `gcc -o output 00.option-o.c` and `gcc 00.option-o.c -o output` make the same results.
    ![2020-08-09-031243_567x146_scrot](/uploads/1d4f6153387b0a6f02f586d208d4b9cf/2020-08-09-031243_567x146_scrot.png)
    ![2020-08-09-120528_558x149_scrot](/uploads/141f4ddb75d1249b00daac72da91404f/2020-08-09-120528_558x149_scrot.png)
2. `gcc -g` : debugging option
    - make debug information to be used by GDB.
    ![image](/uploads/150873e517a1377209c4c60b216d1e0e/image.png)
3. `gcc -D` : define a preprocessor macro
    - It can be used to define compile time macro.
    - On the `05.option-D.c` code, `NO macro` is not defined, so `lv2=NO` does not excuted. It generates an error.
    ```
    #include <stdio.h>
    //#define       NO      1000
    int main(void)
    {
        int lv1 = 1, lv2;
        lv2 = NO;
    #ifdef DEBUG
        printf("lv1:%d, lv2:%d\n", lv1, lv2);
    #endif
        printf("Main End.\n");
        return 0;
    }
    ```
    ![image](/uploads/6cd82c4f25aa97bc9ab4baab82358539/image.png)
    - If I use -D option on compile, I can define NO and I can get normal output.
    - For define NO marco, I used ``gcc -D NO 05.option-D.c`.<br>
    ![2020-08-09-123143_498x122_scrot](/uploads/f773f410e5a6fbf9c94e6d4d792cbd01/2020-08-09-123143_498x122_scrot.png)
4. `gcc -Wall` : set warning level 
    - There are several warning message options execept -Wall, such as -w and -Wextra.
    - `-Wall` option can be used print every warning message.<br>
    ![image](/uploads/acc967145e2c7ea25cbce92dfad29e15/image.png)
5. `link` : Can compile several files together. 
    - On the previous homework , we compile main.c and func.c together with `gcc main.c func.c` commnad.<br>
    - Then we used link option.<br>
    ![2020-08-09-124257_553x135_scrot](/uploads/0f32a522f6fc5c0691e7a4c5a434346b/2020-08-09-124257_553x135_scrot.png)
6. `gcc -O[level]` : set optimization level while compile. 
    - [level] could be set 0 to 3.
    - As this option compiler can optimize the code size and execution time. 
