#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node
{
	int number;
	struct node* next;
}NODE;

void add(int item, NODE** h, NODE** t) // �� �ڿ� �߰�
{
	NODE* newitem = (NODE*)malloc(sizeof(NODE));
	(*t)->next = newitem;
	newitem->number = item;
	newitem->next = (*h)->next;
	(*t) = newitem;
}
//�������� ���� �ٲٷ��� ���� ������
//����ü�� �� ��ü�� �ּҰ� ����Ű�� ��!
int main() {
	NODE* tail = (NODE*)malloc(sizeof(NODE));
	tail->number = 1;
	tail->next = tail;
	NODE* head = (NODE*)malloc(sizeof(NODE));
	head->next = tail;


	int n, k, count = 0;
	cin >> n >> k;

	for (int i = 1;i < n;i++)
	{
		add(i + 1, &head, &tail);
	}

	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp = head->next;
	int cnt = 1;
	int res = 0;
	cout << '<';

	while (temp->next != temp->next->next)
	{
		if (cnt == k - 1) {
			cout << temp->next->number << ", ";
			temp->next = temp->next->next;
			cnt = 1;
		}
		else {
			cnt++;
		}
		temp = temp->next;
	}
	cout << temp->next->number;
	cout << '>';


}