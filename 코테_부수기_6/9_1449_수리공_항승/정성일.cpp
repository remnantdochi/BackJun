#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
	int n, l;
	std::vector<int> pos;
	int temp;
	int cnt = 0;

	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		pos.push_back(temp);
	}
	std::sort(pos.begin(), pos.end());
	std::reverse(pos.begin(), pos.end());

	while (n>0) {
		n--;
		temp = pos[n];
		cnt++;
		pos.pop_back();
		while (n > 0 && temp + l - 1 >= pos[n-1]) {
			pos.pop_back();
			n--;
		}
	}

	printf("%d", cnt);
	return 0;
}
