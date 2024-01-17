#include "item_buffer.c"

#include <stdio.h>

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

int main()
{
	menu();
	return 0;
}
