#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <errno.h>

#include <unistd.h>
#include <sys/syscall.h> 

void * thread_function(void *);

int Counter=0;
#ifndef NOMUTEX
.... mutex_id;
#endif

int main(void)
{
	pthread_t tid1, tid2;
	void *thread_result;

#ifndef NOMUTEX
	if(________(&mutex_id, NULL) != 0){
		perror("pthread_mutex_init");
		exit(errno);
	}
#endif

	if(_______(&tid1, NULL, thread_function, "thread1")!=0) {
		perror("pthread_create");
		exit(1);
	}
	
	if(_______(&tid2, NULL, thread_function, "thread2")!=0) {
		perror("pthread_create");
		exit(1);
	}
	
	if(_______(tid1, &thread_result)!=0) {
		perror("pthread_join");
		exit(1);
	}
	if(_______(tid2, &thread_result)!=0) {
		perror("pthread_join");
		exit(1);
	}
	
#ifndef NOMUTEX
	___________(&mutex_id);
#endif

	printf(" thread result : %s\n", (char *) thread_result);
	return 0;
}

void * thread_function(void * arg)
{
	int temp;
	int i, j;
	char buffer[80];

	printf("thread_function called\n");	
	for(i=0; i<8; i++) {
#ifndef NOMUTEX
		_________(&mutex_id);
#endif
		sprintf(buffer, "%s: CountRelay: from %d to ", (char*)arg, Counter);
		write(1, buffer, strlen(buffer));

		temp=Counter;
		temp = temp+1;
// delay
		for(j=0; j<5000000; j++);

		Counter=temp;

		sprintf(buffer, "%d\n", Counter);
		write(1, buffer, strlen(buffer));
		
#ifndef NOMUTEX
		__________(&mutex_id);
#endif
	}
	// getchar();
	_______("thread end");
}
