# battle_c
## NamDohyeon - Team 3
Personal Project #2

# C compile and Execution
Preprocessing, Compile, Link (with library), Loader
# C preprocessor(CPP)

1. CPP can include files.

I can use "" and <> for this. <> can be used for standard library.

2. CPP can Define Macro

Use #define for this. But this is very critical. So I need some practice for this.
Order Expansion and stringification.
Special Macro. It can be used for searching bug and errorline.

3. CPP can do Conditional Compliation

I can compile section by section with #ifdef and #endif, etc.

4. Line Control

# gcc Compile option(major 6)


-c : generate .o file.
This is for fast compile.
If I has very long code but nothing change, I can use this option and compile more faster by  making this code .o file


-E : preprocessor
If I include math.h in file.c, and make gcc -E file.c command, math.h included and math.h preprocessing result will be out by stdout.


-g : debugging option


-O : Optimization. It should be used with optimize level.
It cannot be used with -g. If you done this, -O will be turn off.


-D : macro define


-o : Can send compile result to other file.


Other options, -std, -infile can be used.
Also, with -dM, #define can be defined with gcc compile.

# Put screenshot here later

On this shot, printf is wrong on main.c. You can fix func(100) as fun1(100)

In this file, how I can read func.c on main.c?

Answer: On C Compile process, there are link process, third chapter.
func1(100) needs link cause its extern int.
So the answer is, we can read this on link process.

If you want compile this, type gcc main.c func.c on prompt.

