#include "led.h"
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>

void* led_green_task(void* args) {

    pinMode(GREEN, OUTPUT);
    for (int i = 0; i < (int)args; ++i) {
        digitalWrite(GREEN, HIGH);
        sleep(2);
        digitalWrite(GREEN, LOW);
        sleep(2);
    }

    pthread_exit("\ngreen thread ends");
}
