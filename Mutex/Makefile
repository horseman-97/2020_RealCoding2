SRCS := led_main.c led_green.c led_yellow.c
OBJS := $(SRCS:.c=.o)
CFLAGS := -c -Wall

led_main : $(OBJS)
	gcc -o $@ $^ -lwiringPi -lpthread

.c.o :
	gcc  $(CFLAGS) $<

clean :
	-rm $(OBJS)
	rm led_main

dep :
	gccmakedep $(SRCS)
