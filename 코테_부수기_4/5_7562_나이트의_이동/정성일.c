#include <stdio.h>
#include <stdlib.h>

void move(int** mat, int size, int* time, int** que, int* que_focus, int* target) {
	int i, j, k, l;  //반복문 변수
	int x, y;  //현재 좌표
	int nx, ny;  //이동할 좌표
	int new_tail = que_focus[1]; //큐 추가 위치

	for (i = que_focus[0]; i <= que_focus[1]; i++) {  //큐에 있는 정점들
		x = que[i][0];  //좌표 저장
		y = que[i][1];
		if (x == target[0] && y == target[1]) {  //목표좌표에 도착하면
			return 0;   //종료
		}
		for (j = -1; j < 2; j += 2) {
			for (k = -1; k < 2; k += 2) {
				for (l = 1; l < 3; l++) {
					nx = x + j * (l);  //이동할 수 있는 좌표
					ny = y + k * (3 - l);
					if (0 <= nx && nx < size && 0 <= ny && ny < size) {  //말판 안에 있으면
						if (mat[nx][ny] == 0) {  //가본적 없는 좌표인지 검사
							mat[nx][ny] = 1;  //방문 표시
							new_tail++;  //큐에 추가
							que[new_tail][0] = nx;
							que[new_tail][1] = ny;
						}
					}
				}
			}
		}
	}
	*time = *time + 1;  //이동횟수 +1
	que_focus[0] = que_focus[1] + 1;  //큐의 head tail 변경
	que_focus[1] = new_tail;

	move(mat, size, time, que, que_focus, target);  //다음단계 진입

	return 0;
}

int main() {
	int test_case;
	int size;
	int** mat;
	int** que;
	int* que_focus;
	int* time;
	int* target;
	int i, j;

	///////////////////////////////////////////////////////////////
	// 말판 크기 상관없는 변수들 할당
	///////////////////////////////////////////////////////////////
	que_focus = (int*)malloc(sizeof(int) * 2);  //큐의 head와 tail
	target = (int*)malloc(sizeof(int) * 2);  //목표 좌표
	time = (int*)malloc(sizeof(int));  //횟수

	///////////////////////////////////////////////////////////////
	// 반복횟수 입력 및 반복
	///////////////////////////////////////////////////////////////
	scanf("%d", &test_case);   
	for (; test_case > 0; test_case--) {
		///////////////////////////////////////////////////////////////
		// 말판 크기 입력
		///////////////////////////////////////////////////////////////
		scanf("%d", &size);

		///////////////////////////////////////////////////////////////
		// 큐와 맵 할당
		///////////////////////////////////////////////////////////////
		que = (int**)malloc(sizeof(int*) * (size * size));  //큐
		for (i = 0; i < size * size; i++) {
			que[i] = (int*)malloc(sizeof(int) * 2);
		}
		mat = (int**)malloc(sizeof(int*) * size);  //맵
		for (i = 0; i < size; i++) {
			mat[i] = (int*)malloc(sizeof(int) * size);
			for (j = 0; j < size; j++) {
				mat[i][j] = 0;
			}
		}

		///////////////////////////////////////////////////////////////
		// 시작좌표 입력 및 큐에 추가
		///////////////////////////////////////////////////////////////
		scanf("%d %d", &i, &j);  //입력
		mat[i][j] = 1;  //맵에 표시
		que[0][0] = i;  //큐에 추가
		que[0][1] = j;

		///////////////////////////////////////////////////////////////
		// 목표좌표 입력
		///////////////////////////////////////////////////////////////
		scanf("%d %d", &target[0], &target[1]);

		///////////////////////////////////////////////////////////////
		// 초기화
		///////////////////////////////////////////////////////////////
		que_focus[0] = 0; //큐 헤드
		que_focus[1] = 0; //큐 테일
		*time = 0; //이동 횟수

		///////////////////////////////////////////////////////////////
		// BFS
		///////////////////////////////////////////////////////////////
		move(mat, size, time, que, que_focus, target);

		///////////////////////////////////////////////////////////////
		// 결과 출력
		///////////////////////////////////////////////////////////////
		printf("%d\n", *time);

		///////////////////////////////////////////////////////////////
		// 맵이랑 큐 할당 해제
		///////////////////////////////////////////////////////////////
		for (i = 0; i < size * size; i++) {
			free(que[i]);
		}
		for (i = 0; i < size; i++) {
			free(mat[i]);
		}
		free(que);
		free(mat);
	}
	///////////////////////////////////////////////////////////////
	// 공통변수 할당 해제
	///////////////////////////////////////////////////////////////
	free(que_focus);
	free(target);
	free(time);

	return 0;
}
