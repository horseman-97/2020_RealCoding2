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
    It moves until preprocessing and does not compile and assemble.<br>
    ex) `gcc -E 00.option-o.c`
    put picture on here.<br>

    You can make .i file by using `>`. `>` does standard out converting.<br>
    ex) gcc -E 00.option-o.c > 00.option-o.i

2. `gcc -S`  : Compile
    It moves until compile and does not assemble and link.<br>
    ex) `gcc -S 00.option-o.c`
    put picture on here.<br>

    It generates .s file on the directory.
    
3. `gcc -c` : Assemble
    It moves until assemble ans does not link.<br>
    ex) `gcc -c 00.option-o.c`
    put picture on here.<br>

    It generates .o file on the directory.
    
### Other useful gcc compile options

    `gcc -o` : 