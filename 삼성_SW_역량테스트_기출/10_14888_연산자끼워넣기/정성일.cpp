#include <stdio.h>
#include <stdlib.h>

int* m_ip;
int m_max = -1;
int m_min = -1;
int m_num;

int f_brute(int m_order[10], int focus) {
	int temp[10];

	if (focus == m_num - 1) {
		int m_res=m_ip[0];
		for (int i = 0; i < m_num - 1; i++) {
			//printf("%d ", m_order[i]);
			switch (m_order[i]) {
			case 1:
				m_res = m_res + m_ip[i + 1];
				break;
			case 2:
				m_res = m_res - m_ip[i + 1];
				break;
			case 3:
				m_res = m_res * m_ip[i + 1];
				break;
			case 4:
				m_res = m_res / m_ip[i + 1];
				break;
			}
		}
		if (m_max == -1 || m_max < m_res) {
			m_max = m_res;
		}
		if (m_min == -1 || m_min > m_res) {
			m_min = m_res;
		}
		//printf(" / %d\n", m_res);
		return 0;
	}

	for (int i = 0; i < 10; i++) {
		temp[i] = m_order[i];
	}
	for (int i = focus + 1; i < m_num - 1; i++) {
		if (m_order[focus] != m_order[i]) {
			temp[focus] = m_order[i];
			temp[i] = m_order[focus];
			f_brute(temp, focus + 1);
			temp[i] = m_order[i];
			temp[focus] = m_order[focus];
		}
	}
	f_brute(m_order, focus + 1);

	return 0;
}


int main() {
	int m_cnt_oper[4];

	scanf("%d", &m_num);

	m_ip = (int*)malloc(sizeof(int) * m_num);
	for (int i = 0; i < m_num; i++) {
		scanf("%d", &m_ip[i]);
	}

	for (int i = 0; i < 4; i++) {
		scanf("%d", &m_cnt_oper[i]);
	}

	int m_order[10];
	int j = 0;
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < m_cnt_oper[i]; k++) {
			m_order[j] = i + 1;
			j++;
		}
	}
	while (j < 10) {
		m_order[j] = 0;
		j++;
	}
	/*for (int i = 0; i < 10; i++) {
		printf("%d ", m_order[i]);
	}
	printf("\n");
	*/
	f_brute(m_order, 0);

	printf("%d\n%d", m_max, m_min);

	free(m_ip);

	return 0;
}
