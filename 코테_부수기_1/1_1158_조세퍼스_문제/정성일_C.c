#include <stdio.h>

int main() {
	int n, k;
	int m_state[5001] = { .0 };
	int i, j=0, m_end=1;

	scanf("%d %d", &n, &k);

	for (i = 1; i <= n; i++) {
		m_state[i] = 1;
	}

	printf("<");

	while (m_end) {
		i = k;
		while (i!=0) {
			j++;
			if (j > n) {
				j = 1;
			}
			if (m_state[j]) {
				i--;
			}
		}

		m_state[j] = 0;
		printf("%d", j);

		m_end = 0;
		for (i = 1; i <= n; i++) {
			if (m_state[i] == 1) {
				m_end = 1;
			}
		}

		if (m_end==1) {
			printf(", ");
		}
	}

	printf(">\n");

	return 0;

}
