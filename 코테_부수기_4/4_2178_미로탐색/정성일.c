#include <stdio.h>
#include <stdlib.h>

void erosion(int** mat, int** que, int* que_focus, int* time, int n, int m) {
	int i, j, k;
	int x, y;
	int new_tail = que_focus[1];

	/////////////////////////////////////////////////////
	//  BFS
	/////////////////////////////////////////////////////
	*time = *time + 1;  //시간 1 증가
	for (i = que_focus[0]; i <= que_focus[1]; i++) {  //큐에 있는 정점들 탐색
		x = que[i][0];  //정점 좌표 저장
		y = que[i][1];
		if (x == n && y == m) {  //목표 정점 도달하면 종료
			return 0;
		}
		for (j = -1; j < 2; j++) {
			for (k = -1; k < 2; k++) {  //정점 상하좌우에
				if (j + k != 0 && j * k == 0 && mat[x + j][y + k] == 0) {  //안 가본 길이 있으면 있으면
					mat[x + j][y + k] = 1;  //방문표시
					new_tail++;  //큐에 추가
					que[new_tail][0] = x + j;
					que[new_tail][1] = y + k;
				}
			}
		}
	}
	/////////////////////////////////////////////////////
	//  큐에 추가된 정점 없으면 -1 반환
	/////////////////////////////////////////////////////
	if (que_focus[1] == new_tail) {
		*time = -1;
		return 0;
	}
	/////////////////////////////////////////////////////
	//  큐의 처음과 끝 수정
	/////////////////////////////////////////////////////
	que_focus[0] = que_focus[1] + 1;
	que_focus[1] = new_tail;
	/////////////////////////////////////////////////////
	//  다음단계 진입
	/////////////////////////////////////////////////////
	erosion(mat, que, que_focus, time, n, m);

	return 0;
}

int main() {
	int** mat;
	int** que;
	int* que_focus;
	int* time;
	int m, n;
	int i, j;
	int target_tail = 0;
	char ch_temp;

	/////////////////////////////////////////////////////
	//  변수 입력
	/////////////////////////////////////////////////////
	scanf("%d %d", &n, &m);
	/////////////////////////////////////////////////////
	//  큐와 맵 할당 및 매핑
	/////////////////////////////////////////////////////
	mat = (int**)malloc(sizeof(int*) * (n + 2));  //맵 1차 할당
	que = (int**)malloc(sizeof(int*) * (n * m));  //큐 1차 할당
	que_focus = (int*)malloc(sizeof(int) * 2);  //큐 head tail 포인터 할당
	time = (int*)malloc(sizeof(int));  //시간 변수 할당
	que_focus[0] = 0;  //큐의 head와 tail 지정
	que_focus[1] = -1;
	*time = 0;  //시간 0초로 초기화
	for (i = 0; i < (n * m); i++) {
		que[i] = (int*)malloc(sizeof(int) * 2);  //큐 2차 할당
	}
	for (i = 0; i <= n + 1; i++) {
		mat[i] = (int*)malloc(sizeof(int) * (m + 2));  //맵 2차 할당
		for (j = 0; j <= m + 1; j++) {
			if (i == 0 || i == n + 1 || j == 0 || j == m + 1) {
				mat[i][j] = -1;  //테두리를 -1 표시
			}
			else {
				scanf(" %c", &ch_temp);  //길 입력
				if (ch_temp == '0') {  //벽 표시
					mat[i][j] = -1;
				}
				if (ch_temp == '1') {  //길 표시
					mat[i][j] = 0;
				}
			}
		}
	}
	mat[1][1] = 1;  //시작점 매핑
	que_focus[1]++;  //시작점 큐 추가
	que[que_focus[1]][0] = 1;
	que[que_focus[1]][1] = 1;
	/////////////////////////////////////////////////////
	//  BFS 시작
	/////////////////////////////////////////////////////
	erosion(mat, que, que_focus, time, n, m);
	/////////////////////////////////////////////////////
	//  결과 출력
	/////////////////////////////////////////////////////
	printf("%d", *time);

	return 0;
}
