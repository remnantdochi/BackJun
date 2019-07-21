#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int data;
	struct Node *next;
}NODE;

typedef struct Stack {
	NODE *top;
	int count; //보관 개수
}STACK;

void push(STACK *stack, int x) {
	NODE *newnode = (NODE *)malloc(sizeof(NODE));
	newnode->data = x;
	newnode->next = stack->top;
	stack->top = newnode;
	
	
	stack->count++;
};

int pop(STACK *stack) {
	int element = 0;

	if (stack->count == 0) {
		return -1;
	}
	else {
		NODE* nownode = stack->top;
		element = nownode->data;
		stack->top = nownode->next;
		stack->count--;
		free(nownode);

		return element;

	}
};

int size(STACK *stack) {
	return stack->count;
};

int empty(STACK *stack) {
	if (stack->count == 0) {
		return 1;
	}
	else {
		return 0;

	}
};

int top(STACK *stack) {
	if (stack->count == 0) {
		return -1;
	}
	else {
		return stack->top->data;

	}
};






int main() {
	int N;
	int X;
	char command[11];
	scanf("%d", &N);

	STACK* stack = (STACK*)malloc(sizeof(STACK));
	stack->top = NULL;
	stack->count = 0;


	for (int i = 0; i < N; i++)
	{
		scanf("%s", command);

		if (strcmp(command, "push") == 0) {
			scanf("%d", &X);
			push(stack, X);
		}
		else if (strcmp(command, "pop") == 0) {
			printf("%d\n", pop(stack));
		}
		else if (strcmp(command, "size") == 0) {
			printf("%d\n", size(stack));
		}
		else if (strcmp(command, "empty") == 0) {
			printf("%d\n", empty(stack));
		}
		else if (strcmp(command, "top") == 0) {
			printf("%d\n", top(stack));
		}
		else {
		}

	}



	return 0;


}
