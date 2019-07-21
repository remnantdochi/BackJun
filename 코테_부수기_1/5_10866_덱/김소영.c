#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int data;
	struct Node *prev;
	struct Node *next;
}NODE;

typedef struct Deque {
	NODE *head;
	NODE *tail;
	int count;
}DEQUE;

void push_front(DEQUE *deque, int x) {
	NODE *newnode = (NODE *)malloc(sizeof(NODE));
	newnode->data = x;
	newnode->prev = NULL;
	newnode->next = NULL;


	if (deque->count == 0) {
		deque->tail = newnode;
	}
	else {
		newnode->next = deque->head;
		deque->head->prev = newnode;

	}
	deque->head = newnode;
	deque->count++;
};

void push_back(DEQUE *deque, int x) {
	NODE *newnode = (NODE *)malloc(sizeof(NODE));
	newnode->data = x;
	newnode->prev = NULL;
	newnode->next = NULL;


	if (deque->count == 0) {
		deque->head = newnode;
	}
	else {
		newnode->prev = deque->tail;
		deque->tail->next = newnode;

	}
	deque->tail = newnode;
	deque->count++;
};

int pop_front(DEQUE *deque) {
	int element = 0;

	if (deque->count == 0) {
		return -1;
	}
	else {
		NODE* nownode = deque->head;
		element = nownode->data;
		deque->head = nownode->next;
		deque->count--;
		free(nownode);

		return element;

	}
};

int pop_back(DEQUE *deque) {
	int element = 0;

	if (deque->count == 0) {
		return -1;
	}
	else {
		NODE* nownode = deque->tail;
		element = nownode->data;
		deque->tail = nownode->prev;
		deque->count--;
		free(nownode);

		return element;

	}
};

int size(DEQUE *deque) {
	return deque->count;
};

int empty(DEQUE *deque) {
	if (deque->count == 0) {
		return 1;
	}
	else {
		return 0;

	}
};

int front(DEQUE *deque) {
	if (deque->count == 0) {
		return -1;
	}
	else {
		return deque->head->data;

	}
};

int back(DEQUE *deque) {
	if (deque->count == 0) {
		return -1;
	}
	else {
		return deque->tail->data;

	}
};
int main() {
	int N;
	int X;
	char command[11];
	scanf("%d", &N);

	DEQUE* deque = (DEQUE*)malloc(sizeof(DEQUE));
	deque->head = NULL;
	deque->tail = NULL;
	deque->count = 0;

	for (int i = 0; i < N; i++) {
		scanf("%s", command);

		if (strcmp(command, "push_front")==0) {
			scanf("%d", &X);
			push_front(deque, X);
		}
		else if (strcmp(command, "push_back") == 0) {
			scanf("%d", &X);
			push_back(deque, X);
		}
		else if (strcmp(command, "pop_front") == 0) {
			printf("%d\n", pop_front(deque));
		}
		else if (strcmp(command, "pop_back") == 0) {
			printf("%d\n", pop_back(deque));
		}
		else if (strcmp(command, "size") == 0) {
			printf("%d\n", size(deque));
		}
		else if (strcmp(command, "empty") == 0) {
			printf("%d\n", empty(deque));
		}
		else if (strcmp(command, "front") == 0) {
			printf("%d\n", front(deque));
		}
		else if (strcmp(command, "back") == 0) {
			printf("%d\n", back(deque));
		}
		else {

		}
	}

	return 0;
}
