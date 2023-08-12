#include<stdio.h>
#define Q_size 5
int queue[Q_size];
int front = 0;
int rear = 0;
int flag = 1;

typedef enum{ok ,Q_full ,Q_empty}Q_status;
Q_status enqueue(int data);
Q_status dequeue(int *Q_ptr);

Q_status enqueue(int data)
{
	if(flag==1 || rear!=front)
	{
		queue[rear]=data;
		rear++;
		if(rear == Q_size){
			rear = 0;			
			flag = 0;
		}
		return ok;
	}
	return Q_full;
}

Q_status dequeue(int *DQ_ptr)
{
	if(!(flag == 1 && front == rear)){
		*DQ_ptr = queue[front];		
		front++;                             
		if(front == Q_size){
			front = 0;
			flag = 1;
		}
		return ok;
	}else return Q_empty;
}
int main()
{
	int n;
	printf("enter 0 for dequeue , any number to enqueue\n");
	while(1)
	{
		scanf("%d",&n);
		switch(n)
		{
			default:
				if(enqueue(n)==ok)
				{
					printf("%d is enqueued\n",n);
				}
				else
					printf("Q is full\n");
			break;
			case 0:
				
				if(dequeue(&n)==ok)
					printf("%d is dequeued\n",n);
					
				else
					printf("Queue is empty\n");
			break;
		}
	}
	return 0;

}