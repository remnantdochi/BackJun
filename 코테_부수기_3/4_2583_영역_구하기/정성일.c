#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////
// 노드 구조 선언
//////////////////////////////////////////////////////////////////////////
struct Node {
	int data;
	struct Node* prevnode;
	struct Node* nextnode;
};

//////////////////////////////////////////////////////////////////////////
// 노드 추가 함수
//////////////////////////////////////////////////////////////////////////
struct Node* AddNode(struct Node* focus, int data) {
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));

	newnode->data = data;
	if (focus == NULL) {
		newnode->nextnode = NULL;
		newnode->prevnode = NULL;
	}
	else if (focus->nextnode == NULL) {
		newnode->prevnode = focus;
		newnode->nextnode = NULL;
		newnode->prevnode->nextnode = newnode;
	}
	else {
		newnode->prevnode = focus;
		newnode->nextnode = focus->nextnode;
		newnode->prevnode->nextnode = newnode;
		newnode->nextnode->prevnode = newnode;
	}

	return newnode;
}

//////////////////////////////////////////////////////////////////////////
// 노드 삭제 함수
//////////////////////////////////////////////////////////////////////////
struct Node* DeleteNode(struct Node* focus) {
	struct Node* prev = focus->prevnode;
	struct Node* next = focus->nextnode;

	free(focus);
	if (prev != NULL) {
		prev->nextnode = next;
	}
	if (next != NULL) {
		next->prevnode = prev;
		return next;
	}
	if (prev == NULL) {
		return next;
	}
	return prev;
}

//////////////////////////////////////////////////////////////////////////
// 노드 출력 함수
//////////////////////////////////////////////////////////////////////////
struct Node* PrintNode(struct Node* focus) {

	if (focus == NULL) {
		//printf("\n");
		return NULL;
	}
	printf("%d ", focus->data);

	return PrintNode(focus->nextnode);
}

