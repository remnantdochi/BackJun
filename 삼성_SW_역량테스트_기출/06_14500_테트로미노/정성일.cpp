#include <stdio.h>
#include <stdlib.h>

int main() {
	int m_size[2];
	int** m_map;
	int temp = 0, m_max = 0;

	scanf("%d %d", &m_size[0], &m_size[1]);
	m_map = (int**)malloc(sizeof(int*) * m_size[0]);
	for (int i = 0; i < m_size[0]; i++) {
		m_map[i] = (int*)malloc(sizeof(int) * m_size[1]);
		for (int j = 0; j < m_size[1]; j++) {
			scanf("%d", &m_map[i][j]);
		}
	}

	//가로 1자
	for (int i = 0; i + 3 < m_size[1]; i++) {
		for (int j = 0; j < m_size[0]; j++) {
			temp = m_map[j][i] + m_map[j][i+1] + m_map[j][i+2] + m_map[j][i+3];
			if (temp > m_max) {
				m_max = temp;
			}
		}
	}
	//세로 1자
	for (int i = 0; i + 3 < m_size[0]; i++) {
		for (int j = 0; j < m_size[1]; j++) {
			temp = m_map[i][j] + m_map[i + 1][j] + m_map[i + 2][j] + m_map[i + 3][j];
			if (temp > m_max) {
				m_max = temp;
			}
		}
	}
	// 00
	// 00
	for (int i = 0; i + 1 < m_size[0]; i++) {
		for (int j = 0; j + 1 < m_size[1]; j++) {
			temp = m_map[i][j] + m_map[i + 1][j] + m_map[i][j + 1] + m_map[i + 1][j + 1];
			if (temp > m_max) {
				m_max = temp;
			}
		}
	}

	// 00
	// 00
	// 00
	for (int i = 0; i + 2 < m_size[0]; i++) {
		for (int j = 0; j + 1 < m_size[1]; j++) {
			temp = m_map[i][j] + m_map[i + 1][j] + m_map[i + 2][j] + m_map[i][j + 1];
			if (temp > m_max) {
				m_max = temp;
			}
			temp = m_map[i][j] + m_map[i + 1][j] + m_map[i + 2][j] + m_map[i + 1][j + 1];
			if (temp > m_max) {
				m_max = temp;
			}
			temp = m_map[i][j] + m_map[i + 1][j] + m_map[i + 2][j] + m_map[i + 2][j + 1];
			if (temp > m_max) {
				m_max = temp;
			}
			temp = m_map[i][j] + m_map[i + 1][j] + m_map[i + 1][j + 1] + m_map[i + 2][j + 1];
			if (temp > m_max) {
				m_max = temp;
			}
			temp = m_map[i][j + 1] + m_map[i + 1][j + 1] + m_map[i + 1][j] + m_map[i + 2][j];
			if (temp > m_max) {
				m_max = temp;
			}
			temp = m_map[i][j + 1] + m_map[i + 1][j + 1] + m_map[i + 2][j + 1] + m_map[i][j];
			if (temp > m_max) {
				m_max = temp;
			}
			temp = m_map[i][j + 1] + m_map[i + 1][j + 1] + m_map[i + 2][j + 1] + m_map[i + 1][j];
			if (temp > m_max) {
				m_max = temp;
			}
			temp = m_map[i][j + 1] + m_map[i + 1][j + 1] + m_map[i + 2][j + 1] + m_map[i + 2][j];
			if (temp > m_max) {
				m_max = temp;
			}
		}
	}

	// 000
	// 000
	for (int i = 0; i + 1 < m_size[0]; i++) {
		for (int j = 0; j + 2 < m_size[1]; j++) {
			temp = m_map[i][j] + m_map[i][j + 1] + m_map[i][j + 2] + m_map[i + 1][j];
			if (temp > m_max) {
				m_max = temp;
			}
			temp = m_map[i][j] + m_map[i][j + 1] + m_map[i][j + 2] + m_map[i + 1][j + 1];
			if (temp > m_max) {
				m_max = temp;
			}
			temp = m_map[i][j] + m_map[i][j + 1] + m_map[i][j + 2] + m_map[i + 1][j + 2];
			if (temp > m_max) {
				m_max = temp;
			}
			temp = m_map[i + 1][j] + m_map[i + 1][j + 1] + m_map[i + 1][j + 2] + m_map[i][j];
			if (temp > m_max) {
				m_max = temp;
			}
			temp = m_map[i + 1][j] + m_map[i + 1][j + 1] + m_map[i + 1][j + 2] + m_map[i][j + 1];
			if (temp > m_max) {
				m_max = temp;
			}
			temp = m_map[i + 1][j] + m_map[i + 1][j + 1] + m_map[i + 1][j + 2] + m_map[i][j + 2];
			if (temp > m_max) {
				m_max = temp;
			}
			temp = m_map[i][j] + m_map[i][j + 1] + m_map[i + 1][j + 1] + m_map[i + 1][j + 2];
			if (temp > m_max) {
				m_max = temp;
			}
			temp = m_map[i + 1][j] + m_map[i + 1][j + 1] + m_map[i][j + 1] + m_map[i][j + 2];
			if (temp > m_max) {
				m_max = temp;
			}
		}
	}

	printf("%d", m_max);

	for (int i = 0; i < m_size[0]; i++) {
		free(m_map[i]);
	}
	free(m_map);

	return 0;
}
