#include <stdio.h>
#include <stdlib.h>
#include <vector>

int m_min;
std::vector<int> m_order;
int m_n, m_k;
int* multitap;

int brutal(int focus, int cnt) {
	int off[2];
	off[0] = -1;
	off[1] = 0;
/*
	for (int i = 0; i < m_n; i++) {
		printf("%d ", multitap[i]);
	}
	printf("\n");
*/
	if (focus == m_k) {
		printf("%d", cnt);
		return 0;
	}

	for (int i = 0; i < m_n; i++) {
		if (multitap[i] == m_order[focus]) {
			brutal(focus + 1, cnt);
			off[0] = -1;
			break;
		}
		else if (multitap[i] == 0) {
			multitap[i] = m_order[focus];
			brutal(focus + 1, cnt);
			off[0] = -1;
			break;
		}
		else {
			for (int j = focus; j < m_k; j++) {
				if (off[1] < j) {
					off[0] = i;
					off[1] = j;
				}
				if (multitap[i] == m_order[j]) {
					break;
				}
				else if(j == m_k - 1) {
					off[0] = i;
					off[1] = j + 1;
				}
			}
		}
	}
	if (off[0] != -1) {
		multitap[off[0]] = m_order[focus];
		brutal(focus + 1, cnt + 1);
	}
	return 0;
}

int main() {
	scanf("%d %d", &m_n, &m_k);
	multitap = (int*)malloc(sizeof(int) * m_n);
	for (int i = 0; i < m_n; i++) {
		multitap[i] = 0;
	}
	for (int i = 0; i < m_k; i++) {
		int temp;
		scanf("%d", &temp);
		m_order.push_back(temp);
	}
	m_min = m_k;
	brutal(0, 0);

	free(multitap);

	return 0;
}
