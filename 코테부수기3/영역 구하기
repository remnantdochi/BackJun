#include <iostream>
#include<cstring>
#include <string>

using namespace std;

int M, N, K;
int start_x, start_y;

int room_size[10001] = { 0, };
int room_num = 0;
int size_= 0;

int get_start_pos(int** map)
{
	int flag = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 0)
			{
				start_x = i;
				start_y = j;
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			return 1; //1을 반환하면 start_pos를 구함
		}
	}
	return 0; //0을 반환하면 start_pos를 구하지못함. (끝)
}

void DFS(int** map,int x, int y)
{
	map[x][y] = 2; // 방문체크
	size_++;
	if (x + 1 < M && map[x + 1][y] == 0) // ↑(위 탐색)
		DFS(map, x + 1, y);
	if (y + 1 < N && map[x][y + 1] == 0) // → (오른쪽 탐색)
		DFS(map, x, y + 1);
	if (x - 1 >= 0 && map[x - 1][y] == 0) // ↓ (아래 탐색)
		DFS(map, x - 1, y);
	if (y - 1 >= 0 && map[x][y - 1] == 0)
		DFS(map, x, y - 1);

}

int main()
{
	int ld_x, ld_y, ru_x, ru_y;
	cin >> M >> N >> K;
	int** map = new int*[M];
	for (int i = 0; i < M; i++)
		map[i] = new int[N];
	for (int i = 0; i < M; i++)
		memset(map[i], 0, N * sizeof(int));

	for (int i = 0; i < K; i++)
	{
		cin >> ld_x >> ld_y >> ru_x >> ru_y;
		for (int i = ld_y; i < ru_y; i++)
		{
			for (int j = ld_x; j < ru_x; j++)
			{
				map[i][j] = 1;
			}
		}
	}
	
	while (get_start_pos(map))
	{
		room_num++;
		DFS(map,start_x,start_y);
		room_size[room_num] = size_;
		size_ = 0;
	}
	for (int i = 1; i <= room_num; i++)
	{
		for (int j = i; j <= room_num; j++)
		{
			if (room_size[i] > room_size[j])
			{
				int temp;
				temp = room_size[i];
				room_size[i] = room_size[j];
				room_size[j] = temp;
			}
		}
	}
	cout << room_num << endl;

	for (int i = 1; i <= room_num; i++)
		cout << room_size[i]<<' ';

	delete[]map;
	return 0;
}
