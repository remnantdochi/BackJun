#include <stdio.h>
#include <string.h>

int main() {
	int m_test = 0;  //테스트 횟수
	int sum = 0;  //괄호가 열리면 +1 닫히면 -1
	int below_0 = 0;  //sum이 음수가 되는거 체크
	int i;  //for문용 변수
	char ch_test[51];
	int m_size = 0;  //문자열 크기 변수

	scanf("%d", &m_test);  //테스트 횟수 입력

	for (1; m_test != 0; m_test--) {  //테스트 반복
		sum = 0;  //초기화
		below_0 = 0;
		for (i = 0; i < 51; i++) {
			ch_test[i] = ' ';
		}

		scanf("%s", ch_test);  //문자열 입력
		m_size = strlen(ch_test);  //문자열 크기 저장

		for (i = 0; i < m_size; i++) {
			if (ch_test[i] == '(') {  // '('일떄 +1
				sum++;
			}
			else if (ch_test[i] == ')') {  // '('일때 -1
				sum--;
			}

			if (sum < 0) {
				below_0 = 1;
			}
		}

		if (sum == 0 && below_0 == 0) {  //sum 이 음수였던적 없고 0이면 VPS
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}


	return 0;
}
