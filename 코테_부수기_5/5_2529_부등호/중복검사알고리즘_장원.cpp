#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int k;

bool check_1(int* comb, int idx) //중복검사
{
	/*함수 check_1은 인트형 배열 comb에 들어있는 idx개의 숫자들 중에서
	중복되어있는 수가 있는지 확인하는 함수이다.
	
	놀랍게도(?) 이 함수는 선형시간의 시간복잡도 O(n) 를 가지게 할 수있다.
	
	어떻게하면 중복검사를 선형시간에 끝낼수 있을지 생각해보라고 빈칸으로 남겨둠!!.
	*/
}

bool check_2(int* comb, char* symbol, int idx) //부등호 검사
{
	if (symbol[idx - 2] == '<'){
		if (comb[idx - 2] < comb[idx - 1])
			return true;
		else
			return false;
	}
	else{
		if (comb[idx - 2] > comb[idx - 1])
			return true;
		else
			return false;
	}
}

void compare_(int* comb, int idx, int* MAX_comb, int* MIN_comb) //MAX값과 MIN값의 비교.
{
	for (int i = 0; i < idx; i++){
		if (comb[i] < MAX_comb[i])
			break;
		else if (comb[i] == MAX_comb[i])
			continue;
		else  {
			for (int j = 0; j < idx; j++) {
				MAX_comb[j] = comb[j];
			}
			break;
		}
	}
	for (int i = 0; i < idx; i++) {
		if (comb[i] > MIN_comb[i])
			break;
		else if (comb[i] == MIN_comb[i])
			continue;
		else  {
			for (int j = 0; j < idx; j++) {
				MIN_comb[j] = comb[j];
			}
			break;
		}
	}	
}

void function(int* comb, char* symbol,int idx, int* MAX_comb, int* MIN_comb) //재귀함수를 이용.
{
	if (idx >= 2){
		if ((!check_1(comb,idx))||(!check_2(comb,symbol,idx)))
			return;
	}
	if (idx == k+1){
		compare_(comb, idx,MAX_comb,MIN_comb);
		return;
	}
	for (int i = 0; i < 10; i++){
		comb[idx] = i;
		function(comb, symbol,idx+1,MAX_comb,MIN_comb);
	}
	return;
}

int main()
{
	cin >> k;
	char* symbol = new char[k];
	for (int i = 0; i < k; i++)
		cin >> symbol[i];

	int comb[10];
	int MAX_comb[10] = { 0 ,};
	int MIN_comb[10] = { 9,9,9,9,9,9,9,9,9,9 };

	function(comb, symbol, 0, MAX_comb, MIN_comb);

	for (int i = 0; i < k + 1; i++)
		cout << MAX_comb[i];
	cout << endl;
	for (int i = 0; i < k + 1; i++)
		cout << MIN_comb[i];

	delete[]symbol;
	return 0;
}
