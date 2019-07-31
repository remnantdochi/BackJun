#include <stdio.h>

int m_size;

void print_map(int map[20][20]);
int lv_up(int map[20][20], int x, int y);
int f_up(int map[20][20], int cnt);
int f_down(int ex_map[20][20], int cnt);
int f_left(int map[20][20], int cnt);
int f_right(int ex_map[20][20], int cnt);
int f_push(int map[20][20], int x, int y);
int f_next(int map[20][20], int cnt);

void print_map(int map[20][20]) {
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			printf("%3d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int lv_up(int map[20][20], int x, int y) {
	int change = 0;
	if (x != 0) {
		int i = (1 + x) / 2 * (m_size - 1);
		for (int j = 0; j < m_size - 1; j++) {
			for (int k = 0; k < m_size; k++) {
				if (map[i - j * x][k] == map[i - j * x - x][k]) {
					map[i - j * x][k] = map[i - j * x][k] * 2;
					map[i - j * x - x][k] = 0;
					change = 1;
				}
			}
		}
	}
	else {
		int i = (1 + y) / 2 * (m_size - 1);
		for (int j = 0; j < m_size - 1; j++) {
			for (int k = 0; k < m_size; k++) {
				if (map[k][i - j * y] == map[k][i - j * y - y]) {
					map[k][i - j * y] = map[k][i - j * y] * 2;
					map[k][i - j * y - y] = 0;
					change = 1;
				}
			}
		}
	}
	//print_map(map);
	return change;
}

int f_push(int map[20][20], int x, int y) {
	int result = 0;
	if (x != 0) {
		for (int i = 0; i < m_size; i++) {
			int j = (1 + x) / 2 * (m_size - 1);
			for (int k = (1 + x) / 2 * (m_size - 1); 0 <= k && k < m_size; k-=x) {
				if (map[k][i] != 0) {
					if (j != k) {
						map[j][i] = map[k][i];
						result = 1;
					}
					j-=x;
				}
			}
			for (int k = j; 0 <= k && k < m_size; k-=x) {
				map[k][i] = 0;
			}
		}
	}
	else {
		for (int i = 0; i < m_size; i++) {
			int j = (1 + y) / 2 * (m_size - 1);
			for (int k = (1 + y) / 2 * (m_size - 1); 0 <= k && k < m_size; k -= y) {
				if (map[i][k] != 0) {
					if (j != k) {
						map[i][j] = map[i][k];
						result = 1;
					}
					j -= y;
				}
			}
			for (int k = j; 0 <= k && k < m_size; k -= y) {
				map[i][k] = 0;
			}
		}
	}
	//print_map(map);
	return result;
}

int f_up(int ex_map[20][20], int cnt) {
	int map[20][20];
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			map[i][j] = ex_map[i][j];
		}
	}
	int result = f_push(map, -1, 0);
	if (lv_up(map, -1, 0)) {
		result = 1;
	}
	if (f_push(map, -1, 0)) {
		result = 1;
	}
	if (result) {
		cnt++;
		return f_next(map, cnt);
	}
	return f_next(map, 5);
}
int f_down(int ex_map[20][20], int cnt) {
	int map[20][20];
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			map[i][j] = ex_map[i][j];
		}
	}
	int result = f_push(map, 1, 0);
	if (lv_up(map, 1, 0)) {
		result = 1;
	}
	if (f_push(map, 1, 0)) {
		result = 1;
	}
	if (result) {
		cnt++;
		return f_next(map, cnt);
	}
	return f_next(map, 5);
}
int f_left(int ex_map[20][20], int cnt) {
	int map[20][20];
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			map[i][j] = ex_map[i][j];
		}
	}
	int result = f_push(map, 0, -1);
	if (lv_up(map, 0, -1)) {
		result = 1;
	}
	if (f_push(map, 0, -1)) {
		result = 1;
	}
	if (result) {
		cnt++;
		return f_next(map, cnt);
	}
	return f_next(map, 5);
}
int f_right(int ex_map[20][20], int cnt) {
	int map[20][20];
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			map[i][j] = ex_map[i][j];
		}
	}
	int result = f_push(map, 0, 1);
	if (lv_up(map, 0, 1)) {
		result = 1;
	}
	if (f_push(map, 0, 1)) {
		result = 1;
	}
	if (result) {
		cnt++;
		return f_next(map, cnt);
	}
	return f_next(map, 5);
}

int f_next(int map[20][20], int cnt) {
	int max = 0;
	if (cnt >= 5) {
		for (int i = 0; i < m_size; i++) {
			for (int j = 0; j < m_size; j++) {
				if (max < map[i][j]) {
					max = map[i][j];
				}
			}
		}
		return max;
	}
	int temp = f_up(map, cnt);
	if (temp > max) {
		max = temp;
	}
	temp = f_down(map, cnt);
	if (temp > max) {
		max = temp;
	}
	temp = f_left(map, cnt);
	if (temp > max) {
		max = temp;
	}
	temp = f_right(map, cnt);
	if (temp > max) {
		max = temp;
	}
	return max;
}

int main() {
	int map[20][20];
	scanf("%d", &m_size);

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			map[i][j] = 0;
		}
	}

	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	//print_map(map);
	printf("%d", f_next(map, 0));
	
	return 0;
}
