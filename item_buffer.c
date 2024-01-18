#ifndef ITEM_BUFFER_C
#define ITEM_BUFFER_C

#include <stdio.h>

#define ITEM_BUFFER_SIZE 10

static inline int INDEX(int i)
{ return i % ITEM_BUFFER_SIZE; }

struct Item {
	int id;
	double price;
};

struct Item item_buffer[ITEM_BUFFER_SIZE];
int front = 0, rear = 0;

void set_item(struct Item *item, int id, double price)
{
	item->id = id;
	item->price = price;
}

void print_item(struct Item item)
{
	printf("Item (%d) - Rs %.2lf\n", item.id, item.price);
}

void print_item_short(struct Item item)
{
	printf("(%d, %.2lf)", item.id, item.price);
}

void print_buffer()
{
	printf("Item buffer: [");
	if (front == rear) {
		printf("]\n");
		return;
	}
	print_item_short(item_buffer[INDEX(front)]);
	for (int i = front+1; i < rear; ++i) {
		printf(", ");
		print_item_short(item_buffer[INDEX(i)]);
	}
	printf("]\n");
}

void producer(double price)
{
	static int id = 1;
	if (rear-front >= ITEM_BUFFER_SIZE) {
		printf("OVERFLOW\n");
		return;
	}
	set_item(&item_buffer[INDEX(rear)], id++, price);
	printf("Produced: ");
	print_item_short(item_buffer[INDEX(rear)]);
	putchar('\n');
	++rear;
}

void consumer()
{
	if (front == rear) {
		printf("UNDERFLOW\n");
		return;
	}
	printf("Consumed: ");
	print_item(item_buffer[INDEX(front)]);
	++front;
}

#endif // ITEM_BUFFER_C

