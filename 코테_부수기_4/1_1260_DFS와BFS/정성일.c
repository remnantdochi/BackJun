#include <stdio.h>
#include <stdlib.h>

void dfs(int** mat, int* dfs_visit, int* dfs_cnt, int n, int focus) {
	//focus가 pop할 정점을 나타냄;
	int i, j, d_visit;

	for (i = 1; i <= n; i++) {
		if (mat[focus][i] == 1) {  //간선이 있으면
			d_visit = 0;
			for (j = 0; j < *dfs_cnt; j++) {  //방문기록 체크
				if (dfs_visit[j] == i) {
					d_visit = 1;
					break;
				}
			}
			if (d_visit == 0) {
				dfs_visit[*dfs_cnt] = i;  //스택에 정점 추가
				*dfs_cnt = *dfs_cnt + 1;
				dfs(mat, dfs_visit, dfs_cnt, n, i);  //다음 dfs 실행
			}
		}
	}
	//더이상 들어갈 간선이 없으면 끝

	return 0;
}

void bfs(int** mat, int* bfs_visit, int* bfs_cnt, int n, int focus) {
	//focus가 방문기록에서 최고 depth 시작점 위치 나타냄
	int i, j, k, d_visit, temp;

	temp = *bfs_cnt;
	for (i = focus; i < temp; i++) {   //최근 depth 정점들중에
		for (j = 1; j <= n; j++) {
			if (mat[bfs_visit[i]][j] == 1) {  //간선이 있으면
				d_visit = 0;
				for (k = 0; k < *bfs_cnt; k++) {  //방문기록 체크
					if (bfs_visit[k] == j) {
						d_visit = 1;
						break;
					}
				}
				if (d_visit == 0) {  //다음 depth의 정점들 추가
					bfs_visit[*bfs_cnt] = j;
					*bfs_cnt = *bfs_cnt + 1;
				}
			}
		}
	}
	if (temp != *bfs_cnt) {  //추가된 정점이 있으면
		bfs(mat, bfs_visit, bfs_cnt, n, temp);  //다음 단계 탐색
	}

	return 0;
}

int main() {
	int n, m, v;
	int i, j;
	int x, y;
	int* dfs_cnt;
	int* bfs_cnt;
	int** mat;
	int* dfs_visit;
	int* bfs_visit;


	///////////////////////////////////////////
	// 인수 입력
	///////////////////////////////////////////
	scanf("%d %d %d", &n, &m, &v);

	///////////////////////////////////////////
	// 방문기록 생성
	///////////////////////////////////////////
	dfs_visit = (int*)malloc(sizeof(int) * n);
	bfs_visit = (int*)malloc(sizeof(int) * n);
	dfs_cnt = (int*)malloc(sizeof(int));
	bfs_cnt = (int*)malloc(sizeof(int));
	*dfs_cnt = 0;
	*bfs_cnt = 0;

	///////////////////////////////////////////
	// 간선 행렬화
	///////////////////////////////////////////
	mat = (int**)malloc(sizeof(int*) * (n + 1));
	for (i = 0; i < n+1; i++) {
		mat [i]= (int*)malloc(sizeof(int) * (n + 1));
		for (j = 0; j < n+1; j++) {
			mat[i][j] = 0;
		}
	}
	for (i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		mat[x][y] = 1;
		mat[y][x] = 1;
	}

	///////////////////////////////////////////
	// 시작점 추가
	///////////////////////////////////////////
	dfs_visit[*dfs_cnt] = v;
	bfs_visit[*bfs_cnt] = v;
	*dfs_cnt = *dfs_cnt + 1;
	*bfs_cnt = *bfs_cnt + 1;

	///////////////////////////////////////////
	// 탐색
	///////////////////////////////////////////
	dfs(mat, dfs_visit, dfs_cnt, n, v);
	bfs(mat, bfs_visit, bfs_cnt, n, 0);

	///////////////////////////////////////////
	// 결과 출력
	///////////////////////////////////////////
	for (i = 0; i < *dfs_cnt; i++) {
		printf("%d ", dfs_visit[i]);
	}
	printf("\n");
	for (i = 0; i < *bfs_cnt; i++) {
		printf("%d ", bfs_visit[i]);
	}


	///////////////////////////////////////////
	// 할당 해제
	///////////////////////////////////////////
	for (i = 0; i <= n; i++) {
		free(mat[i]);
	}
	free(mat);
	free(bfs_visit);
	free(bfs_cnt);
	free(dfs_visit);
	free(dfs_cnt);

	return 0;
}
