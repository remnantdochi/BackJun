#include <stdio.h>
#include <stdlib.h>

int main() {
	int* m_stu;
	int m_room;
	int cap_A, cap_B;

	scanf("%d", &m_room);

	m_stu = (int*)malloc(sizeof(int) * m_room);

	for (int i = 0; i < m_room; i++) {
		scanf("%d", &m_stu[i]);
	}

	scanf("%d %d", &cap_A, &cap_B);

	double cnt = 0;
	for (int i = 0; i < m_room; i++) {
		m_stu[i] -= cap_A;
		cnt++;
		if (m_stu[i] > 0) {
			cnt += m_stu[i] / cap_B;
			if (m_stu[i] % cap_B != 0) {
				cnt++;
			}
		}
	}
	printf("%.f", cnt);

	free(m_stu);

	return 0;
}
