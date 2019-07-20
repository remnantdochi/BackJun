#include <stdio.h>
#include <stdlib.h>

// head, tail은 큐의 head, tail
void bfs(int* level, int* visit, int* visit_mat, int k, int head, int tail) {
	int i, j;  //for문용 변수
	int t1, t2, t3;  //새로 정점 방문 여부
	int v1, v2, v3;  //새로운 정점
	int new_tail;  //다음단계 큐의 tail

	if (visit_mat[k] == 1) {  //k에 도달했으면
		return 0;  //종료
	}
	*level = *level + 1;  //단계+1
	new_tail = tail;
	for (i = head; i <= tail; i++) {  //큐에 들어있는 정점들 모두
		t1 = 0;
		t2 = 0;
		t3 = 0;
		v1 = visit[i] + 1;  //이동 가능한 정점 저장
		v2 = visit[i] - 1;
		v3 = visit[i] * 2;
		if (v1 > 100000 || visit_mat[v1] == 1) {  //범위를 벗어나거나 방문했으면
			t1 = 1;  //방문 X
		}
		if (v2 < 0 || visit_mat[v2] == 1) {  //범위를 벗어나거나 방문했으면
			t2 = 1;  //방문 X
		}
		if (v3 > 100000 || visit_mat[v3] == 1) {  //범위를 벗어나거나 방문했으면
			t3 = 1;  //방문 X
		}
		if (t1 == 0) {
			new_tail++;  //다음단계 큐의 크기 증가
			visit[new_tail] = v1;  //큐에 추가
			visit_mat[v1] = 1;  //방문여부 기록
		}
		if (t2 == 0) {
			new_tail++;
			visit[new_tail] = v2;
			visit_mat[v2] = 1;
		}
		if (t3 == 0) {
			new_tail++;
			visit[new_tail] = v3;
			visit_mat[v3] = 1;
		}
	}
	if (tail == new_tail) {  //추가된게 없으면 종료
		return 0;
	}

	bfs(level, visit, visit_mat, k, tail+1, new_tail);  //다음단계 진입

	return 0;
}

int main() {
	int n, k;
	int i;
	int* level;
	int* visit;
	int* visit_mat;

	/////////////////////////////////////////////////////////////
	//  할당
	/////////////////////////////////////////////////////////////
	level = (int*)malloc(sizeof(int));  //depth 단계
	visit = (int*)malloc(sizeof(int) * 100001);  //bfs용 큐
	visit_mat = (int*)malloc(sizeof(int) * 100001);  //방문여부표

	/////////////////////////////////////////////////////////////
	//  초기화
	/////////////////////////////////////////////////////////////
	for (i = 0; i <= 100000; i++) {
		visit_mat[i] = 0;
		visit[i] = 0;
	}

	/////////////////////////////////////////////////////////////
	//  변수 입력 및 초기 세팅
	/////////////////////////////////////////////////////////////
	scanf("%d %d", &n, &k);
	visit[0] = n;  //큐에 n을 넣음
	visit_mat[n] = 1;  //n 방문 표시
	*level = 0;  //depth 0

	/////////////////////////////////////////////////////////////
	//  bfs
	/////////////////////////////////////////////////////////////
	bfs(level, visit, visit_mat, k, 0, 0);

	/////////////////////////////////////////////////////////////
	//  결과 출력
	/////////////////////////////////////////////////////////////
	printf("%d", *level);

	/////////////////////////////////////////////////////////////
	//  할당 해제
	/////////////////////////////////////////////////////////////
	free(visit);
	free(visit_mat);
	free(level);

	return 0;
}
