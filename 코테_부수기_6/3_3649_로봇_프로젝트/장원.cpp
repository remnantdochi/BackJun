/*일반적인 탐색은 시간복잡도가 O(n^2)이다. 이를 줄이는 방법은 여러가지가 있지만 대표적으로 균형이진트리(레드블랙 트리, AVL트리)를 사용하는
방법과 해싱을 사용하는 방법이있다. 본 코드는 해싱을 사용하였다.*/

#include <iostream>
#include <cstring>
#define bucket 200257 //해쉬 버킷의 사이즈(소수)
#define depth_ 2 //충돌 시 해쉬 버킷의 허용가능한 깊이

using namespace std;


typedef struct item { //해싱 표의 구조체. 들어와있음을 알려주는 flag와 그 아이템의 값(value)로 구성되어있다.
	int flag;
	int value;
}Item;


int main()
{
	int n, X;

	while (cin >> X >> n)
	{
		int mid_cnt = 0; //예외상황 때문에 추가한 변수. 중간값 길이의 블록이 들어오면 카운트된다.
		int MAX = -1; //구해진 두 블록의 길이 차에 대핸 절대값의 최대값. -1로 초기화되어있다.
		int l1, l2; //l1: 첫 번째 블록의 길이. l2: 두 번째 블록의 길이.

		int x = X * 10000000;
		int temp;
		int* input = new int[n];
		Item** hash = new Item*[bucket];
		for (int i = 0;i< bucket; i++)
			hash[i] = new Item[depth_];
		for (int i = 0;i< bucket; i++) //해싱의 초기 flag값을 0으로 초기화한다. (비어있다.)
			memset(hash[i], 0, depth_ * sizeof(Item));

		for (int i = 0; i < n; i++)
		{
			cin >> input[i];
			if (input[i]==x/2) //중앙값이면 중앙값의 횟수를 의미하는 mid_cnt를 1 더해준다. (x가 짝수이든 홀수이든 상관없음.)
			{
				mid_cnt++;
			}
			temp=input[i];
			
			if (temp > x) //만약 입력된 블록의 길이가 구멍의 너비보다 길다면 의미가 없으므로 버린다.
				continue;
			
			int key = temp % bucket; //해싱 키 값을 생성한다.
			for (int j = 0; j < depth_; j++) //해싱한다.
			{
				if (!hash[key][j].flag) //flag=0이면 (비어있으면)
				{
					hash[key][j].flag = 1; //해싱
					hash[key][j].value = temp;
					break;
				}
				if (hash[key][j].flag && hash[key][j].value == temp) //같은 key값을 가진 값이 들어왔으면 의미없으므로  중복하여 해싱하지 않는다.
					break;
			}
	
		}

		int temp_value;
		int target_key;
		int found = 0; //만족하는 두개의 블록을 하나라도 찾았으면 found=1
		for (int i = 0; i < n; i++)
		{
			temp_value = input[i]; //하나 꺼낸 블록의 길이를 temp_value라고 하자.
			if (temp_value > x) //만약 입력된 블록의 길이가 구멍의 너비보다 길다면 의미가 없으므로 검색하지않는다.
				continue;
			target_key = (x - temp_value) % bucket; // 찾고자 하는 블록의 길이는 x-temp_value이므로 key값은 (x-temp_value)%bucket 이 된다.
			for (int j = 0; j < depth_; j++) //검색 시작.
			{
				if (!hash[target_key][j].flag) //flag=0이라면. 즉 구하고자 하는 key값에 대해 해싱값이 비여있다면 찾고자 하는 블록은 없다. 검색 종료.
					break;

				if (hash[target_key][j].flag && (hash[target_key][j].value == x - temp_value)) { //찾고자하는 블록의 길이가 있다면,
					if ((temp_value == x - temp_value) && (mid_cnt < 2)) //우연히 중간값 길이의 블록이 들어왔고 단 하나만 들어와서 자기 자신의 키에 대해 해싱 검색을 했다면 종료한다.
						break;
					if ((temp_value == x - temp_value) && (mid_cnt >= 2)) //우연히 중간값 길이의 블록이 들어왔고 이러한 블록이 두 개 이상들어왔다면 이 두개의 블록은 가능하다.
					{
						found = 1; //찾음
						l1 = temp_value; //첫 번째 블록의 길이
						l2 = l1; // 두 번째 블록의길이(l1과 같다. 중간값이므로)
						break;
					}
					else { //중간값같은 특이예외가 아닌 지극히 평범한 상황. input 블록의 길이와 target 블록의 길이가 다르며, target 블록의 검색에 성공했을 때,
						found = 1;
						if (temp_value <= x / 2 && x - 2 * temp_value >= MAX) { //두 블록 길이 차의 절대값이 구해진 최대값보다 크다면, 이 두개의 블록으로 갱신한다.
							MAX = x - 2 * temp_value;
							l1 = temp_value;
							l2 = x - temp_value;
							break;
						}
						if (temp_value >= x / 2 && 2 * temp_value - x >= MAX) {
							MAX = x - 2 * temp_value;
							l1 = x - temp_value;
							l2 = temp_value;
							break;
						}
						else
							break;
					}
				}
			}
		}
		if (found)
			cout << "yes" << ' ' << l1 << ' ' << l2 << '\n';
		else
			cout << "danger" << '\n';


		for (int h = 0; h < depth_; h++)
			delete[]hash[h];
		delete[]hash;

		delete[]input;

	}

	return 0;
}



