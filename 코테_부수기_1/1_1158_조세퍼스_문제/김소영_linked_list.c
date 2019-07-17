#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

//성일 오빠꺼 조금 바꿔보았습니당 ㅎ..
//prev 지움

int n, k;  //사람 수 N, 건너뛰는 칸 K
int i, j;
int list_size = 0;

typedef struct Node {    // 연결 리스트의 노드 구조체
	int data;// 데이터를 저장할 멤버
	struct Node *next;    // 다음 노드의 주소를 저장할 포인터
	             
}NODE;

NODE* CreateNode(int newData) {
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = newData;
	newNode->next = newNode;

	list_size++;

	return newNode;
}

NODE* AddNode(NODE* cur,int newData) {
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = newData;
	newNode->next = cur->next;
	cur->next = newNode;

	list_size++;

	return newNode;
}

NODE* deleteNode(NODE* prev_cur) {


	NODE* deleteNode = prev_cur->next;
	prev_cur->next = deleteNode->next;
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp = prev_cur->next;

	free(deleteNode);

	list_size--;

	return temp;
}



int main() {
	
	NODE* cur;

	scanf("%d %d", &n, &k);  //변수 입력

	
	for (i = 1; i <= n; i++) {
		if (i == 1) {
			cur = CreateNode(1);
		}
		else {
			cur = AddNode(cur, i);
		}
	}
	cur = cur->next; //head
	

	printf("<");
	while (list_size > 1) {
		if (k == 1) {
			printf("%d, ", cur->data);
			cur = cur->next;
			list_size--;
		}
		else {
			for (j = 1; j < k-1; j++) {
				cur = cur->next;
			}//k-1만큼 이동
			printf("%d, ", cur->next->data);
			cur = deleteNode(cur);
		}
	}

	printf("%d", cur->data);

	printf(">");

	free(cur);

}
