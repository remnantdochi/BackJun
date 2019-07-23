#include <iostream>
#include <string>
#include<cstring>
using namespace std;
int cnt = 0;

typedef struct cell {
	struct cell* go[10];
	int next_visit[10];
}Cell;

void init_Cell(Cell* cell)
{
	for (int i = 0; i < 10; i++) {
		cell->next_visit[i] = 0;
	}
}

void delete_memory(Cell* pos)
{
	int flag = 0;
	for (int i = 0; i < 10; i++)
	{
		if (pos->next_visit[i]) {
			flag = 1;
			delete_memory(pos->go[i]);
			flag = 0;
		}
	}
	if (!flag) {
		cnt++;
		delete[]pos;
	}

}

int main()
{
	int T;
	cin >> T;
	for(int i=0;i<T;i++)
	{ 
		int found = 0;
		int n, start_pos;
		cin >> n;
		Cell* head = new Cell;
		init_Cell(head);
		string* str_set = new string[n];

		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			str_set[i] = str;
			int str_size = str.size();			
			Cell* pos = head;
			for (int i = 0; i < str_size; i++)
			{
				if (!pos->next_visit[str[i] - 48]) {
					pos->next_visit[str[i] - 48] = 1;
					Cell* new_pos = new Cell;
					init_Cell(new_pos);
					pos->go[str[i] - 48] = new_pos;
					pos = new_pos;
				}
				else
					pos = pos->go[str[i] - 48];
			}

		}
		for (int i = 0; i < n; i++)
		{
			string t_str = str_set[i];
			int t_str_size = t_str.size();
			Cell* scan_cell = head;
			for (int i = 0; i < t_str_size; i++)
			{
				scan_cell = scan_cell->go[t_str[i] - 48];
			}
			for (int i = 0; i < 10; i++)
			{
				if (scan_cell->next_visit[i])
				{
					found = 1;
					break;
				}
			}
			if (found)
				break;
		}
		if (found)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';


		delete[]str_set;
		delete_memory(head);
	}

	return 0;
}