//////////////////////////////////////////////////////////////////////////
int main() {
	struct Node* tail;
	struct Node* head;
	struct Node* score_head;
	struct Node* score_focus;
	int n, m, o;
	int i, j, k;
	int temp1, temp2;
	int** mat;
	int* visited;
	int visited_cnt = 0;
	int visited_cnt2 = 0;
	int group_cnt = 0;
	int test_cnt = 0;
	int** map;
	int x, y;
	int s1, s2, s3, s4;
	int blank;

	test_cnt=1;  //테스트횟수 입력
	score_head = NULL;
	score_focus = NULL;

	for (test_cnt; test_cnt > 0; test_cnt--) {  //테스트 반복
		group_cnt = 0;  //초기화
		visited_cnt = 0;
		blank = 0;
		//////////////////////////////////////////////////////////////////////////
		// 인수 입력
		//////////////////////////////////////////////////////////////////////////
		scanf("%d %d %d", &y, &x, &o);
		
		//////////////////////////////////////////////////////////////////////////
		// 지도 저장 공간 할당 및 초기화
		//////////////////////////////////////////////////////////////////////////
		map = (int**)malloc(sizeof(int*) * (x + 1));
		for (i = 0; i <= x; i++) {
			map[i] = (int*)malloc(sizeof(int) * (y + 1));
			for (j = 0; j <= y; j++) {
				map[i][j] = 1;
				if (i == x || j == y) {
					map[i][j] = 0;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////
		// 사각형 매핑
		//////////////////////////////////////////////////////////////////////////
		for (i = 0; i < o; i++) {
			scanf("%d %d %d %d", &s1, &s2, &s3, &s4);
			for (j = s1; j < s3; j++) {
				for (k = s2; k < s4; k++) {
					map[j][k] = 0;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////
		// 간선 저장 공간 할당 및 초기화 (더블포인터 (2*x*y)*2 크기)
		//////////////////////////////////////////////////////////////////////////
		mat = (int**)malloc(sizeof(int*) * x * y * 2);
		for (i = 0; i < x * y * 2; i++) {
			mat[i] = (int*)malloc(sizeof(int) * 2);
			mat[i][0] = 0;
			mat[i][1] = 0;
		}

		//////////////////////////////////////////////////////////////////////////
		// 간선 저장
		//////////////////////////////////////////////////////////////////////////
		m = 0;
		for (i = 0; i < x; i++) {
			for (j = 0; j < y; j++) {
				if (map[i][j] == 1) {  //빈칸 위치
					blank++;
					if (map[i + 1][j] == 1) {  //오른쪽에 있으면 간선 추가
						mat[m][0] = i * 100 + j;  //빈칸 정점 100*x+y로 표시
						mat[m][1] = (i + 1) * 100 + j;
						m++;
					}
					if (map[i][j + 1] == 1) {  //아래쪽에 있으면 간선 추가
						mat[m][0] = i * 100 + j;
						mat[m][1] = i * 100 + j + 1;
						m++;
					}
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////
		// 방문기록 행렬 할당 및 초기화 (빈칸 크기)
		//////////////////////////////////////////////////////////////////////////
		visited = (int*)malloc(sizeof(int) * blank);
		for (i = 0; i < blank; i++) {
			visited[i] = -1;
		}
		n = blank;
		score_head = AddNode(score_head, 100000);  //더미 너비 노드 시작점 추가
		//////////////////////////////////////////////////////////////////////////
		// DFS
		//////////////////////////////////////////////////////////////////////////
		while (visited_cnt != n) {  //모든 정점을 방문할때까지
			head = NULL;  //스택 초기화
			tail = NULL;
			//////////////////////////////////////////////////////////////////////////
			// 스택 시작점 만들기 (새로운 그룹 탐색)
			//////////////////////////////////////////////////////////////////////////
			for (i = 0; i < m; i++) {  //모든 간선 첫번째 정점 검사
				temp1 = 0;
				for (j = 0; j < visited_cnt; j++) {  //방문한 적이 있는지 검사
					if (mat[i][0] == visited[j]) {
						temp1 = 1;
						break;
					}
				}
				if (temp1 == 0) {  //방문한 적이 없으면
					head = AddNode(NULL, mat[i][0]);  //노드 생성
					tail = head;  //head tail 지정
					visited[visited_cnt] = mat[i][0];  //방문 정점 추가
					visited_cnt++;
					visited_cnt2=1;
					group_cnt++;  //그룹 1 증가
					break;
				}
			}
			//////////////////////////////////////////////////////////////////////////
			// 시작점 만들기 실패시 고립된 점이 존재
			//////////////////////////////////////////////////////////////////////////
			if (tail == NULL) {
				group_cnt += n - visited_cnt;
				for (k = 0; k < n - visited_cnt; k++) {  //고립된 점 만큼
					score_focus = score_head;
					score_focus = AddNode(score_focus, 1);  //너비 1 추가
				}
				break;
			}
			//////////////////////////////////////////////////////////////////////////
			// 스택 DFS
			//////////////////////////////////////////////////////////////////////////
			while (tail != NULL) {
				//PrintNode(head);  //단계별 스택 출력 코드
				temp1 = tail->data;
				tail = DeleteNode(tail);  //stack pop
				if (tail == NULL) {  //스택이 비었으면
					head = NULL;  //head tail NULL
				}
				for (i = 0; i < m; i++) {  //모든 간선에서
					if (mat[i][0] == temp1) {  //첫번쨰 정점이 팝한 정점과 일치하면
						temp2 = 0;
						for (j = 0; j < visited_cnt; j++) {  //건너편 정점 방문했는지 확인
							if (visited[j] == mat[i][1]) {
								temp2 = 1;
							}
						}
						if (temp2 == 0) {  //방문한적 없으면
							tail = AddNode(tail, mat[i][1]);  //스택 추가
							if (head == NULL) {  //스택이 비어있었을경우
								head = tail;  //head 재지정
							}
							visited[visited_cnt] = mat[i][1];  //방문 정점 추가
							visited_cnt++;
							visited_cnt2++;
						}
					}
					else if (mat[i][1] == temp1) {  //두번쨰 정점이 팝한 정점과 일치하면
						temp2 = 0;
						for (j = 0; j < visited_cnt; j++) {  //건너편 정점 방문했는지 확인
							if (visited[j] == mat[i][0]) {
								temp2 = 1;
							}
						}
						if (temp2 == 0) {  //방문한적 없으면
							tail = AddNode(tail, mat[i][0]);  //스택 추가
							if (head == NULL) {  //스택이 비어있었을경우
								head = tail;  //head 재지정
							}
							visited[visited_cnt] = mat[i][0];  //방문 정점 추가
							visited_cnt++;  //누적 방문 정점
							visited_cnt2++;  //현재 그룹 방문 정점
						}
					}
				}
			}
			score_focus = score_head;
			if (score_focus->nextnode == NULL) {  //처음 추가되는거면
				score_focus = AddNode(score_focus, visited_cnt2);  //바로 추가
			}
			else {
				while (score_focus->nextnode->data < visited_cnt2) {  //다음노드가 작을때까지
					score_focus = score_focus->nextnode;  //다음노드로 이동
					if (score_focus->nextnode == NULL) {  //끝이면 이동 중단
						break;
					}
				}
				score_focus = AddNode(score_focus, visited_cnt2);  //노드 추가
			}
		}

		//////////////////////////////////////////////////////////////////////////
		// 결과 출력
		//////////////////////////////////////////////////////////////////////////
		printf("%d\n", group_cnt);
		score_head = DeleteNode(score_head);  //더미 제거
		PrintNode(score_head);  //노드 출력

		//////////////////////////////////////////////////////////////////////////
		// 할당 해제
		//////////////////////////////////////////////////////////////////////////
		for (i = 0; i < m; i++) {
			free(mat[i]);
		}
		free(mat);
		free(visited);
		for (i = 0; i <= x; i++) {
			free(map[i]);
		}
		free(map);
	}
	return 0;
}
