/* char 배열로 문자열을 다뤄도 좋지만, string 클래스를 이용하여 코드를 짠다면 더 수월하다.*/
/*https://makerj.tistory.com/127 참고*/

#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define queue_size 10000
int R, C;
int cnt=0;
int MAX = 0;
typedef struct item {
	string s;
	int i;
	int j;
	int count;
}ITEM;

ITEM queue[queue_size];

int front = queue_size - 1;
int rear = -1;


void push(ITEM a)
{
	cnt++;
	front = (front + 1) % queue_size;
	queue[front] = a;
}

ITEM pop()
{
	cnt--;
	rear = (rear + 1) % queue_size;
	return queue[rear];
}

int main()
{
	cin >> R>>C;
	char** map = new char*[R];
	for (int i = 0; i < R; i++)
		map[i] = new char[C];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	ITEM first_item;
	first_item.s.clear();
	first_item.s = map[0][0];
	first_item.count = 1;
	first_item.i = 0;
	first_item.j = 0;

	push(first_item);
	while (cnt != 0)
	{
		ITEM temp = pop();
		if (temp.count > MAX)
			MAX = temp.count;

		if (temp.i - 1 >= 0) //↑
		{
			if (temp.s.find(map[temp.i - 1][temp.j]) == string::npos)
			{
				ITEM new_item;
				new_item.s = temp.s;
				new_item.s += map[temp.i - 1][temp.j];
				new_item.i = temp.i - 1;
				new_item.j = temp.j;
				new_item.count = temp.count + 1;
				push(new_item);
			}
		}
		if (temp.j + 1 <= C-1) //→
		{
			if (temp.s.find(map[temp.i][temp.j+1]) == string::npos)
			{
				ITEM new_item;
				new_item.s = temp.s;
				new_item.s += map[temp.i][temp.j+1];
				new_item.i = temp.i;
				new_item.j = temp.j+1;
				new_item.count = temp.count + 1;
				push(new_item);
			}
		}
		if (temp.i + 1 <= R - 1) //↓
		{
			if (temp.s.find(map[temp.i+1][temp.j]) == string::npos)
			{
				ITEM new_item;
				new_item.s = temp.s;
				new_item.s += map[temp.i+1][temp.j];
				new_item.i = temp.i+1;
				new_item.j = temp.j;
				new_item.count = temp.count + 1;
				push(new_item);
			}
		}
		if (temp.j - 1 >=0) //←
		{
			if (temp.s.find(map[temp.i][temp.j-1]) == string::npos)
			{
				ITEM new_item;
				new_item.s = temp.s;
				new_item.s += map[temp.i][temp.j-1];
				new_item.i = temp.i;
				new_item.j = temp.j-1;
				new_item.count = temp.count + 1;
				push(new_item);
			}
		}
		
	}
	cout << MAX;
	delete[]map;
	return 0;
}
