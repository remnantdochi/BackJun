#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//    1 2 3 4 5 6 7 8 9 0
// 0  a b c d e f g h i j
// 1  k l m n o p q r s t
// 2  u v w x y z

///////////////////////////////////////
// 트리 노드
///////////////////////////////////////
struct Node {
	int data;  //데이터
	struct Node** tree;  //간선 26개
};

///////////////////////////////////////
// 트리 노드 생성
///////////////////////////////////////
struct Node* add_node() {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	int i;

	new_node->data = 0; //0 지나간 경로, 1 트리 끝, 2 일치하는 이름 
	new_node->tree = (struct Node**)malloc(sizeof(struct Node*) * 26);  //간선 26개 할당
	for (i = 0; i < 26; i++) {  //간선 기본적으로 없음으로 설정
		new_node->tree[i] = NULL;
	}

	return new_node;
}

///////////////////////////////////////
// 트리 노드 할당 해제
///////////////////////////////////////
void free_node(struct Node* node) {
	int i = 0;
	if (node != NULL) {
		for (i = 0; i < 26; i++) {
			if (node->tree[i] != NULL) {
				free_node(node->tree[i]);
			}
		}
		free(node);
	}
}

///////////////////////////////////////
// 트리 생성
///////////////////////////////////////
void make_tree(struct Node* node, char* name, int focus, int len) {
	int i;
	int branch;

	if (focus == len) {
		node->data = 1;
		//printf("\n");
	}
	else {
		branch = (int)name[focus] - 'a';
		if (node->tree[branch] == NULL) {
			node->tree[branch] = add_node();
		}
		//printf(" - %c", name[focus]);
		make_tree(node->tree[branch], name, focus + 1, len);
	}
}

///////////////////////////////////////
// 트리 탐색
///////////////////////////////////////
int search_tree(struct Node* node, char* name, int focus, int len) {
	int i;
	int branch;

	if (focus == len) {
		if (node->data == 1) {  // 이름이 같으면
			node->data = 2;  //데이터 변경
			return 1;
		}
		return 0;
	}
	else {
		if (node == NULL) {
			return 0;
		}
		branch = (int)name[focus] - 'a';
		if (node->tree[branch] == NULL) {
			return 0;
		}
		//printf(" - %c", name[focus]);
		return search_tree(node->tree[branch], name, focus + 1, len);
	}
}

///////////////////////////////////////
// 트리중 겹치는 이름 출력
///////////////////////////////////////
void print_tree(struct Node* node, char* name, int focus) {
	int i = 0;

	if (node != NULL) {
		if (node->data==2) {
			name[focus] = '\0';
			printf("%s\n", name);
		}
	}
	for (i = 0; i < 26; i++) {
		if (node->tree[i] != NULL) {
			name[focus] = (char)i + 'a';
			print_tree(node->tree[i], name, focus + 1);
		}
	}
}


int main() {
	int m, n;
	char name[21];
	char* name_ptr = name;
	struct Node* head;
	int i;
	int len;
	int cnt = 0;

	head = add_node();  //트리 시작점 생성
	scanf("%d %d", &n, &m);  //이름 갯수 입력
	for (i = 0; i < n; i++) {
		scanf("%s", name);
		len = strlen(name);
		make_tree(head, name_ptr, 0, len);  //이름 트리 생성
	}
	for (i = 0; i < m; i++) {
		scanf("%s", name);
		len = strlen(name);
		if (search_tree(head, name_ptr, 0, len)==1) {  //일치하는 이름 있으면
			cnt++;  //카운트
		}
	}
	printf("%d\n", cnt);
	print_tree(head, name_ptr, 0);  //겹치는 이름 출력
	free_node(head);  //할당 해제

	return 0;
}
