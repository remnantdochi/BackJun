#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef struct m_time {
	int start, end;
}m_time;

bool f(m_time a, m_time b) {
	if (a.start < b.start) {
		return 1;
	}
	if (a.start == b.start && a.end < b.end) {
		return 1;
	}
	return 0;
}

int main() {
	int n;
	struct m_time* ip;

	scanf("%d", &n);
	ip = (m_time*)malloc(sizeof(m_time) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &ip[i].start, &ip[i].end);
	}
	sort(ip, ip + n, f);
	for (int i = 0; i < n; i++) {
	}
	int i=0;
	int cnt = 0;
	while (i < n) {
		if (ip[i].start == ip[i].end) {
			cnt++;
			i++;
		}
		else {
			cnt++;
			int min[2];
			min[0] = ip[i].end;
			min[1] = i;
			for (int j = i + 1; ip[j].start < min[0]; j++) {
				if (ip[j].end < min[0]) {
					min[0] = ip[j].end;
					min[1] = j;
				}
			}
			i = min[1] + 1;
			while (ip[i].start < min[0] && i<=n) {
				i++;
			}
		}
	}
	printf("%d", cnt);

	return 0;
}
