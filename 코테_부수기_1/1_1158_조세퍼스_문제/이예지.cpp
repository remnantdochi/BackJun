#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node
{
	int number;
	struct node* next;
}NODE;

void add(int item, NODE** h, NODE** t) // 맨 뒤에 추가
{
	NODE* newitem = (NODE*)malloc(sizeof(NODE));
	(*t)->next = newitem;
	newitem->number = item;
	newitem->next = (*h)->next;
	(*t) = newitem;
}
//포인터의 값을 바꾸려면 이중 포인터
//구조체의 값을 바꾸려면 주소값으로 간다
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
	temp = tail;
	int cnt = 0;
	cout << '<';

	while (temp->next != temp->next->next)
	{
		if (cnt >= k-1) {
			cout << temp->next->number << ", ";
			NODE* dnode = temp->next;
			temp->next = temp->next->next;
			cnt = 0;
			free(dnode);
		}
		else {
			cnt++;
			temp = temp->next;
		}
		//temp = temp->next;
	}
	cout << temp->next->number << '>';

	free(head);

}
