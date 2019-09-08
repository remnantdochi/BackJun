#include <stdio.h>
#include <stdlib.h>
int** m_map;
int m_size[2];
int cnt_2;

int erosion(int x, int y) {
	//printf("%d\n", cnt_2);
	if (x > 0) {
		if (m_map[x - 1][y] == 0) {
			m_map[x - 1][y] = -2;
			cnt_2++;
			erosion(x - 1, y);
		}
	}
	if (y > 0) {
		if (m_map[x][y - 1] == 0) {
			m_map[x][y - 1] = -2;
			cnt_2++;
			erosion(x, y - 1);
		}
	}
	if (x + 1 < m_size[0]) {
		if (m_map[x + 1][y] == 0) {
			m_map[x + 1][y] = -2;
			cnt_2++;
			erosion(x + 1, y);
		}
	}
	if (y + 1 < m_size[1]) {
		if (m_map[x][y + 1] == 0) {
			m_map[x][y + 1] = -2;
			cnt_2++;
			erosion(x, y + 1);
		}
	}

	return 0;
}

int main() {
	int m_max = 0;
	int m_wall[3][2];
	int cnt_0 = 0;

	scanf("%d %d", &m_size[0], &m_size[1]);
	m_map = (int**)malloc(sizeof(int*) * m_size[0]);
	for (int i = 0; i < m_size[0]; i++) {
		m_map[i] = (int*)malloc(sizeof(int) * m_size[1]);
		for (int j = 0; j < m_size[1]; j++) {
			scanf("%d", &m_map[i][j]);
			if (m_map[i][j] == 0) {
				cnt_0++;
			}
		}
	}

	for (int i = 0; i < m_size[0] * m_size[1]; i++) {
		m_wall[0][0] = i / m_size[1];
		m_wall[0][1] = i % m_size[1];
		if (m_map[m_wall[0][0]][m_wall[0][1]] == 0) {
			for (int j = i + 1; j < m_size[0] * m_size[1]; j++) {
				m_wall[1][0] = j / m_size[1];
				m_wall[1][1] = j % m_size[1];
				if (m_map[m_wall[1][0]][m_wall[1][1]] == 0) {
					for (int k = j + 1; k < m_size[0] * m_size[1]; k++) {
						m_wall[2][0] = k / m_size[1];
						m_wall[2][1] = k % m_size[1];
						if (m_map[m_wall[2][0]][m_wall[2][1]] == 0) {
							//printf("1: %d,%d 2: %d,%d 3: %d,%d\n", m_wall[0][0], m_wall[0][1], m_wall[1][0], m_wall[1][1], m_wall[2][0], m_wall[2][1]);
							m_map[m_wall[0][0]][m_wall[0][1]] = -1;
							m_map[m_wall[1][0]][m_wall[1][1]] = -1;
							m_map[m_wall[2][0]][m_wall[2][1]] = -1;
							cnt_2 = 0;
							for (int l = 0; l < m_size[0]; l++) {
								for (int m = 0; m < m_size[1]; m++) {
									if (m_map[l][m] == 2) {
										erosion(l, m);
									}
								}
							}
							if (m_max < cnt_0 - cnt_2 - 3) {
								m_max = cnt_0 - cnt_2 - 3;
							}
							for (int l = 0; l < m_size[0]; l++) {
								for (int m = 0; m < m_size[1]; m++) {
									if (m_map[l][m] < 0) {
										m_map[l][m] = 0;
									}
								}
							}
						}
					}
				}
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
