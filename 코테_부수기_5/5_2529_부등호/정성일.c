#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void permut(int* rule, int k, int focus, int list[10], int* min, int* max) {
	int i, j;
	int temp;
	int satis = 1;

	////////////////////////////////////////////////////////
	// k+1개 순열 만들었으면
	////////////////////////////////////////////////////////
	if (focus == k + 1) {  //k+1개 순열 만들었으면
		for (i = 0; i < k; i++) {
			if (rule[i] == 0 && list[i]>list[i+1]) {  //규칙 검사
				satis = 0;
				break;
			}
			if (rule[i] == 1 && list[i] < list[i + 1]) {
				satis = 0;
				break;
			}
		}
		if (satis) {  //규칙 틀린거 없으면
			for (i = 0; i <= k; i++) {  //최대순열과 비교
				if (max[i] > list[i]) {  //최대 순열보다 작으면
					break;  //비교 종료
				}
				else if (max[i] < list[i]) {  //최대 순열보다 크면
					for (j = 0; j <= k; j++) {  //갱신
						max[j] = list[j];
					}
					break;  //비교 종료
				}
			}
			for (i = 0; i <= k; i++) {  //최소 순열과 비교
				if (min[i] < list[i]) {  //최소 순열보다 크면
					break;  //비교 종료
				}
				else if (min[i] > list[i]) {  //최소 순열보다 작으면
					for (j = 0; j <= k; j++) {  //갱신
						min[j] = list[j];
					}
					break;  //비교 종료
				}
			}
		}
		return 0;
	}

	////////////////////////////////////////////////////////
	// focus위치의 숫자 변경
	////////////////////////////////////////////////////////
	for (i = focus; i < 10; i++) {  //focus부터 끝가지 있는 수들
		temp = list[i];  //바꾸기
		list[i] = list[focus];
		list[focus] = temp;
		permut(rule, k, focus + 1, list, min, max);  //다음단계
		temp = list[i];  //원상복귀
		list[i] = list[focus];
		list[focus] = temp;
	}

	return 0;
}

int main() {
	int k;
	int i, j;
	int* rule;
	int* min;
	int* max;
	char ch_temp;
	int list[10];

	////////////////////////////////////////////////////////
	// 순열 생성
	////////////////////////////////////////////////////////
	for (i = 0; i < 10; i++) {
		list[i] = i;
	}

	////////////////////////////////////////////////////////
	// 부등호 갯수 입력
	////////////////////////////////////////////////////////
	scanf("%d", &k);

	////////////////////////////////////////////////////////
	// 변수 할당
	////////////////////////////////////////////////////////
	rule = (int*)malloc(sizeof(int) * k);  // 부등호 정보
	min = (int*)malloc(sizeof(int) * (k + 1));  // 최소 순열
	max = (int*)malloc(sizeof(int) * (k + 1));  // 최대 순열
	for (i = 0; i <= k; i++) {  //최대최소값 초기화
		min[i] = 9;
		max[i] = 0;
	}

	////////////////////////////////////////////////////////
	// 부등호 입력
	////////////////////////////////////////////////////////
	for (i = 0; i < k; i++) {
		scanf(" %c", &ch_temp);
		if (ch_temp == '<') {
			rule[i] = 0;
		}
		else if (ch_temp == '>') {
			rule[i] = 1;
		}
	}
	
	////////////////////////////////////////////////////////
	// 순열 탐색
	////////////////////////////////////////////////////////
	permut(rule, k, 0, list, min, max);

	////////////////////////////////////////////////////////
	// 결과 출력
	////////////////////////////////////////////////////////
	for (i = 0; i <= k; i++) {
		printf("%d", max[i]);
	}
	printf("\n");
	for (i = 0; i <= k; i++) {
		printf("%d", min[i]);
	}

	return 0;
}
