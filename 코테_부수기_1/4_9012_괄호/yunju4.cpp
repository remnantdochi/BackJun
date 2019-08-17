#include <iostream>
#include <algorithm>
#include <list>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int match(void);

int main() {
	int c;
	scanf("%d", &c);
	int result[10000];
	for (int i = 0; i < c; i++) {
		result[i] = match();
	}
	for (int i = 0; i < c; i++) {
		if (result[i] == 1) printf("YES\n");
		else printf("NO\n");
	}
}
int match(void) {
	char bracket[10000];
	scanf("%s", bracket);
	int number[3] = { 0, };// 열린괄호 카운트
	int length = strlen(bracket);
	for (int j = 0; j < length; j++) {
		int k = 0;
		if (bracket[j] == '{') {
			number[0]++;
		}
		else if (bracket[j] == '[') number[1]++;
		else if (bracket[j] == '(') {
			number[2]++;
		}
		else if (bracket[j] == '}') {
			if (number[0] == 0) return 0;
			while (bracket[j - k - 1] == 0) {
				k++;
				if (j - k - 1 < 0) return 0;
			}
			if (bracket[j - k - 1] == '{') {
				bracket[j - k - 1] = 0;
				bracket[j] = 0;
				number[0]--;
			}
			else return 0;
		}
		else if (bracket[j] == ']') {
			if (number[1] == 0) return 0;
			while (bracket[j - k - 1] == 0) {
				k++;
				if (j - k - 1 < 0) return 0;
			}
			if (bracket[j - k - 1] == '[') {
				bracket[j - k - 1] = 0;
				bracket[j] = 0;
				number[1]--;
			}
			else return 0;
		}
		else if (bracket[j] == ')') {
			if (number[2] == 0) {
				return 0;

			}
			while (bracket[j - k - 1] == 0) {
				k++;
				if (j - k - 1 < 0) return 0;
			}
			if (bracket[j - k - 1] == '(') {
				bracket[j - k - 1] = 0;
				bracket[j] = 0;
				number[2]--;
			}
			else return 0;
		}
	}
	if ((number[0] == 0) && (number[1] == 0) && (number[2] == 0)) return 1;
	else return 0;
}




