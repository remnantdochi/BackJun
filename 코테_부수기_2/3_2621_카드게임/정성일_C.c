#include <stdio.h>

int main() {
	char ch_temp;  //카드 색상 임시 입력
	int i_temp;  //카드 숫자 임시 입력
	int t_color[4];  //카드 색상 통계
	int t_num[10];  //카드 숫자 통계
	int i, j;  //for문 변수
	int max_num = 0;  //최고숫자
	int temp_score = 0;  //임시 점수
	int max_score = 0;  //최대점수
	
	//////////////////////////////////////
	// 변수 초기화
	//////////////////////////////////////
	for (i = 0; i < 4; i++) {
		t_color[i] = 0;
	}
	for (i = 0; i < 10; i++) {
		t_num[i] = 0;
	}

	//////////////////////////////////////
	// 카드 입력
	//////////////////////////////////////
	for (i = 0; i < 5; i++) {
		scanf(" %c", &ch_temp);
		scanf(" %d", &i_temp);

		if (ch_temp == 'R') {  // 색상별 분류
			t_color[0]++;
		}
		else if (ch_temp == 'B') {
			t_color[1]++;
		}
		else if (ch_temp == 'Y') {
			t_color[2]++;
		}
		else if (ch_temp == 'G') {
			t_color[3]++;
		}
		t_num[i_temp]++;  //숫자 카운팅
	}
	///////////////////////////////////////
	// 최대숫자 찾기
	///////////////////////////////////////
	for (i = 9; i > 0; i--) {
		if (t_num[i] != 0) {
			max_num = i;
			max_score = max_num + 100;
			break;
		}
	}

	////////////////////////////////////////
	// 점수 계산
	////////////////////////////////////////
	for (i = 0; i < 5; i++) {
		if (t_color[i] == 5) {  //같은 색 5장
			for (j = 9; j > 0; j--) {
				if (t_num[j] != 0) {
					temp_score = j + 600;
					if (temp_score > max_score) {
						max_score = temp_score;
					}
					break;
				}
			}
			for (j = 1; j < 6; j++) {
				if (t_num[j] == 1 && t_num[j+1] == 1 && t_num[j+2] == 1 && t_num[j+3] == 1 && t_num[j+4] == 1) {  //연속되는 숫자 5장
					temp_score = 900 + j + 4;
					if (temp_score > max_score) {
						max_score = temp_score;
					}
					break;
				}
			}
		}
	}

	for (j = 1; j < 6; j++) {
		if (t_num[j] == 1 && t_num[j + 1] == 1 && t_num[j + 2] == 1 && t_num[j + 3] == 1 && t_num[j + 4] == 1) {  //연속되는 숫자 5장
			temp_score = 500 + j + 4;
			if (temp_score > max_score) {
				max_score = temp_score;
			}
			break;
		}
	}

	for (i = 1; i < 10; i++) {
		if (t_num[i] == 4) {  //같은숫자 4장
			temp_score = 800 + i;
			if (temp_score > max_score) {
				max_score = temp_score;
			}
			break;
		}
	}

	for (i = 1; i < 10; i++) {
		if (t_num[i] == 3) {  //같은숫자 3장
			temp_score = 400 + i;
			if (temp_score > max_score) {
				max_score = temp_score;
			}
			for (j = 1; j < 10; j++) {
				if (t_num[j] == 2) {  //같은 숫자 2장
					temp_score = 700 + i * 10 + j;
					if (temp_score > max_score) {
						max_score = temp_score;
					}
					break;
				}
			}
			break;
		}
	}

	for (i = 1; i < 10; i++) {
		if (t_num[i] == 2) {  //같은 숫자 2장
			temp_score = 200 + i;
			if (temp_score > max_score) {
				max_score = temp_score;
			}
			for (j = i; j < 10; j++) {
				if (j != i && t_num[j] == 2) {  //같은 숫자 2장
					temp_score = 300 + j * 10 + i;
					if (temp_score > max_score) {
						max_score = temp_score;
					}
					break;
				}
			}
			break;
		}
	}

	printf("%d", max_score);  //최대점수 출력

	return 0;
}
