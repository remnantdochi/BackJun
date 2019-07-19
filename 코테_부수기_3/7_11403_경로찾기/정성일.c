#include <stdio.h>

void dfs(int** mat, int** way, int n, int start, int focus) {
	int i = 0;
	int check = 1;

	for (i = 0; i < n; i++) {  //체크해본 점인지 확인
		if (way[focus][0] == -1) {
			check = 0;
			break;
		}
	}

	if (check==0) {  //확인되지 않은 출발점이면
		for (i = 0; i < n; i++) {
			if (mat[focus][i] == 1 && way[start][i] != 1) {  //가본적 없는 길이면
				way[start][i] = 1;
				if (start != i) {  //루프가 아니면
					dfs(mat, way, n, start, i);  //진입
				}
			}
		}
	}
	else {  //이미 확인된 출발점
		for (i = 0; i < n; i++) {
			if (way[focus][i] == 1) {  //이 출발점에서 갈수 있는곳은
				way[start][i] = 1;  //다 갈수 있다.
			}
		}
	}

	return 0;
}

int main() {
	int n;
	int i, j;
	int** mat;
	int** way;

	scanf("%d", &n);  //그리드 크기 입력

	mat = (int**)malloc(sizeof(int*) * n);  //입력용 행렬
	way = (int**)malloc(sizeof(int*) * n);  //출력용 행렬
	for (i = 0; i < n; i++) {
		mat[i] = (int*)malloc(sizeof(int) * n);
		way[i] = (int*)malloc(sizeof(int) * n);
		for (j = 0; j < n; j++) {
			scanf("%d", &mat[i][j]);  //입력
			way[i][j] = -1;  //출력행렬 초기화
		}
	}

	for (i = 0; i < n; i++) {  //모든점으로 진입
		dfs(mat, way, n, i, i);
		for (j = 0; j < n; j++) {  //진입이 끝났으면
			if (way[i][j] == -1) {  //나머지 못 가는 점 정리
				way[i][j] = 0;
			}
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", way[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < n; i++) {
		free(way[i]);
		free(mat[i]);
	}
	free(way);
	free(mat);

	return 0;
}
