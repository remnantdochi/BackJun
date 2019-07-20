/*아주 간단한 재귀함수 사용. 가독성은 좋지만 효율은 떨어진다. */
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int N;
int MAX = 0;
void check(int* array,int* idx_storage)
{

	for (int i = 0; i < N; i++){
		for (int j = i+1; j < N; j++){
			if (idx_storage[i] == idx_storage[j]){
				return;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < N - 1; i++)
		sum += abs(array[idx_storage[i]] - array[idx_storage[i + 1]]);
	if (sum > MAX)
		MAX = sum;	
}

void function(int* array, int* idx_storage, int num)
{
	if (num == N) {
		check(array, idx_storage);
		return;
	}
	for (int i = 0; i < N; i++) {
		idx_storage[num] = i;
		function(array, idx_storage, num + 1);
	}
}

int main()
{
	cin >> N;
	int* array = new int[N];
	for (int i = 0; i < N; i++)
		cin >> array[i];
	int* history = new int[N];

	function(array, history, 0);

	delete[]history;
	delete[]array;
	cout << MAX;
	return 0;
}
