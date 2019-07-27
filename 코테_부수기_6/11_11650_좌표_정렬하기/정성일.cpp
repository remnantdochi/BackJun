#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;
typedef struct x_y {
	int x, y;
}x_y;

bool f(x_y a, x_y b) {
	if (a.x < b.x)return 1;
	if (a.x == b.x && a.y < b.y)return 1;
	return 0;
}

int main() {
	int n;
	scanf("%d", &n);
	x_y* ip;
	ip = (x_y*)malloc(sizeof(x_y) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &ip[i].x, &ip[i].y);
	}
	sort(ip, ip + n, f);
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", ip[i].x, ip[i].y);
	}
	return 0;
}
