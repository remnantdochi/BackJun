#include <stdio.h>
#include <stdlib.h>

//함수설명 하단에
struct Node* AddNode(struct Node* current_Node, int data);
struct Node* CreateNode(int data);
struct Node* RemoveNode(struct Node* current_Node);

struct Node {  //노드(데이터+포인터)
	int data;
	struct Node* nextNode;
	struct Node* prevNode;
};

int main() {
	int n, k;  //사람 수, 건너뛰는 칸
	struct Node* current_Node;  //현재 노드 포인터
	int i, j;  //반복문용 변수

	scanf("%d %d", &n, &k);  //변수 입력

	for (i = 1; i <= n; i++) {  //사람 노드 생성
		if (i == 1) {
			current_Node = CreateNode(i);
		}
		else {
			current_Node = AddNode(current_Node, i);
		}
	}
	current_Node = current_Node->nextNode;

	printf("<");
	for (i = 1; i < n ; i++) {
		for (j = 1; j < k; j++) {
			current_Node = current_Node->nextNode;  //다음노드로 이동
		}
		printf("%d, ",current_Node->data);  //노드 출력및 제거
		current_Node=RemoveNode(current_Node);
	}
	printf("%d", current_Node->data);  //노드 출력
	printf(">");

	free(current_Node);  //노드 할당 해제

	return 0;
}

//////////////////////////////////////////////////
//  초기노드 생성
//////////////////////////////////////////////////
struct Node* CreateNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = data;  //데이터 저장
	newNode->nextNode = newNode;  //노드 연결
	newNode->prevNode = newNode;

	return newNode;  //포인터 반환
}

//////////////////////////////////////////////////
//  맨뒤에 노드 추가
//////////////////////////////////////////////////
struct Node* AddNode(struct Node* current_Node, int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = data;  //데이터 저장
	newNode->nextNode = current_Node->nextNode;  //노드연결 수정
	newNode->prevNode = current_Node;
	current_Node->nextNode = newNode;
	newNode->nextNode->prevNode = newNode;

	return newNode;  //새로운노드 주소 반환
}



struct Node* RemoveNode(struct Node* current_Node) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

	temp = current_Node->nextNode;
	current_Node->nextNode->prevNode = current_Node->prevNode;
	current_Node->prevNode->nextNode = current_Node->nextNode;
	free(current_Node);  //노드 할당 해제

	return temp;  //다음노드 주소 반환
}
