#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/////////////////////////////////////////
// 순서 섞기
/////////////////////////////////////////
void shuffle(int* list, int focus, int n, int* max) {
	int i;
	int temp;

	/////////////////////////////////////////
	// focus가 끝에 가면
	/////////////////////////////////////////
	if (focus + 1 == n) {
		temp = 0;
		for (i = 0; i < n - 1; i++) {
			temp += abs(list[i] - list[i + 1]);
		}
		if (temp > * max) {
			*max = temp;
		}
		return 0;
	}

	/////////////////////////////////////////
	// focus위치에 뒤에있는 숫자들 한번씩 넣어봄
	/////////////////////////////////////////
	for (i = focus; i < n ; i++) {
		temp = list[focus];
		list[focus] = list[i];
		list[i] = temp;
		shuffle(list, focus + 1, n, max);
		temp = list[focus];
		list[focus] = list[i];
		list[i] = temp;
	}

	return 0;
}

int main() {
	int* list;
	int* max;
	int n;
	int i;

	/////////////////////////////////////////
	// 최대값 변수 할당
	/////////////////////////////////////////
	max = (int*)malloc(sizeof(int));
	*max = 0;

	/////////////////////////////////////////
	// 변수 할당 및 입력
	/////////////////////////////////////////
	scanf("%d", &n);
	list = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}

	/////////////////////////////////////////
	// 셔플
	/////////////////////////////////////////
	shuffle(list, 0, n, max);

	/////////////////////////////////////////
	// 결과 출력
	/////////////////////////////////////////
	printf("%d", *max);

	/////////////////////////////////////////
	// 할당 해제
	/////////////////////////////////////////
	free(list);
	free(max);

	return 0;
}
