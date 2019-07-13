#include <stdio.h>

int main() {

	int ip;
	int m1[2], m2[2];
	int count;

	count = 0;
	scanf("%d", &ip);

	m1[0] = ip / 10;
	m1[1] = ip % 10;

	while (1) {
		m2[0] = m1[1];
		m2[1] = (m1[0] + m1[1]) % 10;
		count++;
		if (10 * m2[0] + m2[1] == ip) {
			break;
		}
		m1[0] = m2[0];
		m1[1] = m2[1];
	}

	printf("%d", count);

	return 0;
}
