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
		bool flag = false;
		for (int j = 0; j < N;j++) {
			if (map[i][j] == 'X') {
				flag = false;
				//cout << "test1 " << "i: " << i << " j: " << j << " cnt: " << cnt << endl;
				cnt = 0;
				continue;
			}
			if (++cnt == 2) {
				if (flag == false) {
					flag = true;
					row++;
					//cout << "test2 " << "i: " << i << " j: " << j << " cnt: " << cnt << endl;
				}
				//cout << "test3 " << "i: " << i << " j: " << j << " cnt: " << cnt << endl;
				cnt = 0;
			}
			//cout << "test4 " << "i: " << i << " j: " << j << " cnt: " << cnt << "row : "<< row << endl;
		}
	}
	//cout << endl;
	for (int i = 0;i < N;i++) {
		int cnt = 0;
		bool flag = false;
		for (int j = 0; j < N;j++) {
			if (map[j][i] == 'X') {
				flag = false;
				cnt = 0;
				//cout << "test4 " << "i: " << i << " j: " << j << " cnt: " << cnt << endl;
				continue;
			}
			if (++cnt == 2) {
				if (flag == false) {
					flag = true;
					col++;
					//cout << "test5 " << "i: " << i << " j: " << j << " cnt: " << cnt << endl;
				}
				//cout << "test6 " << "i: " << i << " j: " << j << " cnt: " << cnt << endl;
				cnt = 0;
			}
		}
	}

	cout << row << " "<< col <<endl;
}
