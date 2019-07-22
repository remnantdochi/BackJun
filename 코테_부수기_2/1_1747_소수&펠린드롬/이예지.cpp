#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


using namespace std;

bool isPalindrome(char* letter) {
	int length = strlen(letter);
	for (int i = 0;i < length/2; i++) {
		//cout << i << " " << length - i-1 << endl;
		//cout << letter[i] << " " << letter[length - i-1] << endl;
		if (letter[i] != letter[length - i-1]) {
			return false;
		}
	}
	return true;
}

bool isPrime(int num) {
	for (int i = 2;i <= num / 2;i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}


int main() {
	int N;
	cin >> N;
	if (N == 1) {
		cout << 2;
		return 0;
	}
	char *tmp = (char*)malloc(sizeof(char));
	//N += 1;

	while (1) {
		sprintf(tmp, "%d", N);
		//cout << tmp << " " << tmp[1] << endl;
		if (isPalindrome(tmp)) {
			//cout << "isPrime" << N << endl;
			if (isPrime(N)) {
				cout << N << endl;
				return 0;
			}
		}
		N++;
	}
	free(tmp);
}
