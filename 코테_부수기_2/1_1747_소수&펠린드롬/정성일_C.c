#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	int m_start;  //시작점 변수
	int d_prime;  //소수 판별 변수
	int d_pen;  //팰린드롬 판별 변수  
	int i;  //for문 변수
	char m_pen[15] = "";  //팰린드롬 문자열
	int m_strlen = 0;  //문자열 크기

	scanf("%d", &m_start);  //시작점 입력;

	while (1) {
		if (m_start == 1) {  //1은 소수가 아니므로 2 출력
			printf("2\n");
			break;
		}

		sprintf(m_pen, "%d", m_start);  //m_start를 문자열로 변환
		m_strlen = strlen(m_pen);  //문자열 크기 저장

		d_pen = 1;
		d_prime = 1;  //판별 변수 초기화

		////////////////////////////////////////////////////////////////////////////////
		// 팰린드롬 판별
		////////////////////////////////////////////////////////////////////////////////
		for (i = 0; i <= m_strlen/2; i++) {
			if (m_pen[i] != m_pen[m_strlen - i - 1]) {
				d_pen = 0;
				break;
			}
		}

		////////////////////////////////////////////////////////////////////////////////
		//  소수 판별
		////////////////////////////////////////////////////////////////////////////////
		if (d_pen) {  //팰린드롬이면
			for (i = 2; i <= (m_start / 2); i++) {  //m_start 절반까지 나눠서 소수인지 검증
				if (m_start % i == 0) {
					d_prime = 0;
					break;
				}
			}
			if (d_prime) {  //소수이면 출력
				printf("%d\n", m_start);
				break;
			}
		}
		m_start++;  //m_start 1 늘림
	}

	return 0;
}
