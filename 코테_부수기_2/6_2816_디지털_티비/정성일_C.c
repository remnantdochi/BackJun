#include <stdio.h>
#include <string.h>

int main() {
	int n;  //채널 갯수
	int i;  //for문용 변수
	int m_1, m_2;  //KBS1, KBS2 위치
	char temp[11];  //채널이름 임시저장

	scanf("%d", &n);  //채널 갯수 입력

	for (i = 0; i < n; i++) {
		scanf("%s", temp);  //채널 입력
		if (strcmp(temp, "KBS1")==0) {  //KBS1 위치 저장
			m_1 = i;
		}
		if (strcmp(temp, "KBS2") == 0) {  //KBS2 위치 저장
			m_2 = i;
		}
	}

	for (i = 0; i < m_1; i++) {  //KBS1 위치로 이동
		printf("1");
	}
	for (i = 0; i < m_1; i++) {  //KBS1 맨위로 변경
		printf("4");
	}
	for (i = 0; i < m_2; i++) {  //KBS2 위치로 이동
		printf("1");
	}
	if (m_2 < m_1) {  //KBS1이 밑에 있었으면 KBS2의 위치가 한칸 내려갔으므로
		printf("14"); //추가적으로 1칸 밑으로 이동, 위로 변경
	}
	for (i = 0; i < m_2-1; i++) {  //KBS2 두번째로 변경
		printf("4");
	}

	return 0;
}
