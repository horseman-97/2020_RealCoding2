# Multithreading with Raspberrypi GPIO
### 20200814

## Basic concepts

- `Process` :  A program in execution. If an installed program is running, this instance can be called as process.<br>
    Each process has its own memory space, and does not share with the other processes.
    Address space includes code, data, stack and heap area.
    The 5 statuses of process are new ,ready, running, waiting, terminated.
    single process is only available in single processor. One process cannot mapping multiple processor.
- `Thread` : A collection of process execution parts 
    Create a new process means create a new address space. 
    


## Multithread and Mutex

What is multitasking? Multitasking system means that a system that can perform simultaneously.  We can say that this system has parallelism.
<br>
Multitasking even available single core by splitting CPU task time and making threads. 
### Makefile review

## Actual code - explanation its function

At first, I wrote main function like this.
```
int main(int argc, char *argv[]){
   pthread_t tid_green, tid_yellow;
   int mode = atoi(argv[1]);
   int count = atoi(argv[2]);
   wiringPiSetup();
   if (argc == 3) {
        if (mode == 1) {
			pthread_create(&tid_green, NULL, led_green_task, (void*)count);

        }
        if (mode == 2) {
			pthread_create(&tid_yellow, NULL, led_yellow_task, (void*)count);
        }
        if (mode == 3) {
            pthread_create(&tid_yellow, NULL, led_yellow_task, (void*)count);
            pthread_create(&tid_green, NULL, led_green_task, (void*)count);
        }
        
    	led_red_task();
        pthread_exit(NULL);
   }
   else
   {
       led_red_task();
   }
   
    
    

}
```
<br>
This function looks like reasonable, and I was close to the perfect. On this code, I can handle three cases, `$./led_main 1 5`,<br>
`$./led_main 2 7`, and `$./led_main 3 6`. However, it does not work on `$ ./led_main` command. Why?<br>
First, let me explain `(int argc, char *argv[])`. Those arguments are how command line arguments are passed to `main()` in C. `argc` will be the number of strings pointed by `argv`. 
The variables are named `argc (argument count)` and `argv (argument vector)` by convention.
Just remeber that argc is the number of arguments being passed into your program from the command line and argv is the array of arguments.
If argc == 1, we cannot control `$./led_main`. So we should add the branch for this.
<br>
Therefore, I suggest this main function for controling all issues.

```
int main(int argc, char *argv[]){
    pthread_t tid_green, tid_yellow;
    wiringPiSetup();
    if (argc == 1){
        led_red_task();
        pthread_exit(NULL);
    }
    if (argc == 3) {
        int mode = atoi(argv[1]);
        int count = atoi(argv[2]);    
        if (mode == 1) {
			pthread_create(&tid_green, NULL, led_green_task, (void*)count);

        }
        if (mode == 2) {
			pthread_create(&tid_yellow, NULL, led_yellow_task, (void*)count);
        }
        if (mode == 3) {
            pthread_create(&tid_yellow, NULL, led_yellow_task, (void*)count);
            pthread_create(&tid_green, NULL, led_green_task, (void*)count);
        }
        
    	led_red_task();
        pthread_exit(NULL);
   }
}
```

### Reference
https://stackoverflow.com/questions/3024197/what-does-int-argc-char-argv-mean
