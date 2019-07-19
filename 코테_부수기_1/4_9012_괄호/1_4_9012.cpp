#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		char PS[51];
		cin >> PS;
		char quebox[26] = { ' ', };
		int length = strlen(PS);
		int index = -1;

		for (int j = 0; j < strlen(PS);j++) {
			if (PS[j] == '(') {
				quebox[index+1] = '(';
				index++;
				continue;
			}
			else if (PS[j] == ')') {
				if (index == -1) {
					index = -2; // 밑에서 else에 걸리게
					break;
				}
				if (quebox[index] == '(') index--;
				else {
					cout << "NO" << endl;
					continue;
				}
			}
		}
		if (index == -1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}