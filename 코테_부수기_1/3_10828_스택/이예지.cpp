#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node {
	int number;
	struct node* prev;
	struct node* next;
}NODE;
typedef struct que {
	struct node* sp;
	int spsize;
}STACK;
void push(STACK* line, int item) {
	NODE* newnode = (NODE*)malloc(sizeof(NODE));
	newnode->prev = line->sp;
	newnode->next = NULL;
	newnode->number = item;
	if (line->sp == NULL) line->sp = newnode;
	else {
		line->sp->next = newnode;
		line->sp = newnode;
	}
	line->spsize++;
}
int pop(STACK* line) {
	if (line->sp == NULL) return -1;
	int value = line->sp->number;
	NODE* dnode = line->sp;
	line->sp = line->sp->prev;
	free(dnode);
	line->spsize--;
	return value;
}
int top(STACK* line) {
	if (line->sp == NULL) return -1;
	return line->sp->number;
}
int size(STACK* line) {
	return line->spsize;
}
int empty(STACK* line) {
	if (line->spsize) return 0;
	return 1;
}
int main() {
	int n; //command 갯수
	cin >> n;
	STACK* pro = (STACK*)malloc(sizeof(STACK));
	pro->spsize = 0;
	pro->sp = NULL;
	for (int i=0; i < n; i++) {
		string command;
		int number;
		cin >> command;
		if (command == "push") {
			cin >> number;
			push(pro, number);
		}
		else if (command == "pop") cout << pop(pro) << endl;
		else if (command == "top") cout << top(pro) << endl;
		else if (command == "size") cout << size(pro) << endl;
		else  cout << empty(pro) << endl;
	}
	free(pro);
	return 0;
}
