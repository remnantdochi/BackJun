/*문제 1759_암호_만들기에서는 본 문제와 동일한 유형이지만 재귀함수를 이용하지 않았다. 둘 다 장담점이 뚜렷하여 섞어쓰는것도 좋지만,
사실 최대한 재귀함수를 사용하지 않고 문제를 푸는것이 좋은 습관이다.*/ 

#include <iostream>
#include<cstring>
#include<string>
#include<algorithm>
#define UP 1
#define DOWN 0

using namespace std;
bool check_(int* array, int* visit)
{
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		if (visit[i] == 1) {
			sum += array[i];
		}
	}
	if (sum == 100){
		for (int i = 0; i < 9; i++) {
			if (visit[i])
				cout << array[i] << endl;
		}
		return true;
	}
	return false;
}

int flag = 0; // 일곱 난쟁이를 찾으면 flag=1로 갱신된다.

void find_(int* array, int* visit, int num, int idx, int direction) { 

	if(direction==UP) visit[idx] = 1;
	if (flag || idx > 8 || num > 7) return;
	if (num == 7) {
		if (check_(array, visit)) { flag = 1; return; }
	}
	find_(array, visit, num + 1, idx + 1, UP); //UP방향이면 다음 인덱스의 값을 포함한다.(num:=num+1)
	visit[idx+1] = 0;
	find_(array, visit, num, idx + 1, DOWN);//DOWN방향이면 다음 인덱스의 값을 포함하지 않는다.(num:=num)
}

int main()
{
	int array[9];
	for (int i = 0; i < 9; i++)
		cin >> array[i];
	int visit[9+1] = {0, };
	sort(array, array + 9);
	find_(array, visit, 0, -1, DOWN);
	return 0;
}
/*모든 재귀함수는 수학적으로 반드시 반복문으로 대치될 수 있다. 반복문을 이용하여 풀은 1759_암호_만들기와 비교해보자.*/
