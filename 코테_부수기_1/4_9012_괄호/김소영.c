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

void push(STACK *stack, char x) {
	NODE *newnode = (NODE *)malloc(sizeof(NODE));
	newnode->data = x;
	newnode->next = stack->top;
	stack->top = newnode;
	stack->count++;
};

void pop(STACK *stack) {

	NODE* nownode = stack->top;
	stack->top = nownode->next;
	stack->count--;
	free(nownode);

};


int main() {
	int N;
	int length;
	char list[51];
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		STACK* stack = (STACK*)malloc(sizeof(STACK));
		stack->top = NULL;
		stack->count = 0;

		scanf("%s", list);
		length = strlen(list);
		for (int i = 0; i < length; i++) {
			if (list[i] == '(') {
				push(stack, list[i]);
			}
			else if (list[i] == ')') {
				if (stack->count == 0) {
					stack->count = -1;
					break;
				}
				else {
					pop(stack);
				}
				
			}
			
		}
		if (stack->count == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

		free(stack);
	}



	return 0;


}
