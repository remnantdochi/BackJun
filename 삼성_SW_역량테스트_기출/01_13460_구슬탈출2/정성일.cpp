#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

typedef struct pos {
	int rb[2];
	int bb[2];
}pos;

int move(int step, int map[10][10], std::vector<pos> data) {
	int n = data.size();
	std::vector<pos> new_data;
	pos pos1;

	step++;
	if (step > 10) {
		return -1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = -1; j < 2; j += 2) {
			for (int k = 0; k < 2; k++) {
				pos1 = data[i];
				int rb_h = 0;
				int bb_h = 0;
				if (pos1.bb[k] == pos1.rb[k]) {
					if (pos1.bb[1 - k] * j < pos1.rb[1 - k] * j) {
						while (map[pos1.rb[0] + (j * k)][pos1.rb[1] + (j * (1 - k))] != -1) {
							pos1.rb[1 - k] += j;
							if (map[pos1.rb[0]][pos1.rb[1]] == 1) {
								rb_h = 1;
								pos1.rb[0] = 0;
								pos1.rb[1] = 0;
								break;
							}
						}
						while (map[pos1.bb[0] + (j * k)][pos1.bb[1] + (j * (1 - k))] != -1 && pos1.bb[1 - k] + j != pos1.rb[1 - k]) {
							pos1.bb[1 - k] += j;
							if (map[pos1.bb[0]][pos1.bb[1]] == 1) {
								bb_h = 1;
								pos1.bb[0] = 0;
								pos1.bb[1] = 0;
								break;
							}
						}
					}
					else {
						while (map[pos1.bb[0] + (j * k)][pos1.bb[1] + (j * (1 - k))] != -1) {
							pos1.bb[1 - k] += j;
							if (map[pos1.bb[0]][pos1.bb[1]] == 1) {
								bb_h = 1;
								pos1.bb[0] = 0;
								pos1.bb[1] = 0;
								break;
							}
						}
						while (map[pos1.rb[0] + (j * k)][pos1.rb[1] + (j * (1 - k))] != -1 && pos1.rb[1 - k] + j != pos1.bb[1 - k]) {
							pos1.rb[1 - k] += j;
							if (map[pos1.rb[0]][pos1.rb[1]] == 1) {
								rb_h = 1;
								pos1.rb[0] = 0;
								pos1.rb[1] = 0;
								break;
							}
						}
					}
				}
				else {
					while (map[pos1.rb[0] + (j * k)][pos1.rb[1] + (j * (1 - k))] != -1) {
						pos1.rb[1 - k] += j;
						if (map[pos1.rb[0]][pos1.rb[1]] == 1) {
							rb_h = 1;
							pos1.rb[0] = 0;
							pos1.rb[1] = 0;
							break;
						}
					}
					while (map[pos1.bb[0] + (j * k)][pos1.bb[1] + (j * (1 - k))] != -1) {
						pos1.bb[1 - k] += j;
						if (map[pos1.bb[0]][pos1.bb[1]] == 1) {
							bb_h = 1;
							pos1.bb[0] = 0;
							pos1.bb[1] = 0;
							break;
						}
					}
				}
				if (bb_h == 0) {
					if (rb_h == 1) {
						return step;
					}
					if (pos1.rb[0] != data[i].rb[0] || pos1.rb[1] != data[i].rb[1] || pos1.bb[0] != data[i].bb[0] || pos1.bb[1] != data[i].bb[1]) {
						//printf(" red : %d %d -> %d %d\n", data[i].rb[0], data[i].rb[1], pos1.rb[0], pos1.rb[1]);
						//printf("blue : %d %d -> %d %d\n", data[i].bb[0], data[i].bb[1], pos1.bb[0], pos1.bb[1]);
						new_data.push_back(pos1);
					}
				}
			}
		}
	}
	/*
	printf("%d\n", step);
	for (int i = 0; i < new_data.size(); i++) {
		printf("blue : %d %d\n red : %d %d\n", new_data[i].bb[0], new_data[i].bb[1], new_data[i].rb[0], new_data[i].rb[1]);
	}*/
	return move(step, map, new_data);
}

int main() {
	int size[2];
	int map[10][10];
	std::vector<pos> que;
	pos pos1;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = 0;
		}
	}

	scanf("%d %d", &size[0], &size[1]);
	for (int i = 0; i < size[0]; i++) {
		for (int j = 0; j < size[1]; j++) {
			char temp;
			scanf(" %c", &temp);
			if (temp == '#') {
				map[i][j] = -1;
			}
			else if (temp == '.') {
				map[i][j] = 0;
			}
			else if (temp == 'O') {
				map[i][j] = 1;
			}
			else if (temp == 'R') {
				map[i][j] = 0;
				pos1.rb[0] = i;
				pos1.rb[1] = j;
			}
			else if (temp == 'B') {
				map[i][j] = 0;
				pos1.bb[0] = i;
				pos1.bb[1] = j;
			}
		}
	}
	que.push_back(pos1);

	int step = move(0, map, que);

	printf("%d", step);

	return 0;
}
