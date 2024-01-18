#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define BIG_NUMBER 1000000
int counter = 0;
pthread_mutex_t lock;

void *count_big(void *param)
{
	int n = *((int *)param);
	for (int i = 0; i < n; ++i) {
		pthread_mutex_lock(&lock);
		++counter;
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}

int main()
{
	pthread_t thread;

	int n = BIG_NUMBER/2;
	
	pthread_create(&thread, NULL, count_big, &n);
	count_big(&n);
	pthread_join(thread, NULL);

	printf("Counter: %d\n", counter);
	
	return 0;
}

