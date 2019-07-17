#include <stdio.h>
#include <stdlib.h>

//함수설명 하단에
struct Node* pushNode(struct Node* tail, int data);
struct Node* CreateNode(int data);
struct Node* BacktoNode(struct Node* head, struct Node* tail);
int PopNode(struct Node* head);

struct Node {  //노드(데이터+포인터)
	int data;
	struct Node* nextNode;
};

int main() {
	int n, k;  //사람 수, 건너뛰는 칸
	struct Node* que_head;  //헤드 노드 포인터
	struct Node* que_tail;  //맨끝노드(테일노드) 포인터
	int i, j;  //반복문용 변수

	scanf("%d %d", &n, &k);  //변수 입력
	que_head = CreateNode(0);  //헤드노드 생성
	que_tail = que_head;  //테일노드 지정

	for (i = 1; i <= n; i++) {  //사람 노드 생성
		que_tail=pushNode(que_tail, i);
	}

	printf("<");
	for (i = 0; i < n-1; i++) {
		for (j = 1; j < k; j++) {
			que_tail = BacktoNode(que_head, que_tail);  //첫노드를 맨 뒤로
		}
		printf("%d, ", PopNode(que_head));  //첫노드 출력및 제거
	}
	printf("%d", PopNode(que_head));  //첫노드 출력 및 제거
	printf(">");

	free(que_head);  //헤드노드 할당 해제

	return 0;
}

//////////////////////////////////////////////////
//  헤드노드 생성
//////////////////////////////////////////////////
struct Node* CreateNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = data;  //헤드이므로 데이터는 상관 없음
	newNode->nextNode = NULL;  //초기에 연결되어있는 노드 없음

	return newNode;  //포인터 반환
}

//////////////////////////////////////////////////
//  맨뒤에 노드 추가
//////////////////////////////////////////////////
struct Node* pushNode(struct Node* tail, int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	
	newNode->data = data;
	newNode->nextNode = NULL;  //추가 할 노드 생성
	tail->nextNode = newNode;  //테일노드뒤에 새노드가 옴

	return newNode;  //새로운 테일노드 포인터 반환
}

//////////////////////////////////////////////////
//  첫 노드를 맨 뒤로 순서변경
//////////////////////////////////////////////////
struct Node* BacktoNode(struct Node* head, struct Node* tail) {
	struct Node* firstNode = head->nextNode;  //첫노드 포인터 저장
	struct Node* secondNode = head->nextNode->nextNode;  //두번째노드 포인터 저장

	tail->nextNode = firstNode;  //첫노드가 테일노드 뒤로 감
	firstNode->nextNode = NULL;  //첫노드가 맨뒤로가서 NULL포인터를 가짐
	head->nextNode = secondNode;  //두번째노드가 헤드노드 다음에 따라옴

	return firstNode;  //새로운 테일노드 포인터 반환
}

//////////////////////////////////////////////////
//  첫 노드 데이터 반환 및 할당해제
//////////////////////////////////////////////////
int PopNode(struct Node* head) {
	int temp = head->nextNode->data;  //첫노드 데이터 저장
	struct Node* secondNode = head->nextNode->nextNode;  //두번째노드 포인터 저장

	free(head->nextNode);  //첫노드 할당해제
	head->nextNode = secondNode;  //두번째노드를 헤드노드 뒤로

	return temp;  //첫노드 데이터 반환
}
