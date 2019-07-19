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
void pushing(int item, QUE* line) {
	NODE* nNode = (NODE*)malloc(sizeof(NODE));
	nNode->number = item;
	nNode->prev = line->rear;
	nNode->next = NULL;
	if (line->front == NULL) { //�� ÷ �߰��Ҷ�
		line->front = nNode;
		line->rear = line->front;
	}
	else {
		line->rear->next = nNode;
		line->rear = nNode;
	}
	line->quesize++;
}
int poping(QUE* line) {
	if (line->front == NULL) return -1;
	int value = line->front->number;
	NODE* dNode = line->front;
	line->front = line->front->next;
	free(dNode);
	if (line->quesize == 1) line->rear = NULL; //1���� ��������
	line->quesize--;
	return value;
}
int front(QUE* line) {
	return line->front->number;
}
int back(QUE* line) {
	return line->rear->number;
}
int size(QUE* line) {
	return line->quesize;
}
int empty(QUE* line) {
	if (line->quesize) return 0;
	return 1;
}

int main() {
	int N; //command ����
	cin >> N;
	QUE* problem = (QUE*)malloc(sizeof(QUE));
	problem->front = NULL;
	problem->rear = NULL;
	problem->quesize = 0;
	for (int i = 0; i < N; i++) {
		string command;
		int number;
		cin >> command;
		if (command == "push") {
			cin >> number;
			pushing(number, problem);
		}
		else if (command == "pop") cout << poping(problem) << endl;
		else if (command == "front") cout << front(problem) << endl;
		else if (command == "back") cout << back(problem) << endl;
		else if (command == "size") cout << size(problem) << endl;
		else cout << empty(problem) << endl;

	}
	free(problem);
	return 0;
}