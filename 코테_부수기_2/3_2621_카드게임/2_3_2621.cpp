#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main() {
	char card[5];
	int number[5];
	for (int i = 0;i < 5;i++) {
		cin >> card[i] >> number[i];
	}
	sort(number, number + 5);
	sort(card, card + 5);
	//cout << card[4] << "card" << endl;
	//cout << number[4] << "num" << endl;

	if (card[0] == card[1] == card[2] == card[3] == card[4]) {
		if (number[4] - 1 == number[3] && number[3] - 1 == number[2] && number[2] - 1 == number[1] && number[1] - 1 == number[0]) {
			cout << number[4] + 900 << endl;
		}
	}
	else if (((number[0] == number[1] == number[2] == number[3]) && (number[3] != number[4]) || (number[0] != number[1])  &&(number[1] == number[2] == number[3] == number[4]))) {
		if (number[0] == number[1]) {
			cout << number[0] + 800 << endl;
		}
		else {
			cout << number[1] + 800 << endl;
		}
	}
	else if ((number[0] == number[1]) && (number[2] == number[3] == number[4]) || (number[0] == number[1] == number[2]) && (number[3] == number[4]) ) {
		if (number[0] == number[1] == number[2]) {
			cout << number[0] * 10 + number[3] + 700 << endl;
		}
		else {
			cout << number[0] + number[2] * 10 + 700 << endl;
		}
	}
	else if (card[0] == card[1] == card[2] == card[3] == card[4]) {
		cout << number[4] + 600 << endl;
	}
	else if (number[4] - 1 == number[3] && number[3] - 1 == number[2] && number[2] - 1 == number[1] && number[1] - 1 == number[0]) {
		cout << number[4] + 500 << endl;
	}
	else if (number[0] == number[1] == number[2] || number[1] == number[2] == number[3] || number[2] == number[3] == number[4]) {
		cout << number[2] + 400 << endl;
	}
	else if ((number[0] == number[1] && number[2] == number[3]) || (number[1] == number[2] && number[3] == number[4])) {
		if (number[0] == number[1]) {
			cout << number[2] * 10 + number[1] + 300;
		}
		else {
			cout << number[3] * 10 + number[2] + 300;
		}
	}
	else if (number[0] == number[1] || number[1] == number[2] || number[2] == number[3] || number[3] == number[4]) {
		if (number[0] == number[1]) {
			cout << number[0] + 200;
		}
		else if (number[1] == number[2]) {
			cout << number[1] + 200;
		}
		else if (number[2] == number[3]) {
			cout << number[2] + 200;
		}
		else {
			cout << number[3] + 200;
		}
	}
	else {
		cout << number[4] + 100 << endl;
	}
}