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
    This option produces the standard output
    ex) `gcc -E 00.option-o.c`
    
![image](/uploads/184118ec25ddad0e759c5c5a0ece5483/image.png)

the result should be like this.
![image](/uploads/c959727113d0f8765df0edb7bafb2580/image.png)

    You can make .i file by using `>`. `>` does standard out converting.<br>
    ex) gcc -E 00.option-o.c > 00.option-o.i
    
As the result, 00.option-o.i generated on the list.
![image](/uploads/7a9845b7e50381162ac5d733ad4ef76d/image.png)
    
And the result is same with the normal `-E` option
![image](/uploads/1a25011ba83d459f98bcb70dfb85acb1/image.png)

2. `gcc -S`  : Compile
    It moves until compile and does not assemble and link.<br>
    ex) `gcc -S 00.option-o.c`

    It generates .s file on the directory.
    
3. `gcc -c` : Assemble
    It moves until assemble ans does not link.<br>
    ex) `gcc -c 00.option-o.c`
    put picture on here.<br>

    It generates .o file on the directory.
    
### Other useful gcc compile options

    `gcc -o` : 