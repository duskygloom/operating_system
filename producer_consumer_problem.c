#include "item_buffer.c"

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t lock;

void menu()
{
	int option;
	double price;

	while (1) {
		printf("\nSTORE\n");
		printf("1. Produce.\n");
		printf("2. Consume.\n");
		printf("3. Show.\n");
		printf("   -------------\n");
		printf("0. Exit.\n");
		printf("Response: ");
		scanf("%d", &option);
		
		if (option == 0) break;

		else if (option == 1) {
			printf("Price: ");
			scanf("%lf", &price);
			producer(price);
		}

		else if (option == 2)
			consumer();

		else if (option == 3)
			print_buffer();

		else printf("Invalid option.\n");
	}
}

void *producer_runner(void *params)
{
	while (1) {
		pthread_mutex_lock(&lock);
		producer(20);
		pthread_mutex_unlock(&lock);
		sleep(1);
	}
	return NULL;
}

void *consumer_runner(void *params)
{
	while (1) {
		pthread_mutex_lock(&lock);
		consumer();
		pthread_mutex_unlock(&lock);
		sleep(2);
	}
	return NULL;
}

int main()
{
	pthread_t producer_thread, consumer_thread;
	pthread_create(&producer_thread, NULL, producer_runner, NULL);
	pthread_create(&consumer_thread, NULL, consumer_runner, NULL);
	while (1) {
		print_buffer();
		sleep(5);
	}
	pthread_join(producer_thread, NULL);
	pthread_join(consumer_thread, NULL);
	return 0;
}
