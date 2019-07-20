#include <stdio.h>
#include <stdlib.h>
void brutal(int* height, int* comb, int* end, int n) {
	int i;
	int cnt = 0;
	int total = 0;
	
	////////////////////////////////////////////////
	//  조합 완성
	////////////////////////////////////////////////
	if (n == 8) {
		for (i = 0; i < 9; i++) {
			if (comb[i] == 1) {
				cnt++;
				total += height[i];
			}
		}
		if (cnt == 7 && total == 100) {  //7명에 합이 100이면
			*end = 1;  //중단
		}
		return 0;
	}
	////////////////////////////////////////////////
	//  다음 조합 생성
	////////////////////////////////////////////////
	n++;
	if (*end == 1) {  //중단점 체크
		return 0;
	}
	comb[n] = 0;
	brutal(height, comb, end, n);
	if (*end == 1) {  //중단점 체크
		return 0;
	}
	comb[n] = 1;
	brutal(height, comb, end, n);

	return 0;
}

int main() {
	int* height = (int*)malloc(sizeof(int) * 9);
	int* comb = (int*)malloc(sizeof(int) * 9);
	int* end = (int*)malloc(sizeof(int));
	int i, j;
	int temp;

	////////////////////////////////////////////////
	//  변수 입력 및 초기화
	////////////////////////////////////////////////
	*end = 0;
	for (i = 0; i < 9; i++) {
		scanf("%d", &height[i]);
	}

	////////////////////////////////////////////////
	//  오름차순 정렬
	////////////////////////////////////////////////
	for (i = 0; i < 9; i++) {
		for (j = i + 1; j < 9; j++) {
			if (height[i] > height[j]) {
				temp = height[i];
				height[i] = height[j];
				height[j] = temp;
			}
		}
	}

	////////////////////////////////////////////////
	//  brutal 탐색 실행
	////////////////////////////////////////////////
	brutal(height, comb, end, -1);

	////////////////////////////////////////////////
	//  결과 출력
	////////////////////////////////////////////////
	for (i = 0; i < 9; i++) {
		if (comb[i] == 1) {
			printf("%d\n", height[i]);
		}
	}

	return 0;
}
