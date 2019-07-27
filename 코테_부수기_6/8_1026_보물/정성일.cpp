#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

std::vector<int> num1;
std::vector<int> num2;
int m_min;
int m_size;

int calc() {
	int ans = 0;
	int i;

	for (i = 0; i < m_size; i++) {
		ans += num1[i] * num2[i];
	}

	return ans;
}

int main() {
	int i;
	int temp;

	scanf("%d", &m_size);
	for (i = 0; i < m_size; i++) {
		scanf("%d", &temp);
		num1.push_back(temp);
	}
	for (i = 0; i < m_size; i++) {
		scanf("%d", &temp);
		num2.push_back(temp);
	}
	std::sort(num1.begin(), num1.end());
	std::sort(num2.begin(), num2.end());
	std::reverse(num2.begin(), num2.end());
	m_min = calc();

	printf("%d", m_min);

	return 0;
}
