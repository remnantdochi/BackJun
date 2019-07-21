

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int data;
	struct Node *next;
}NODE;

typedef struct Queue {
	NODE *front;//앞에서 꺼냄
	NODE *rear; //뒤에 넣음
	int count; //보관 개수
}QUEUE;

void push(QUEUE *queue, int x){
	NODE *newnode = (NODE *)malloc(sizeof(NODE));
	newnode->data = x;
	newnode->next = NULL;


	if (queue->count == 0) {
		queue->front = newnode;
	}
	else {
		queue->rear->next = newnode;
		
	}
	queue->rear = newnode;
	queue->count++;
};

int pop(QUEUE *queue) {
	int element = 0;

	if (queue->count == 0) {
		return -1;
	}
	else {
		NODE* nownode = queue->front;
		element = nownode->data;
		queue->front = nownode->next;
		queue->count--;
		free(nownode);

		return element;

	}
};

int size(QUEUE *queue) {
	return queue->count;
};

int empty(QUEUE *queue) {
	if (queue->count == 0) {
		return 1;
	}
	else {
		return 0;

	}
};

int front(QUEUE *queue) {
	if (queue->count == 0) {
		return -1;
	}
	else {
		return queue->front->data;

	}
};

int back(QUEUE *queue) {
	if (queue->count == 0) {
		return -1;
	}
	else {
		return queue->rear->data;

	}
};





int main() {
	int N;
	int X;
	char command[11];
	scanf("%d", &N);
	
	QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
	queue->front = NULL;
	queue->rear = NULL;
	queue->count = 0;


	for (int i = 0; i < N; i++)
	{
		scanf("%s", command);

		if (strcmp(command, "push")==0){
			scanf("%d", &X);
			push(queue, X);
		}
		else if (strcmp(command, "pop")==0) {
			printf("%d\n",pop(queue));
		}
		else if (strcmp(command, "size")==0) {
			printf("%d\n", size(queue));
		}
		else if (strcmp(command, "empty")==0) {
			printf("%d\n", empty(queue));
		}
		else if (strcmp(command, "front")==0) {
			printf("%d\n", front(queue));
		}
		else if (strcmp(command, "back")==0) {
			printf("%d\n", back(queue));
		}
		else {
		}

	}



	return 0;


}

