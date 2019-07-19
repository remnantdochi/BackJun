#include <iostream>
#include <algorithm>
#include <list>
#include <string>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	list <int> people;
	for (int i = 1; i < N + 1; i++) {
		people.push_back(i);
	}

	list<int>::iterator it = people.begin();
	int count = 1;
	int num = 0;
	printf("<");
	while (num < N) {
		if (it == people.end()) {
			it = people.begin();
		}
		if (count == K) {
			printf("%d", *it);
			it = people.erase(it);
			count = 1;
			num++;
			if (num < N)printf(", ");
		}
		else {
			count++;
			++it;
		}

	}
	printf(">");
}