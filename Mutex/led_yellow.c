#include "led.h"
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>

void* led_yellow_task(void* args) {

    pinMode(YELLOW, OUTPUT);
    for (int i = 0; i < (int)args; ++i) {
        digitalWrite(YELLOW, HIGH);
        sleep(3);
        digitalWrite(YELLOW, LOW);
        sleep(3);
    }

    pthread_exit("\nyellow thread ends");
}
