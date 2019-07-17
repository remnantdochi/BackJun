           // 2019-02-02 JANGWON KIM
// MY_QUEUE
#define _CRT_SECURE_NO_WARNINGS
#define QUEUE_SIZE 10001
#include <stdio.h>
#include <stdlib.h>

int queue[QUEUE_SIZE];
int front = 0;
int rear = 0;
int queue_size = 0;

void push(int element)
{
	if (queue_size <QUEUE_SIZE)
	{
		rear = (rear + 1) % QUEUE_SIZE;
		queue_size = queue_size + 1;
		queue[rear] = element;
	}
	else
	{
		//printf("Error: Stack overflow occurs!\n");
	}
}
int pop()
{
	if (queue_size > 0)
	{
		front = (front + 1) % QUEUE_SIZE;
		queue_size = queue_size - 1;
		return queue[front];
	}
	else
	{
		//printf("Error: The queue is already empty!\n");
		return -1;
	}
}
int size()
{
	if (queue_size > 0&&queue_size<=QUEUE_SIZE)
	{
		return queue_size;
	}
	else if(queue_size>QUEUE_SIZE)
	{
		printf("Error: Stack overflow occurs!\n");
	}
	else
	{
		//printf("Error: The queue is already empty!\n");
		return 0;
	}
}
int IsEmpty()
{
	if (queue_size == 0)
		return 1;
	else
		return 0;
}
int top() //큐의 가장 앞에 있는 정수를 출력한다.
{
	if (queue_size > 0)
	{
		return queue[front + 1 % QUEUE_SIZE];
	}
	else
	{
		//printf("Error: The queue is already empty!\n");
		return -1;
	}
}
int back()
{
	if (queue_size > 0)
	{
		return queue[rear];
	}
	else
	{
		//printf("Error: The queue is already empty!\n");
		return -1;
	}
}
int main()
{
	char buffer[15];

	int N;
	int X;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", buffer);
		if (buffer[0] == 'p' && buffer[1] == 'u')
		{
			scanf("%d", &X);
			push(X);
		}
		else if (buffer[0] == 'p' && buffer[1] == 'o')
		{
			printf("%d\n", pop());
		}
		else if (buffer[0] == 's')
		{
			printf("%d\n", size());
		}
		else if (buffer[0] == 'f')
		{
			printf("%d\n", top());
		}
		else if (buffer[0] == 'b')
		{
			printf("%d\n", back());
		}
		else
			printf("%d\n", IsEmpty());
	}


	return 0;
}                                                     
