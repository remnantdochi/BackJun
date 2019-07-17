//����https://zoomkoding.github.io/codingtest/2019/06/29/baekjoon-1158.html

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

struct node {
	int data = 0;
	node* next, * prev;
	node() {
		next = prev = NULL;
		data = 0;
	}
	node(int item, node* ptr) { //ptr �ڿ� �߰�
		data = item;
		prev = ptr;
		next = ptr->next;
		next->prev = prev->next = this;
	}
	void Dnode() {
		prev->next = next; //���⼭ prev�� next�� ���� ����?
		next->prev = prev;
		delete this;
	}
};

struct Dlinked {
	node* head;
	node* tail;

	Dlinked() {
		int count = 0;
		head = new node();
		tail = new node();
		head->next = tail;
		tail->prev = head;
	}
	void insert(int item) { //tail �� �߰�
		new node(item, tail);
	}
};

int main() {
	int n, k, count = 0;
	cin >> n >> k;
	Dlinked* people = new Dlinked();
	printf("test1");
	for (int i = 1; i <= n; i++)people->insert(i);
	printf("%d ", people->head);
}