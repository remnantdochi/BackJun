#include <iostream>
#include <stdlib.h>

using namespace std;
int main()
{
	int N;
	cin >> N;
	char map[101][101];
	int row = 0, col = 0;
	for (int i = 0;i < N;i++) {
		cin >> map[i];
		int cnt = 0;
		int j = 0;
		while (j < N) {
			if (map[i][j] == 'X') {
				cnt = 0;
				//j++;
				cout << "test1" << "i : " << i << " j : " << j << " cnt: " << cnt << endl;
				j++;
				continue;
			}
			if (++cnt == 2) {
				row++;
				cout << "test2" << "i : " << i << " j : " << j << " cnt: " << cnt << endl;
				//j++;
				break;
			}
			cout << "test3" << "i : " << i << " j : " << j << " cnt: " << cnt << endl;
			j++;
		}
	}
	cout << endl;
	for (int i = 0;i < N;i++) {
		int cnt = 0;
		for (int j = 0; j < N;j++) {
			if (map[j][i] == 'X') {
				cnt = 0;
				cout << "test4" << "i : " << i << " j : " << j << " cnt: " << cnt << endl;
				continue;
			}
			if (++cnt == 2) {
				col++;
				cout << "test5" << "i : " << i << " j : " << j << " cnt: " << cnt << endl;
				break;
			}
			cout << "test6" << "i : " << i << " j : " << j << " cnt: " << cnt << endl;
		}
	}

	cout << row << " "<< col <<endl;
}