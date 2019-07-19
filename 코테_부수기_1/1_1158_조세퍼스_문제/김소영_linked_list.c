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
/* 정성일 피드백
전역변수는 나중에 여러 스레드가 합쳐질때 간섭여지가 많아서
최대한 사용 지양

n,k,i,j는 main에 넣어도 문제 없고
list_size도 가감코드를 노드함수에서 호출전으로 옮기면 문제 없을거라 생각
	ex)
	list_size++;
	CreateNode(i);

------------------------------------------------------------------------------

최초 노드 생성시 조건문을 줄일 수 있음
cur=CreateNode(1);
for(i = 2; i <= n; i++){
	cur=AddNode(cur,i);
}

-----------------------------------------------------------------------------

(focus) - (focus+1) - (focus+2)
노드가 있다고 할때
deleteNode에서 (focus+1) 삭제후
(focus+2)가 아닌 (focus)를 반환하면
k=1까지 일반화가 가능

기존
focus->next->data      하면 (focus+1)출력
delete(focus)             하면 (focus+1)삭제후 (focus+2)반환
focus->data              해야 (focus+2)가 나옴

수정
focus->next->data      하면 (focus+1)출력
delete(focus)             하면 (focus+1)삭제후 (focus)반환
focus->next->data      하면 (focus+2)가 나옴

즉 코드를

//cur을 tail에 남겨두고
//cur = cur->next; 삭제
while (list_size > 1) {
	for(j=1;j<k;j++){                            //k가 1일때는 실행 안 함
		cur = cur -> next;
	}
	printf("%d ,", cur -> next -> data);
	list_size--;                                   //deleteNode에서 빼옴
	cur = deleteNode(cur);
}
로 수정 가능
-----------------------------------------------------------------------------
*/
