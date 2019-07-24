#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//    1 2 3 4 5 6 7 8 9 0
// 0  a b c d e f g h i j
// 1  k l m n o p q r s t
// 2  u v w x y z

struct Node {
	int data;
	struct Node** tree;
};

struct Node* add_node() {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	int i;

	new_node->data = 0;
	new_node->tree = (struct Node**)malloc(sizeof(struct Node*) * 26);
	for (i = 0; i < 26; i++) {
		new_node->tree[i] = NULL;
	}

	return new_node;
}

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

int search_tree(struct Node* node, char* name, int focus, int len) {
	int i;
	int branch;

	if (focus == len) {
		if (node->data == 1) {
			node->data = 2;
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

	head = add_node();
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%s", name);
		len = strlen(name);
		make_tree(head, name_ptr, 0, len);
	}
	for (i = 0; i < m; i++) {
		scanf("%s", name);
		len = strlen(name);
		if (search_tree(head, name_ptr, 0, len)==1) {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	print_tree(head, name_ptr, 0);
	free_node(head);
	return 0;
}
