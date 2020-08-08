# battle_c - 실전코딩2

### Dohyun Nam - Team 3

# Why we learn C again? 

1. C language is low level language.
It betweens Hardware and the System Software.

2. C language is essential in UNIX filesystem.

3. It means that you cannot make OS(based on UNIX) without C.

4. Although it is old language, still C is one of the most used languages on market.

# Simple C&UNIX history

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

# Which C?

1972 Original C
1978 K&R C
ANSI C
C99
C11
C18
IEEE POSIX-C, FIPS(for US federal Gov)

One of the most important characteristic in C99 is thread.

MinGW
Minimalist GNU for Windows. Provide essential functions of GNU compilers
It only has gcc compiler and debugger. Therefore, it cannot handle complex command.