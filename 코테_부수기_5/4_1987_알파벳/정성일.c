#include <stdio.h>
#include <stdlib.h>
//    1 2 3 4 5 6 7 8 9 0
// 0  a b c d e f g h i j
// 1  k l m n o p q r s t
// 2  u v w x y z

void move(int** map, int alphabet[27], int x, int y, int m, int n, int* max, int cnt) {
	int j, k;
	int temp = 0;

	//////////////////////////////////////////////////
	//  상하좌우로 이동
	//////////////////////////////////////////////////
	for (j = -1; j < 2; j ++) {
		for (k = -1; k < 2; k ++) {
			if (j * k == 0 && j + k != 0) {
				if (0 <= x + j && x + j < m && 0 <= y + k && y + k < n) {  //범위 내에 있는지 확인
					if (alphabet[map[x + j][y + k]] == 0) {  //이미 지난 알파벳인지 확인
						//printf("%d %d\n", x + j, y + k);
						alphabet[map[x + j][y + k]] = 1;  //지남 표시
						move(map, alphabet, x + j, y + k, m, n, max, cnt + 1);  //이동
						alphabet[map[x + j][y + k]] = 0;  //원상복구
						temp++;
					}
				}
			}
		}
	}
	if (temp == 0) {  //이동 불가면
		if (*max < cnt) {  //최대값 갱신
			*max = cnt;
		}
	}

	return 0;
}

int main() {
	int m, n;
	int i, j;
	char ch_temp;
	int** map;
	int* max = (int*)malloc(sizeof(int));
	int alphabet[27];

	//////////////////////////////////////////////////
	//  변수 생성 및 초기화
	//////////////////////////////////////////////////
	*max = 0;
	for (i = 0; i <= 26; i++) {
		alphabet[i] = 0;
	}
	//////////////////////////////////////////////////
	//  변수 입력
	//////////////////////////////////////////////////
	scanf("%d %d", &m, &n);
	map = (int**)malloc(sizeof(int*) * m);  // 지도 할당
	for (i = 0; i < m; i++) {
		map[i] = (int*)malloc(sizeof(int) * n);
		for (j = 0; j < n; j++) {
			scanf(" %c", &ch_temp);  //매핑
			map[i][j] = (int)ch_temp - 'A' + 1;  //알파벳 순번으로 변환저장
		}
	}
	alphabet[map[0][0]] = 1;  //시작점 방문 표시
	move(map, alphabet, 0, 0, m, n, max, 1);  //탐색 시작

	//////////////////////////////////////////////////
	//  결과 출력
	//////////////////////////////////////////////////
	printf("%d", *max);

	//////////////////////////////////////////////////
	//  할당해제
	//////////////////////////////////////////////////
	free(max);
	for (i = 0; i < m; i++) {
		free(map[i]);
	}
	free(map);

	return 0;
}
