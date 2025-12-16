#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void insert(int q[],int *rear,int item)
{
	if (*rear == (MAX-1))
	{
		printf("\n queue full\n");
		return;
	}
	q[++(*rear)]=item;
	printf("\n the item inserted into queue is %d\n",item);
}
void delete(int q[],int *rear,int *front)
{
	int item;
	if (*front > *rear)
	{
		printf("\n Queue is Empty\n");
		*rear = -1;
		*front = 0;
		return;
	}
	item = q[(*front)++];
	printf("\n The item deleted from queue is %d\n",item);
}
void display(int q[],int *rear,int *front)
{
	int i;
	if (*front > *rear)
	{
		printf("\n Queue is Empty\n");
		return;
	}
	for(i=*front;i<=*rear;i++)
		printf("%d\t",q[i]);
	printf("\n");
}
int main()
{
	int q[MAX],rear=-1,front=0;
	int ch,item;
	while(1)
	{
		printf("$$$$$$$$$QUEUE$$$$$$$$$$$$\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("\n Enter your choice:: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\n Enter the item to queue:: ");
				scanf("%d",&item);
				insert(q,&rear,item);
				break;
			case 2: delete(q,&rear,&front);
				break;
			case 3: display(q,&rear,&front);
				break;
			case 4: exit(0);
			default: printf("\n Wrong Choice!!! \n");
		}
	}
	return 0;
}
