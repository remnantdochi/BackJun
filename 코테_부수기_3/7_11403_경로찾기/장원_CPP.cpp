#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int N;

void init_visit(int* visit) //visit 배열의 초기화
{
	memset(visit, 0, N * sizeof(int));
}

void DFS(int** mat, int* visit, int k) // k번째 정점을 시작으로하는 Depth First Search
{	
	for (int i = 0; i < N; i++)
	{
		if (mat[k][i] == 1)
		{
			if (visit[i] != 1) //방문하지 않은 정점이라면, 그 정점을 통해 계속해서 탐색한다.
			{
				visit[i] = 1;
				DFS(mat, visit, i);
			}
			else //이미 방문한 정점이라면 건너뛰고 다음 정점을 탐색한다.
				continue;
		}
		else
			continue;
		}
	
}


int main()
{
	cin >> N; //총 N개의 정점

	int** mat = new int*[N]; //인접행렬 생성
	for (int i = 0; i < N; i++)
		mat[i] = new int[N];

	int** connect = new int*[N]; //경로의 존재유무를 나타내는 행렬 생성 (출력행렬)
	for (int i = 0; i < N; i++)
		connect[i] = new int[N];

	for (int i = 0; i < N; i++)
		memset(connect[i], 0, N * sizeof(int));

	int* visit = new int[N]; // visit 배열 생성. DFS시 사용되는 배열로, 정점 방문 정보를 저장하는 배열
	memset(visit, 0, N * sizeof(int));

	for (int i = 0; i < N; i++) // 인접행렬의 입력
	{
		for (int j = 0; j < N; j++)
		{
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i < N; i++) //N개의 정점에 대한 DFS 시작
	{
		init_visit(visit);
		DFS(mat, visit, i);
		for (int j = 0; j < N; j++)
			connect[i][j] = visit[j]; //정점i에서 시작하여 방문가능한 정점은 연결되었음을 의미
	}

	for (int i = 0; i < N; i++) //출력
	{
		for (int j = 0; j < N; j++)
		{
			cout << connect[i][j]<<' ';
		}
		cout << endl;
	}

	return 0;
}
