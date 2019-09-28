#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int m_num;
int** m_mat;
int m_min = -1;

int f_brute(int m_team[10], int focus);
int f_diff(int m_team[10]);

int f_brute(int m_team[10], int focus) {
	if (focus == 0) {
		int temp;
		temp = f_diff(m_team);
		//printf("%d\n", temp);
		if (temp < m_min || m_min == -1) {
			m_min = temp;
		}

		return 0;
	}

	int m_limit;
	if (focus == m_num / 2 - 1) {
		m_limit = m_num;
	}
	else {
		m_limit = m_team[focus + 1];
	}
	for (int i = focus; i < m_limit; i++) {
		//printf("%d %d\n",focus, i);
		m_team[focus] = i;
		f_brute(m_team, focus - 1);
	}

	return 0;
}

int f_diff(int m_team[10]) {
	int m_member[20];
	
	for (int i = 0; i < 20; i++) {
		m_member[i] = 0;
	}
	for (int i = 0; i < m_num/2; i++) {
		//printf("%d ", m_team[i]);
		m_member[m_team[i]] = 1;
	}
	//printf("\n");
	for (int i = 0; i < m_num; i++) {
		if (m_member[i] == 0) {
			m_member[i] = 2;
		}
	}

	int m_A = 0, m_B = 0;

	for (int i = 0; i < m_num; i++) {
		switch (m_member[i]) {
		case 1:
			for (int j = 0; j < m_num; j++) {
				if (m_member[j] == 1) {
					m_A += m_mat[i][j];
				}
			}
			break;
		case 2:
			for (int j = 0; j < m_num; j++) {
				if (m_member[j] == 2) {
					m_B += m_mat[i][j];
				}
			}
			break;
		}
	}


	return abs(m_A - m_B);
}

int main() {

	scanf("%d", &m_num);

	m_mat = (int**)malloc(sizeof(int*) * m_num);
	for (int i = 0; i < m_num; i++) {
		m_mat[i] = (int*)malloc(sizeof(int) * m_num);
		for (int j = 0; j < m_num; j++) {
			scanf(" %d", &m_mat[i][j]);
		}
	}

	int m_team[10];

	for (int i = 0; i < m_num / 2; i++) {
		m_team[i] = i;
	}
	for (int i = m_num / 2; i < 10; i++) {
		m_team[i] = 0;
	}

	f_brute(m_team, m_num / 2 - 1);
	printf("%d", m_min);

	for (int i = 0; i < m_num; i++) {
		free(m_mat[i]);
	}
	free(m_mat);

	return 0;
}
