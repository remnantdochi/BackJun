#include <stdio.h>

int main() {
	int n;  //국가 갯수
	int m_target;  //궁금한 국가
	int m_medal[1000][4] = { .0 };  //국가 메달 데이터
	int m_rank[1000] = { .0 };  //순위
	int m_temp[4] = { .0 };  //값 교환용 임시 변수
	int i, j, k;  //for문용 변수

	scanf("%d %d", &n, &m_target);  //국가수 및 궁금한 국가 입력

	for (i = 0; i < n; i++) {  //메달정보 입력
		scanf("%d %d %d %d", &m_medal[i][0], &m_medal[i][1], &m_medal[i][2], &m_medal[i][3]);
	}

	/////////////////////////////////////////////////////////////
	//  선택정렬로 줄 세우기
	/////////////////////////////////////////////////////////////
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (m_medal[i][1] < m_medal[j][1]) {
				for (k = 0; k < 4; k++) {
					m_temp[k] = m_medal[i][k];
					m_medal[i][k] = m_medal[j][k];
					m_medal[j][k] = m_temp[k];
				}
			}
			else if (m_medal[i][1] == m_medal[j][1]) {
				if (m_medal[i][2] < m_medal[j][2]) {
					for (k = 0; k < 4; k++) {
						m_temp[k] = m_medal[i][k];
						m_medal[i][k] = m_medal[j][k];
						m_medal[j][k] = m_temp[k];
					}
				}
				else if (m_medal[i][2] == m_medal[j][2]) {
					if (m_medal[i][3] < m_medal[j][3]) {
						for (k = 0; k < 4; k++) {
							m_temp[k] = m_medal[i][k];
							m_medal[i][k] = m_medal[j][k];
							m_medal[j][k] = m_temp[k];
						}
					}
				}
			}
		}
	}
	///////////////////////////////////////////////////////////////
	// 랭킹지정 및 동점국가 탐색
	///////////////////////////////////////////////////////////////
	for (i = 0; i < n; i++) {
		m_rank[i] = i + 1;  //정렬순서를 순위로 지정
		if (m_medal[i][1] == m_medal[i - 1][1]) {  //앞 국가와 매달이 같으면
			if (m_medal[i][2] == m_medal[i - 1][2]) {
				if (m_medal[i][3] == m_medal[i - 1][3]) {
					m_rank[i] = m_rank[i - 1];  //앞 국가와 같은 순위 지정
				}
			}
		}
	}

	for (i = 0; i < n; i++) {
		if (m_medal[i][0] == m_target) {  //궁금한 국가를 찾아 출력
			printf("%d", m_rank[i]);
			break;
		}
	}

	return 0;
}
