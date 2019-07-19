#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node {
	int number;
	struct node* prev;
	struct node* next;
}NODE;
typedef struct que {
	struct node* front;
	struct node* rear;
	int quesize;
}QUE;
void push_front(int item, QUE* line) {
	NODE* nNode = (NODE*)malloc(sizeof(NODE));
	nNode->number = item;
	nNode->prev = NULL;
	nNode->next = line->front;
	if (line->front == NULL) { //젤 첨 추가할때
		line->rear = nNode;
	}
	else {
		line->front->prev = nNode;
	}
	line->front = nNode;
	line->quesize++;
}
void push_back(int item, QUE* line) {
	NODE* nNode = (NODE*)malloc(sizeof(NODE));
	nNode->number = item;
	nNode->prev = line->rear;
	nNode->next = NULL;
	if (line->front == NULL) { //젤 첨 추가할때
		line->front = nNode;
	}
	else {
		line->rear->next = nNode;
	}
	line->rear = nNode;
	line->quesize++;
}
int pop_front(QUE* line) {
	if (line->front == NULL) return -1;
	int value = line->front->number;
	NODE* dNode = line->front;
	line->front = line->front->next;
	free(dNode);
	if (line->front == NULL) line->rear = NULL; //1개만 남았을때
	else line->front->prev = NULL; // 이거 free하면서 할 필요 없는 거 아닌가???
	line->quesize--;
	return value;
}
int pop_back(QUE* line) {
	if (line->front == NULL) return -1;
	int value = line->rear->number;
	NODE* dNode = line->rear;
	line->rear = line->rear->prev;
	free(dNode);
	if (line->rear == NULL) line->front = NULL; //1개만 남았을때
	else line->rear->next = NULL;
	line->quesize--;
	return value;
}
int front(QUE* line) {
	if (line->front != NULL) return line->front->number;
	return -1;
}
int back(QUE* line) {
	if (line->front != NULL) return line->rear->number;
	return -1;
}
int size(QUE* line) {
	return line->quesize;
}
int empty(QUE* line) {
	if (line->quesize) return 0;
	return 1;
}

int main() {
	int N; //command 갯수
	cin >> N;
	QUE* problem = (QUE*)malloc(sizeof(QUE));
	problem->front = NULL;
	problem->rear = NULL;
	problem->quesize = 0;
	for (int i = 0; i < N; i++) {
		string command;
		int number;
		cin >> command;
		if (command == "push_back") {
			cin >> number;
			push_back(number, problem);
		}
		else if (command == "push_front") {
			cin >> number;
			push_front(number, problem);
		}
		else if (command == "pop_front") cout << pop_front(problem) << endl;
		else if (command == "pop_back") cout << pop_back(problem) << endl;
		else if (command == "front") cout << front(problem) << endl;
		else if (command == "back") cout << back(problem) << endl;
		else if (command == "size") cout << size(problem) << endl;
		else cout << empty(problem) << endl;

	}
	free(problem);
	return 0;
}
