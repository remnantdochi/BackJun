#include <iostream>
#include <stdlib.h>
#include <algorithm> //sort, max_element

using namespace std;

bool case1(char*, int*);
int case2(char*, int*);
int case3(char*, int*);
bool case4(char*, int*);
bool case5(char*, int*);
bool case6(char*, int*);
int case7(char*, int*);
int case8(char*, int*);


int main() {
	int score = 0;
	int max_num = 0;
	char* color = new char[5];
	int* number = new int[5];
	

	for (int i = 0; i < 5; i++) {
		cin >> color[i];
		cin >> number[i];
	};


	if (case1(color,number)) {
		
		//max_num = *max_element(number, number+5);
		score = 900 + number[4];
		cout << score << endl;
	}
	else if (case2(color, number)) {
		
		score = 800 + case2(color, number);
		cout << score << endl;
	}
	else if (case3(color, number)) {
		int two = 0 ;
		two = case3(color, number);
		score = 700 + 10 * number[2] + number[two];
		cout << score << endl;
	}
	else if (case4(color, number)) {

		score = 600 + number[4];
		cout << score << endl;
	}
	else if (case5(color, number)) {

		score = 500 + number[4];
		cout << score << endl;
	}
	else if (case6(color, number)) {

		score = 400 + number[2];
		cout << score << endl;
	}
	else if (case7(color, number)) {

		score = 300 + number[1] + number[3] * 10;
		cout << score << endl;
	}
	else if (case8(color, number)) {
		score = 200 + case8(color, number);
		cout << score << endl;
	}
	else {
		sort(number, number + 5);
		score = 100 + number[4];
		cout << score << endl;
	}

	
	delete[] color;
	delete[] number;
};

bool case1(char* color, int* number) {
	bool same_color = 0;
	bool continuous_number = 1;
	same_color = (color[0] == color[1] && color[1] == color[2] && color[2] == color[3] && color[3] == color[4]);

	sort(number, number + 5);

	for (int i = 0; i < 4; i++) {
		if (number[i]+1 != number[i + 1]){
			continuous_number = 0;
			break;
			}
	}

	return same_color && continuous_number;


};

int case2(char* color, int* number) {
	int same_color = 0;
	sort(number, number + 5);

	if (number[0] == number[1]) {
		if (number[0] == number[1] && number[1] == number[2] && number[2] == number[3]) {
			same_color = number[0];
		};
	}
	else {
		if (number[1] == number[2] && number[2] == number[3] && number[3] == number[4]) {
			same_color = number[1];
		};
	}

	return same_color;
}

int case3(char* color, int* number) {
	bool devide_number = 0;
	sort(number, number + 5);

	//뒤에가 3장
	if (number[0] == number[1] && number[2] == number[3] && number[3] == number[4]) {
		return 1;
	}
	//앞이 3장
	else if(number[0] == number[1] && number[1] == number[2] && number[3] == number[4]){
		return 3;
	}
	else {
		return 0;
	}
	
}
bool case4(char* color, int* number) {

	bool same_color = 0;
	sort(number, number + 5);

	same_color = (color[0] == color[1] && color[1] == color[2] && color[2] == color[3] && color[3] == color[4]);
	return same_color;
}
bool case5(char* color, int* number) {
	bool continuous_number = 1;
	sort(number, number + 5);

	for (int i = 0; i < 4; i++) {
		if (number[i] + 1 != number[i + 1]) {
			continuous_number = 0;
			break;
		}
	}
	return continuous_number;
}
bool case6(char* color, int* number) {
	bool devide_number = 0;
	sort(number, number + 5);

	//뒤에가 3장
	if (number[2] == number[3] && number[3] == number[4]) {
		return 1;
	}
	//앞이 3장
	else if (number[0] == number[1] && number[1] == number[2]) {
		return 1;
	}
	else {
		return 0;
	}
}
int case7(char* color, int* number) {
	sort(number, number + 5);
	if (number[0] == number[1] && number[2] == number[3] ) {
		return 1;
	}
	else if (number[0] == number[1] && number[3] == number[4]) {
		return 2;
	}
	else if (number[1] == number[2] && number[3] == number[4]) {
		return 3;
	}
	else {
		return 0;
	}
}
int case8(char* color, int* number) {
	int continuous_number = 0;
	sort(number, number + 5);
	for (int i = 0; i < 4; i++) {
		if (number[i] == number[i + 1]) {
			continuous_number = number[i];
			break;
		}
	}
	return continuous_number;
}


/*
B 7
B 6
B 5
B 4
B 3

B 3
R 3
B 7
Y 3
G 3

R 5
Y 7
G 7
B 5
Y 7

Y 3
Y 4
Y 8
Y 6
Y 7

R 7
R 8
G 9
Y 6
B 5

R 7
Y 7
R 2
G 7
R 5

R 5
Y 5
Y 4
G 9
B 4

R 5
Y 2
B 5
B 3
G 4

R 1
R 2
B 4
B 8
Y 5
*/
