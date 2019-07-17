#include <iostream>
using namespace std;
int N, k;
int list_size = 0;

typedef struct node
{
	int number;
	struct node* next;
	struct node* prev;
}NODE;

void add(NODE* head_ptr)
{
	if (list_size != 0)
	{
		NODE* temp = head_ptr;
		for (int i = 0; i < list_size; i++)
		{
			temp = temp->next;
		}
		NODE* new_node = (NODE*)malloc(sizeof(NODE));
		new_node->next = temp->next;
		new_node->number = list_size + 1;
		new_node->prev = temp;
		temp->next = new_node;
		
		head_ptr->next->prev = new_node;
		list_size++;
	}
	else
	{
		NODE* new_node = (NODE*)malloc(sizeof(NODE));
		head_ptr->next = new_node;
		new_node->number = 1;
		new_node->next = new_node;
		new_node->prev = new_node;

		list_size = 1;
	}
}

int main()
{
	NODE head;
	head.number = 0;
	head.next = NULL;
	head.prev = NULL;

	cin >> N>>k;

	for (int i = 0; i < N; i++)
	{
		add(&head);
	}

	
	NODE* temp;
	temp = &head;
	
	cout << '<';
	while (1)
	{
		NODE* deleted_node;
		for (int i = 0; i < k; i++)
		{
			temp = temp->next;
		}

		if (temp->next == temp)
		{
			cout << temp->number<<'>';
			break;
		}
		else
		{
			cout << temp->number << ','<<' ';
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			deleted_node = temp;
			temp = temp->prev;
			free(deleted_node);
		}

	}
	
}
