#include <iostream>
#include <stdlib.h>
#include <string> //string 사용

using namespace std;

int main() {
	int N;
	int X = 0, Y = 0; //X는 가로, Y는 세로
	int count = 0;
	string str;
	cin >> N ;
	
	string *seat = new string[N];
	
	for (int i = 0; i < N; i++) {
		cin >> str;
		seat[i] = str;
	}

	//가로(X) 세기
	for (int i = 0; i < N; i++) {
		count = 0;
		for (int j = 0; j < N; j++) {
			if (seat[i][j] == '.') {
				count++;
			}
			else {
				count = 0;
			}

			if (count == 2) {
				X++;
			}
		}
	}


	//세로(Y)세기
	for (int i = 0; i < N; i++) {
		count = 0;
		for (int j = 0; j < N; j++) {
			if (seat[j][i] == '.') {
				count++;
			}
			else {
				count = 0;
			}

			if (count== 2) {
				Y++;
			}
		}
	}
	cout << X <<" "<<Y<< endl;

	delete[] seat;
}
