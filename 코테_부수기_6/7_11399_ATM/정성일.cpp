#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

int main() {
	int n;
	std::vector<int> time;
	int i, j;
	int temp;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &temp);
		time.push_back(temp);
	}
	std::sort(time.begin(), time.end());
	temp = 0;
	for (i = 0; i < time.size();i++) {
		for (j = 0; j <= i; j++) {
			temp += time[j];
		}
	}
	printf("%d", temp);

	return 0;
}
