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
	else if(focus->nextnode==NULL) {
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

	return prev;
}

//////////////////////////////////////////////////////////////////////////
// 노드 출력 함수
//////////////////////////////////////////////////////////////////////////
struct Node* PrintNode(struct Node* focus) {

	if (focus == NULL) {
		printf("\n");
		return NULL;
	}
	printf("%d ", focus->data);

	return PrintNode(focus->nextnode);
}

//////////////////////////////////////////////////////////////////////////
int main() {
	struct Node* tail;
	struct Node* head;
	int n, m;
	int i, j;
	int temp1, temp2;
	int** mat;
	int* visited;
	int visited_cnt = 0;
	int group_cnt = 0;

	//////////////////////////////////////////////////////////////////////////
	// 인수 입력
	//////////////////////////////////////////////////////////////////////////
	scanf("%d %d", &n, &m);

	//////////////////////////////////////////////////////////////////////////
	// 간선 저장 공간 할당 및 초기화 (더블포인터 m*2 크기)
	//////////////////////////////////////////////////////////////////////////
	mat = (int**)malloc(sizeof(int*) * m);
	for (i = 0; i < m; i++) {
		mat[i] = (int*)malloc(sizeof(int) * 2);
		mat[i][0] = 0;
		mat[i][1] = 0;
	}

	//////////////////////////////////////////////////////////////////////////
	// 방문기록 행렬 할당 및 초기화 (n크기)
	//////////////////////////////////////////////////////////////////////////
	visited = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		visited[i] = 0;
	}

	//////////////////////////////////////////////////////////////////////////
	// 간선 저장
	//////////////////////////////////////////////////////////////////////////
	for (i = 0; i < m; i++) {
		scanf("%d %d", &mat[i][0], &mat[i][1]);
	}

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
			if (temp1==0) {  //방문한 적이 없으면
				head = AddNode(NULL, mat[i][0]);  //노드 생성
				tail = head;  //head tail 지정
				visited[visited_cnt] = mat[i][0];  //방문 정점 추가
				visited_cnt++;
				group_cnt++;  //그룹 1 증가
				break;
			}
		}
		//////////////////////////////////////////////////////////////////////////
		// 시작점 만들기 실패시 고립된 점이 존재
		//////////////////////////////////////////////////////////////////////////
		if (tail == NULL) {
			group_cnt += n - visited_cnt;
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
						visited_cnt++;
					}
				}
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	// 결과 출력
	//////////////////////////////////////////////////////////////////////////
	printf("%d", group_cnt);

	//////////////////////////////////////////////////////////////////////////
	// 할당 해제
	//////////////////////////////////////////////////////////////////////////
	for (i = 0; i < m; i++) {
		free(mat[i]);
	}
	free(mat);

	return 0;
}
