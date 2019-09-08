#include <stdio.h>
#include <stdlib.h>


int main() {
	int m_pos[2];
	int m_size[2];
	int m_num;
	int m_dice[4][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
	/*
	    북
	 서 하 동
	    남
	    상
	 */

	scanf("%d %d %d %d %d", &m_size[0], &m_size[1], &m_pos[0], &m_pos[1], &m_num);

	int** map = (int**)malloc(sizeof(int*)*m_size[0]);
	for (int i = 0; i < m_size[0]; i++) {
		map[i] = (int*)malloc(sizeof(int) * m_size[1]);
		for (int j = 0; j < m_size[1]; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int* m_cmd = (int*)malloc(sizeof(int) * m_num);
	for (int i = 0; i < m_num; i++) {
		scanf("%d", &m_cmd[i]);
	}

	for (int i = 0; i < m_num; i++) {
		//printf("%d %d : ", i, m_cmd[i]);
		switch (m_cmd[i]) {
		case 1://동
			if (m_pos[1] + 1 < m_size[1]) {
				m_pos[1] += 1;
				int temp = m_dice[1][0];
				m_dice[1][0] = m_dice[1][1];
				m_dice[1][1] = m_dice[1][2];
				m_dice[1][2] = m_dice[3][1];
				m_dice[3][1] = temp;
				printf("%d\n", m_dice[3][1]);
				if (map[m_pos[0]][m_pos[1]] == 0) {
					map[m_pos[0]][m_pos[1]] = m_dice[1][1];
				}
				else {
					m_dice[1][1] = map[m_pos[0]][m_pos[1]];
					map[m_pos[0]][m_pos[1]] = 0;
				}
			}
			break;

		case 2://서
			if (m_pos[1] - 1 >= 0) {
				m_pos[1] -= 1;
				int temp = m_dice[1][2];
				m_dice[1][2] = m_dice[1][1];
				m_dice[1][1] = m_dice[1][0];
				m_dice[1][0] = m_dice[3][1];
				m_dice[3][1] = temp;
				printf("%d\n", m_dice[3][1]);
				if (map[m_pos[0]][m_pos[1]] == 0) {
					map[m_pos[0]][m_pos[1]] = m_dice[1][1];
				}
				else {
					m_dice[1][1] = map[m_pos[0]][m_pos[1]];
					map[m_pos[0]][m_pos[1]] = 0;
				}
			}
			break;

		case 3://북
			if (m_pos[0] - 1 >= 0) {
				m_pos[0] -= 1;
				int temp = m_dice[3][1];
				m_dice[3][1] = m_dice[2][1];
				m_dice[2][1] = m_dice[1][1];
				m_dice[1][1] = m_dice[0][1];
				m_dice[0][1] = temp;
				printf("%d\n", m_dice[3][1]);
				if (map[m_pos[0]][m_pos[1]] == 0) {
					map[m_pos[0]][m_pos[1]] = m_dice[1][1];
				}
				else {
					m_dice[1][1] = map[m_pos[0]][m_pos[1]];
					map[m_pos[0]][m_pos[1]] = 0;
				}
			}
			break;

		case 4://남
			if (m_pos[0] + 1 < m_size[0]) {
				m_pos[0] += 1;
				int temp = m_dice[0][1];
				m_dice[0][1] = m_dice[1][1];
				m_dice[1][1] = m_dice[2][1];
				m_dice[2][1] = m_dice[3][1];
				m_dice[3][1] = temp;
				printf("%d\n", m_dice[3][1]);
				if (map[m_pos[0]][m_pos[1]] == 0) {
					map[m_pos[0]][m_pos[1]] = m_dice[1][1];
				}
				else {
					m_dice[1][1] = map[m_pos[0]][m_pos[1]];
					map[m_pos[0]][m_pos[1]] = 0;
				}
			}
			break;
		}
	}


	for (int i = 0; i < m_size[0]; i++) {
		free(map[i]);
	}
	free(m_cmd);
	free(map);

	return 0;
}
