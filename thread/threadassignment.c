#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

short int score[30] = {10, 68, 90, 66, 32 ,55, 27, 25, 33, 91 ,92, 72, 65, 40, 94, 45, 81, 1, 95, 23, 43, 26, 82, 7, 28, 47, 13, 48, 71, 38};


int static compare (const void* first, const void* second)
{
    if (*(short*)first > *(short*)second)
        return 1;
    else if (*(short*)first < *(short*)second)
        return -1;
    else
        return 0;
}

void * thread1(void * arg)
{
    short int sum = 0;//I set sum's data type short int
    float average = 0.0;//For point calculation

	for (int i=0; i<30;)
    {
        sum = sum +score[i++]; 
        sleep(1);
    }
    printf("Sum = %hd\n", sum);
	average = (float)sum/30.0;
    printf("Average = %f\n", average);
	pthread_exit(arg);
}

void * thread2(void * arg)
{
	qsort(score, 30, sizeof(short), compare);
    //Use qsort which offers to you on stdlib.h
    for(int i=0; i<30;)
        printf("%hd\n", score[i++]);

    
	pthread_exit(arg);
}

int main(void)
{
	pthread_t tid;
    pthread_t tid2;
	int status;
    //int status2;

	printf("Main_Thread Start\n");
	status = pthread_create(&tid, NULL, thread1, (void *) score);
    status = pthread_create(&tid2, NULL, thread2, (void *) score);
    //status2 = pthread_create(&tid2, NULL, thread2, (void *) score);

	if(status != 0) {
		perror("thread create");
		exit(1);
	}
    /*
    if(status2 != 0) {
		perror("thread create");
		exit(1);
	}
    */	
	
	printf("Main_Thread End\n");
	pthread_exit(NULL);
    return 0;
}