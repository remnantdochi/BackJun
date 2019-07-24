#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

std::vector<int> length;

int bi_search(int start, int end, int find) {
	if (start == end) {
		if (length[start] == find) {
			return start;
		}
		return -1;
	}
	if ((start - end) * (start - end) == 1) {
		if (length[start] == find) {
			return start;
		}
		if (length[end] == find) {
			return end;
		}
		return -1;
	}

	if (length[(start + end) / 2] > find) {
		return bi_search(start, (start + end) / 2, find);
	}
	return bi_search((start + end) / 2, end, find);
}

int main() {
	int target;
	int n;
	int i, j;
	int temp;
	int end;

	while (scanf("%d", &target) == 1) {
		end = 0;
		
		scanf("%d", &n);
		if (n == 0) {
			printf("danger\n");
			end = 1;
		}
		if (n == 1) {
			scanf("%d", &temp);
			printf("danger\n");
			end = 1;
		}
		if (end == 0) {
			for (i = 0; i < n; i++) {
				scanf("%d", &temp);
				length.push_back(temp);
			}
			sort(length.begin(), length.end());
			for (i = 0; i < n; i++) {
				temp = bi_search(i + 1, n - 1, target * 10000000 - length[i]);
				if (temp != -1) {
					printf("yes %d %d\n", length[i], length[temp]);
					end = 1;
					break;
				}
				else if (length[i] + length[j] > target * 10000000) {
					break;
				}
				if (end == 1) {
					break;
				}
			}
			if (end == 0) {
				printf("danger\n");
			}
			length.clear();
		}
	}
	return 0;
}
