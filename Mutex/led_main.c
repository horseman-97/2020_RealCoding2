#include "led.h"
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h> 
#include <pthread.h> 


void led_red_task(void){

    pinMode(RED, OUTPUT);
    for (int i = 0; i < 10; ++i) {
        digitalWrite(RED, HIGH);
        sleep(1);
        digitalWrite(RED, LOW);
        sleep(1);
    }

    pthread_exit("\nred thread ends");
}

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

