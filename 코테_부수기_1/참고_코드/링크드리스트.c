    
//2019-01-24 JANGWON KIM

//*Doubly linked circular list*
//노드는 1번부터 사용 및 시작. (head 노드의 번호는 1.)
//명령 함수는 add, get, insert, delete.

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int key;
	struct node* next;
	struct node* prev;	
}NODE;

int list_size; // 노드의 수

int get(int N, NODE** head) //N번째 노드의 key값을 추출
{
	NODE* desired_node;
	desired_node = *head;
	if (list_size == 0)
	{
		printf("Error <get>: The linked-list is empty!\n");
		exit(1);
	}
	else if(N<1)	
	{
		printf("Error <get>: Wrong number!(N<1)\n");
		exit(1);
	}
	else if (N > list_size)		
	{
		printf("Error <get>: The list has fewer number of nodes than N !\n");
		exit(1);
	}
	else if(N>=2&&N<=list_size/2) //정방향으로 탐색
	{
		NODE* desired_node = *head;
		for (int i = 1; i < N; i++)
		{
			desired_node = desired_node->next;
		}
		return desired_node->key;
	}
	else if (N>=2&&N>list_size/2) //역방향으로 탐색
	{
		NODE* desired_node = *head;
		for (int i = 0; i < list_size-N+1; i++)
		{
			desired_node = desired_node->prev;
		}
		return desired_node->key;
	}
	else //N==1
		return (*head)->key;
					
}
void add(int key, NODE** head) // 링크의 끝에 새로운 노드를 추가
{
	if (list_size!=0) 
	{
		NODE* temp = (NODE*)malloc(sizeof(NODE));
		temp->key = key;
		temp->next=*head;
		temp->prev = (*head)->prev;
		(*head)->prev->next = temp;
		temp->next = *head;
		(*head)->prev = temp;
		list_size = list_size + 1;
	}
	else
	{
		(*head)->key = key;
		list_size = list_size + 1;
	}
}
void delete(int N, NODE** head) //N 번째 노드를 제거
{  
	if (list_size == 0)
	{
		printf("Error <delete>: The linked-list is already empty!\n");
		return;
	}
	else if (N > list_size)
	{
		printf("Error <delete>: The list has fewer number of nodes than N!\n");
		return;
	}
	else if (N < 1)
	{
		printf("Error <delete>: Wrong number!(N<1)\n");
		return;
	}
	else if (N == 1&&list_size>1) //노드의 수가 2이상 이면서 head노드를 지운다면
	{
		NODE* delete_node = *head;
		(*head)->prev->next = (*head)->next;
		(*head)->next->prev = (*head)->prev;
		(*head)=(*head)->next; 
		list_size = list_size - 1;
		free(delete_node);
	}
	else if (N == 1 && list_size == 1) //노드의 수가 하나만 존재할 때 head노드를 지운다면,
	{   //초기화
		(*head)->key; 
		(*head)->next = (*head);
		(*head)->prev = (*head);
		list_size = list_size - 1; 

	}
	else if (N >= 2 && N <= list_size / 2)//-> 정방향 탐색
	{ //노드의 수가 2이상 이면서 중간 노드를 지운다면,
		NODE* delete_node = *head;
		for (int i = 1; i < N; i++)
		{
			delete_node = delete_node->next;
		}
		delete_node->prev->next = delete_node->next;
		delete_node->next->prev = delete_node->prev;
		
		list_size = list_size - 1;
		free(delete_node);
	}
	else //(N >= 2 && N > list_size / 2) ->역방향 탐색
	{ //노드의 수가 2이상 이면서 중간 노드를 지운다면,
	NODE* delete_node = *head;
	for (int i = 0; i < list_size-N+1; i++)
	{
		delete_node = delete_node->prev;
	}
	delete_node->prev->next = delete_node->next;
	delete_node->next->prev = delete_node->prev;

	list_size = list_size - 1;
	free(delete_node);
	}
}
void insert(int N, int key, NODE** head) //N 번째에 새로운 노드를 삽입
{

	if (N < 1)
	{
		printf("Error <insert>: Wrong number!(N<1)\n");
		return;
	}
	else if (N > list_size)
	{
		printf("Error <insert>: N can't be bigger than list_size!\n");
		return;
	}
	else if (N == 1) // head 노드가 바뀌어 진다.
	{
		NODE* new_node = (NODE*)malloc(sizeof(NODE));
		new_node->key = key;
		new_node->next = *head;;
		new_node->prev = (*head)->prev;
		(*head)->prev->next = new_node;
		(*head)->prev = new_node;
		(*head)=new_node;
		list_size = list_size + 1;
	}
	else if (N <= list_size / 2) //정방향 탐색
	{
		NODE* before_node = *head;
		for (int i =1; i < N; i++)
		{
			before_node = before_node->next;
		}
		NODE* new_node = (NODE*)malloc(sizeof(NODE));
		new_node->key = key;
		new_node->next = before_node;
		new_node->prev = before_node->prev;
		before_node->prev->next = new_node;
		before_node->prev = new_node;
		list_size = list_size + 1;
	}
	else if (N > list_size / 2) //역방향 탐색
	{
		NODE* before_node = *head;
		for (int i = 0; i < list_size-N+1; i++)
		{
			before_node = before_node->prev;
		}
		NODE* new_node = (NODE*)malloc(sizeof(NODE));
		new_node->key = key;
		new_node->next = before_node;
		new_node->prev = before_node->prev;
		before_node->prev->next = new_node;
		before_node->prev = new_node;
		list_size = list_size + 1;
	}
	
	
}


int main()
{
	NODE* head=(NODE*)malloc(sizeof(NODE)); //노드는 1번부터 사용 및 시작. (head 노드의 번호는 1.)
	list_size = 0;
	head->key; 
	head->next = head;
	head->prev = head; //초기화 작업 끝.
	
	return 0;
}
