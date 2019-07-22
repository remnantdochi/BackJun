#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main() {

	int N;
	int length;
	int check = 0;
	int prime = 0;
	char str[8];
	cin >> N;
	
	

	while (1) {
		check = 0;
		//itoa(N, str, 10); //int를 str로 바꿈.
		sprintf(str, "%d", N);
		length = strlen(str);

		//팰린드롬 판별
		for (int i = 0; i < length / 2; i++) {

			if (str[i] != str[length - 1 - i]) {
				check = 1;
				break;

			}
		}

		if (check == 0) {
			prime = 0;
			//소수 판별
			if(N == 1){
				prime = 1;
				N++;
			}
			else {
				for (int j = 2; j < N; j++) {
					if (N%j == 0) {
						prime = 1;
						N++;
						break;
					}
				}
			}

			if (prime == 0) {

				printf("%d\n", N);
				break;
			}

		}
		else {
			N++;
		}
	}


	return 0;
}
