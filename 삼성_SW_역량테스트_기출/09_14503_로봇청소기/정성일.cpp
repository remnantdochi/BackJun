#include <stdio.h>
#include <stdlib.h>

struct s_pos {
	int x;
	int y;
	int d;
};

int main() {
	struct s_pos m_pos;
	int m_size[2];

	scanf("%d %d", &m_size[0], &m_size[1]);
	scanf("%d %d %d", &m_pos.x, &m_pos.y, &m_pos.d);
	m_pos.x++;
	m_pos.y++;

	int** m_map = (int**)malloc(sizeof(int*) * (2 + m_size[0]));
	for (int i = 0; i < m_size[0] + 2; i++) {
		m_map[i] = (int*)malloc(sizeof(int) * (2 + m_size[1]));
		for (int j = 0; j < m_size[1] + 2; j++) {
			if (i == 0 || j == 0 || i == m_size[0] + 1 || j == m_size[1] + 1) {
				m_map[i][j] = 1;
			}
			else {
				scanf("%d", &m_map[i][j]);
			}
		}
	}

	int m_cnt = 0;
	while (1) {
		//printf("%d %d %d\n", m_pos.x, m_pos.y, m_pos.d);
		if (m_map[m_pos.x][m_pos.y] == 0) {
			m_cnt++;
			m_map[m_pos.x][m_pos.y] = -1;
		}
		int m_d = m_pos.d + 4;
		int m_done = 0;
		for (int i = 1; i <= 4; i++) {
			switch ((m_d - i) % 4) {
			case 0:
				if (m_map[m_pos.x - 1][m_pos.y] == 0) {
					m_pos.x = m_pos.x - 1;
					m_pos.d = 0;
					m_done = 1;
				}
				break;
			case 1:
				if (m_map[m_pos.x][m_pos.y + 1] == 0) {
					m_pos.y = m_pos.y + 1;
					m_pos.d = 1;
					m_done = 1;
				}
				break;
			case 2:
				if (m_map[m_pos.x + 1][m_pos.y] == 0) {
					m_pos.x = m_pos.x + 1;
					m_pos.d = 2;
					m_done = 1;
				}
				break;
			case 3:
				if (m_map[m_pos.x][m_pos.y - 1] == 0) {
					m_pos.y = m_pos.y - 1;
					m_pos.d = 3;
					m_done = 1;
				}
				break;
			}
			if (m_done) {
				break;
			}
		}
		if (m_done == 0) {
			switch (m_pos.d) {
			case 0:
				if (m_map[m_pos.x + 1][m_pos.y] <= 0) {
					m_pos.x = m_pos.x + 1;
				}
				else if (m_map[m_pos.x + 1][m_pos.y] == 1) {
					m_done = 2;
				}
				break;
			case 1:
				if (m_map[m_pos.x][m_pos.y - 1] <= 0) {
					m_pos.y = m_pos.y - 1;
				}
				else if (m_map[m_pos.x][m_pos.y - 1] == 1) {
					m_done = 2;;
				}
				break;
			case 2:
				if (m_map[m_pos.x - 1][m_pos.y] <= 0) {
					m_pos.x = m_pos.x - 1;
				}
				else if (m_map[m_pos.x - 1][m_pos.y] == 1) {
					m_done = 2;;
				}
				break;
			case 3:
				if (m_map[m_pos.x][m_pos.y + 1] <= 0) {
					m_pos.y = m_pos.y + 1;
				}
				else if (m_map[m_pos.x][m_pos.y + 1] == 1) {
					m_done = 2;;
				}
				break;
			}
		}
		if (m_done == 2) {
			break;
		}
	}

	printf("%d", m_cnt);

	for (int i = 0; i < m_size[0]; i++) {
		free(m_map[i]);
	}
	free(m_map);

	return 0;
}
