#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int N;

bool compare_(int* comb, int cnt, int idx) { //ture면 좋은순열
	int total_flag = 1; //total_flag=1이면 좋은순열->true반환
	for (int i = 0; i + cnt + cnt - 1 < idx; i++){
		int flag = 0;
		for (int c = 0; c < cnt; c++){
			if (comb[i + c] != comb[i + cnt + c]) { //크기 cnt만큼 비교하는 도중 하나라도 다른게 있다면 좋은조합.
				flag = 1; //인덱스 i에 대해 좋은 조합이라면 flag=1.
				break;
			}
			else
				continue;
		}
		if (flag == 0){ //순열을 크기 cnt만큼씩 비교를 하였을때 나쁜 순열을 가지게하는 조합이 하나라도 있다면,
			total_flag = 0; //결국 이 순열은 나쁜 순열이다.
			break;
		}
	}
	if (total_flag){
		return true;
	}
	else{
		return false;
	}
}


bool check_(int* comb, int idx, int cnt) //중복검사를 위한 함수. (cnt는 비교하는 수의 자릿수의 크기. 한칸씩 비교한다면 1, 두칸씩 비교한다면 2...)
{
	bool flag = true;
	if (cnt > idx / 2) // cnt의 두배가 인덱스 값을 초과한다면 의미가 없으므로 끝.
		return flag;
	if (!compare_(comb, cnt, idx)) //주어진 cnt에 대해 나쁜 순열이라면 false를 반환.
		return false;
	else
		flag = check_(comb, idx, cnt + 1); //주어진 cnt의 값이 초과하지않고, 이 cnt의 값에 대해 좋은 수열이라면 cnt의 값을 1 증가시키고 다시 판별한다.
}


bool IsMin_(int* comb, int idx, int* MIN_comb) //주어진 순열(comb에 담겨있는)이 최소인지 판별하는 함수.
{

	for (int i = 0; i < idx; i++) {
		if (comb[i] > MIN_comb[i])
			break;
		else if (comb[i] == MIN_comb[i])
			continue;
		else {
			for (int j = 0; j < idx; j++) {
				MIN_comb[j] = comb[j];
			}
			return true;
		}
	}
	return false;
}

void function(int* comb, int idx, int* MIN_comb) //최소 순열을 구하는 함수.
{
	if (comb[0]>MIN_comb[0]) //맨 처음 숫자가 최소값을 가지는 순열보다 크다면 끝.
		return;
	
	if (idx>=1 && comb[idx]>MIN_comb[idx]) //다음 인덱스부터 그 인덱스의 숫자가 최소값을 가지는 순열보다 크다면 끝.
		return;

	if (idx >= 2) { //최소값을 가지는 순열보다 작은것이 확인되었으면 이 순열이 좋은순열인지 나쁜순열인지 판별한다.
		if (!check_(comb, idx, 1)) { //나쁜 순열이였다면 끝.
			return;
		}
	}
	if (idx == N) { //구해진 순열이 좋은순열이고 목표 자릿수인 N이라면, 

		if (IsMin_(comb, idx, MIN_comb)) //구해진 순열이 최소값인가?
		{
			for (int i = 0; i < idx; i++) //맞다면 최소순열이 된다.
				MIN_comb[i] = comb[i];
			return;
		}
		else // 아니라면 끝.
			return;
	}
	for (int i = 1; i <= 3; i++) { //다음 인덱스에 1~3 값을 다 넣어본다. ex) 1-> 11, 12, 13
		comb[idx] = i;
		function(comb, idx + 1, MIN_comb);
	}
	return;
}

int main()
{
	cin >> N;
	int* comb = new int[N];
	int* MIN_comb = new int[N];
	for (int i = 0; i < N; i++)
		MIN_comb[i] = 9; //최소 순열의 초기화.

	function(comb, 0, MIN_comb); //최소 순열을 구하는 함수.

	for (int i = 0; i < N; i++) //출력
		cout << MIN_comb[i];

	delete[]MIN_comb;
	delete[]comb;
	return 0;
}
