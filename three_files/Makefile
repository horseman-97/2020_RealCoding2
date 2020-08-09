SRCS := main.c func.c
OBJS := $(SRCS:.c=.o)
CC := gcc
CFLAGS = -c -Wall -g
#CFLAGS = -c -Wall -O

main : $(OBJS)
	$(CC) -o $@ $^

#dummy target
clean : -rm $(OBJS)
	rm main

dep : 
	gccmakedep $(SRCS)
