#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
// -1 벽
// 0 빈칸
// 1 뱀
// 2 사과
typedef struct m_pos {
	int x;
	int y;
}m_pos;

int move(int m_time, int** cmd, int cmd_cnt, int** map, vector<m_pos> snake, m_pos direct, int cmd_num) {
	if (cmd_num > cmd_cnt) {
		if (cmd[cmd_cnt][0] == m_time) {
			if (cmd[cmd_cnt][1] == 0) {//right
				int temp = direct.x;
				direct.x = direct.y;
				direct.y = temp * (-1);
			}
			else {//left
				int temp = direct.x;
				direct.x = direct.y * (-1);
				direct.y = temp;
			}
			cmd_cnt++;
		}
	}

	m_time++;
	m_pos add;
	add = snake[snake.size()-1];
	add.x = add.x + direct.x;
	add.y = add.y + direct.y;
	//printf("%d %d\n", add.x, add.y);
	snake.push_back(add);
	if (map[add.x][add.y] == 0) {
		map[add.x][add.y] = 1;
		add = snake[0];
		map[add.x][add.y] = 0;
		snake.erase(snake.begin());
		return move(m_time, cmd, cmd_cnt, map, snake, direct, cmd_num);
	}
	else if (map[add.x][add.y] == 2) {
		map[add.x][add.y] = 1;
		return move(m_time, cmd, cmd_cnt, map, snake, direct, cmd_num);
	}
	else {
		return m_time;
	}
}

int main() {
	int m_size;
	vector<m_pos> snake;
	m_pos temp;
	scanf("%d", &m_size);

	int** map = (int**)malloc(sizeof(int*) * (m_size + 2));
	for (int i = 0; i <= m_size + 1; i++) {
		map[i] = (int*)malloc(sizeof(int) * (m_size + 2));
		for (int j = 0; j <= m_size + 1; j++) {
			if (i == 0 || j == 0 || i == m_size + 1 || j == m_size + 1) {
				map[i][j] = -1;
			}
			else {
				map[i][j] = 0;
			}
		}
	}

	int num_app;
	scanf("%d", &num_app);
	for (int i = 0; i < num_app; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		map[x][y] = 2;
	}

	temp.x = 1;
	temp.y = 1;
	map[1][1] = 1;
	snake.push_back(temp);

	int num_cmd;
	scanf("%d", &num_cmd); 
	int** cmd = (int**)malloc(sizeof(int*) * num_cmd);
	for (int i = 0; i < num_cmd; i++) {
		cmd[i] = (int*)malloc(sizeof(int) * 2);
		char ch;
		scanf(" %d %c", &cmd[i][0], &ch);
		if (ch == 'D') {
			cmd[i][1] = 0;
		}
		else if (ch == 'L') {
			cmd[i][1] = 1;
		}
	}

	temp.x = 0;
	temp.y = 1;

	printf("%d", move(0, cmd, 0, map, snake, temp, num_cmd));

	for (int i = 0; i <= m_size + 1; i++) {
		free(map[i]);
	}
	free(map);
	for (int i = 0; i < num_cmd; i++) {
		free(cmd[i]);
	}
	free(cmd);

	return 0;
}
