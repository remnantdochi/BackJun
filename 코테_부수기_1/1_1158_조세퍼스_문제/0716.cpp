//참고https://zoomkoding.github.io/codingtest/2019/06/29/baekjoon-1158.html

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

typedef struct node
{
	int number;
	struct node* next;
}NODE;

/*void insert(int item, int k, NODE* h) //k번째 노드 뒤에 삽입
{
	NODE* newitem = (NODE*)malloc(sizeof(NODE));
	int cnt = 1;
	NODE* node_ptr = (NODE*)malloc(sizeof(NODE));
	node_ptr= h->next;
	
	while (cnt != k || node_ptr != h->next){
		node_ptr = node_ptr->next;
		cnt++;
	}

	newitem->number = item;
	newitem->next = node_ptr->next;
	node_ptr->next = newitem;

	free(node_ptr);
}*/



void add(int item, NODE* h, NODE* t) // 맨 뒤에 추가
{
	NODE* newitem = (NODE*)malloc(sizeof(NODE));
	if ( h->next== NULL)
	{
		h->next = newitem;
		newitem->number = item;
		newitem->next = h->next;
		t->number = newitem->number;
		t->next = newitem->next;

	}
	else
	{
		t->next = newitem;
		newitem->number = item;
		newitem->next = h->next;
		t = newitem;
	}
}

int main() {
	NODE* head=(NODE*)malloc(sizeof(NODE));
	head->next = NULL;
	head->number = 0;
	NODE* tail = (NODE*)malloc(sizeof(NODE));
	

	int n, k, count = 0;
	cin >> n >> k;

	for (int i = 0;i < n;i++)
	{
		add(i + 1, head, tail);
	}

	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp = head->next;
	for (int i = 0;i < n;i++)
	{
		NODE* temp = (NODE*)malloc(sizeof(NODE));
		
		cout << temp->number;
		temp = temp->next;
	}
	

}