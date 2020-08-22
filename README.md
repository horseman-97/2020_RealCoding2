# battle_c - Realcoding2

### Dohyun Nam - Team 3

### 20200803

## Why we learn C again? 

1. C language is low level language.
It betweens Hardware and the System Software.

2. C language is essential in UNIX filesystem.

3. It means that you cannot make OS(based on UNIX) without C.

4. Although it is old language, still C is one of the most used languages on market.

## Simple C&UNIX history

![image](/uploads/f58fdeb78e5378b602be0bb0d8d51e77/image.png)

PDP 7 -> Ritchie made 'A' language cause assembly was so irritate -> He changed his language's name
with 'C' -> UNIX 

Berkeley made their UNIX-based OS. We call it BSD.
Meanwhile, AT&T makes UNIX(version 7) their trademark.
Some annoyed peple moved and made SunOS, Xentix, System V, etc.

Simply, MacOS based on BSD. 
There are many UNIX-liked System. Minix, Zenix, Linux...etc.

These all UNIX-based OS have something in common. Their kernel is based on C-language.
So If you want make OS, you need C compiler(CC)

## Which C?

1972 Original C<br>
1978 K&R C<br>
ANSI C<br>
C99<br>
C11<Br>
C18<br>
IEEE POSIX-C, FIPS(for US federal Gov)<br>

One of the most important characteristic in C99 is thread.<br>
Using thread, we can handle multithreading system.

## Platforms

MinGW<br>
Minimalist GNU for Windows. Provide essential functions of GNU compilers
It only has gcc compiler and debugger. Therefore, it cannot handle complex command.
<br>

cygwin<br>
Our main shell platform is not cygwin, but for `manpage`, cygwin should be installed on your computer.<br>
If you are curious some C functions, you have to visit its manpage and figure out its syntax, usage, and limitations.<br>

# Standard Input and Output

## Redirection
Before the C shell executes a command, it scans the command line for redirection characters. These special notations direct the shell to redirect input and output.<br>

- `< File` : Opens the specified File (which is first variable, command, and file name expanded) as the standard input.
- `> File` : Uses the specified File as standard output. If File does not exist, it is created. If File exists, it is truncated, and its previous contents are lost.

First, I can show you some examples. <br>

![image](/uploads/67672578ed398455925a93e599d60f9a/image.png)
1. make `input_data` file. You can use `touch` command.
2. If you watch `input_data` file with `cat` command, you can figure out there's nothing in the file. Why? cause you never make input on this file.
3. Let's make standard input. Type `$ cat > input_data` on shell and put `200` on this shell. 
4. Now with `cat input_data`, we can find `200` on this file.

Normally, we can type keyboard and make standard input, but with the redirection characters, standard input can be changed as file system.

<br>
![image](/uploads/7b8cf5d7ecfe210206e5b469b5fe9ac2/image.png)
![image](/uploads/6dc0fc4c8d2d8cbd4ec5eb41f255158e/image.png)
<br>

1. `$ ./a.exe < input_data` makes `input_data` file to standard input.
2. The standard output is `Hello World`.
3. Instead printing output to standard output(monitor), we can store it on the `output_data` file.
    Type `$ ./a.exe < input_data > output_data`. 
4. There are no standard output, but if you checkout output_data file with `cat output_data` command, 
    You can figure out standard output stored on output_data file with the redirection keyword `>`.

<br>
Now, imagine that I change input_data from 200 to -200.
After that, try again `$ ./a.exe < input_data > output_data`. command.

<br>
![image](/uploads/86992a3735229352fd02af5f2f84d836/image.png)
<br>

What can we know from this screenshot? The stderr message `Error. It is negative` does not stored on `output_data` file.
Printing this as output_data, what we should do is  `$ ./a.exe < input_data &> output_data`.<br>

- `>&FILE` : The form >& redirects both standard output and standard error to the specified File. 

<br>
![image](/uploads/5c741a87c197ce9ff730627deafc710e/image.png)
<br>
<br>

Let's modify some codes on hello.c and try this.
<br>
![image](/uploads/104ba5193fb619f30e3f4ec1cad3e589/image.png)
<br>
![image](/uploads/0a79192b65e9db345cf8086cc6daae02/image.png)
<br>

- Stderr : `Error. It is negative`
- Stdout : `HELLO WORLD`.


## 20200804

# How C program executed?

![image](/uploads/0082faefd87276c0fd22a125248fa556/image.png)
1. preprocessing. 
    - The C preprocessor modifies a source file before handing it over to the compiler.

2. compile source code. 
    - Compiler changes source code's address with assembly and makes link.

3. Done linking.
    - find the function or variables on library and link with the code I wrote.

4. Loader brings it to memory.
    - Decide the arguments locate position in the memory and allocate.


## References.
`https://www.ibm.com/support/knowledgecenter/ssw_aix_72/osmanagement/c_inout_redir.html`