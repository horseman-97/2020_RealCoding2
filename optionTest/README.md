## 2020806

### Compiler and Interpreter

Both Compiler and Interpreter translate source file to machine language.<br>
Therefore, their result format is both same as binary.

However, Compiler and Interpreter have difference as translating process.<br>

1. Compiler's translates at once, while interpreter translates row by row.
2. Compiler converts before program runs, whereas interpreter converts during program runs.
3. The most critical difference is that compiler generate intermediate code, on the other hand, interpreter does not gererate it.<br>
    The reason why interpreter does not generate intermediate is that .....
4. Compiler's execution time is shorter than interpreter.
5. Interpreter's translate time is shorter than compiler.

### GCC Compile commands

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

1. `gcc -o <file>` : Make output on <file>
    - 