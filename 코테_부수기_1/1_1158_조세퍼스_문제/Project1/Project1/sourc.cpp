#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Node {
	int data = 0;
	Node* next, * prev;
	Node() {
		next = prev = NULL;
		data = 0;
	}
	Node(int i, Node* ptr)//ptr �ڿ� �߰�
	{
		data = i;
		prev = ptr;
		next = ptr->next;
		next->prev = prev->next = this;
	}
	void selvDelete() {
		prev->next = next;
		next->prev = prev;
		delete this;
	}
};

struct DLinkedList {
	Node* head;
	Node* tail;
	Node* iter;
	int count;
	DLinkedList() { //������
		count = 0;
		iter = new Node();
		head = new Node(); //���̸� �����ؼ� ������ �ְ��Ѵ�.
		tail = new Node(); //���̸� �����ؼ� ������ �ְ��Ѵ�.
		head->next = tail; //���ο����Ѵ�.
		tail->prev = head;
		iter = head;
	}
	void endInsert(int i) { //tail �տ� �߰��Ѵ�.
		new Node(i, tail->prev);
	}
	void moveRight() {
		if (iter->next == tail->prev) iter = head;
		else iter = iter->next;
	}

	void endDelete() {
		Node* temp = iter->next;
		cout << temp->data;
		moveRight();
		temp->selvDelete();
	}
};

int main() {
	int n, k, count = 0;
	cin >> n >> k;
	DLinkedList* list = new DLinkedList();

	for (int i = 1; i <= n; i++)list->endInsert(i);

	cout << "<";
	while (count < n) {
		if (count != 0)cout << ", ";
		for (int i = 0; i < k - 1; i++)list->moveRight();
		list->endDelete();
		count++;
	}
	cout << ">";
}