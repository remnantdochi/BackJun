#include <stdio.h>
#include <stdlib.h>

int** m_tab;
int m;
int max;

int func(int cost, int focus) {
	if (m == focus) {
		if (max < cost) {
			max = cost;
		}
		return 0;
	}

	if (focus + m_tab[focus][0] <= m) {
		func(cost + m_tab[focus][1], focus + m_tab[focus][0]);
	}
	func(cost, focus + 1);

	return 0;
}

int main() {
	scanf("%d", &m);

	m_tab = (int**)malloc(sizeof(int*) * m);

	for (int i = 0; i < m; i++) {
		m_tab[i] = (int*)malloc(sizeof(int) * 2);
		scanf("%d %d", &m_tab[i][0], &m_tab[i][1]);
	}

	func(0, 0);
	printf("%d", max);

	for (int i = 0; i < m; i++) {
		free(m_tab[i]);
	}
	free(m_tab);

	return 0;
}
