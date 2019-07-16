#include <stdio.h>

int main() {

	int ip;  //시작 숫자
	int m1[2], m2[2];  //숫자 분리
	int count;  //사이클 길이

	count = 0;
	scanf("%d", &ip);  //시작 숫자 입력

	m1[0] = ip / 10;  //숫자 분리
	m1[1] = ip % 10;

	while (1) {
		m2[0] = m1[1];  //규칙 시행
		m2[1] = (m1[0] + m1[1]) % 10;
		count++;  //횟수 +1
		if (10 * m2[0] + m2[1] == ip) {  //숫자가 돌아왔으면 루프 탈출
			break;
		}
		m1[0] = m2[0];
		m1[1] = m2[1];
	}

	printf("%d", count);  //규칙 시행 횟수 출력

	return 0;
}
