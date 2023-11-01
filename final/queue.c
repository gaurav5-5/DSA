#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int orders[MAX];
int front = 0, rear = -1;

int add_order(unsigned int);
int deliver_order();
void display_orders();
void display_menu();

int
main()
{
	unsigned int choice = 0;
	unsigned int oid;
	int failed;

	display_menu();

	do
	{

		printf("\n>>> ");
		_flushall();
		scanf("%d", &choice);

		switch(choice)
		{
		case 0:
			printf("\n+------------+");
			printf("\n| Exiting... |");
			printf("\n+------------+\n");
			break;

		case 1:
			oid = (rand() % 1000 + 1) ;
			failed = add_order(oid);
			if(!failed)
			{
				printf("\n+--------+------+");
				printf("\n| PLACED | #%03d |", oid);
				printf("\n+--------+------+\n");
			}
			break;

		case 2:
			oid = deliver_order();
			if(oid >= 0)
			{
				printf("\n+-----------+------+");
				printf("\n| DELIVERED | #%03d |", oid);
				printf("\n+-----------+------+\n");
			}
			break;

		case 3:
			display_orders();
			break;

		case 4:
			display_menu();
			break;

		default:
			printf("\n+-------------------+");
			printf("\n| Invalid Choice!!! |");
			printf("\n+-------------------+\n");
			break;
		}

	}
	while(choice);

	return EXIT_SUCCESS;
}

int
add_order(unsigned int id)
{
	rear++;
	if(rear >= MAX && front)
		rear = 0;
	else if(rear >= MAX){
		printf("\n+---------------------------+");
		printf("\n| MAXIMUM CAPACITY REACHED! |");
		printf("\n+---------------------------+\n");
		return 1;
	}
	orders[rear] = id;
	return 0;
}

int
deliver_order()
{
	if(front >= MAX)
	{
		if(rear == MAX-1)
		{
			printf("\nNO MORE ORDERS!!\n");
			return -1;
		} else {
			front = 0;
		}
	}
	int ord = orders[front];
	orders[front] = 0;
	front++;

	return ord;
}

void
display_orders()
{
	printf("\n+--------+");
	printf("\n| ORDERS |");
	printf("\n+--------+");
	int frd = front;
	int ind = 1;

	if(frd == 0 && rear == -1)
		printf("  NO ORDERS TO PRINT...");
	else if(front > rear && rear == MAX-1)
		printf("  NO ORDERS TO PRINT...");
	else if(front > rear)
	{
		while(frd < MAX)
		{
			printf(" %d. ORDER [%03d] \n", ind++, orders[frd]);
			frd++;
		}
		frd = 0;
		while(frd <= rear)
		{
			printf("  %d. ORDER [%03d] \n",ind++, orders[frd]);
			frd++;
		}
	}
	else {
		while(frd < rear)
		{
			printf("  %d. ORDER [%03d] \n",ind++, orders[frd]);
			frd++;
		}
	}
}

void
display_menu()
{
	printf("\n+------------+");
	printf("\n| OPERATIONS |");
	printf("\n+------------+");
	printf("\n  [0] Exit");
	printf("\n  [1] Add Order");
	printf("\n  [2] Deliver Order");
	printf("\n  [3] Display Orders");
	printf("\n  [4] Print Menu\n");
}
