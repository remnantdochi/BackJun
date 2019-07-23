#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N,L;
	cin >> N>>L;
	int* broken = new int[N];
	
	for (int i = 0; i < N; i++)
		cin >> broken[i];

	sort(broken, broken + N);

	int cnt = 0;
	for (int i = 0; i < N;)
	{
		int temp_cnt=0;
		int temp = i;
		while (1)
		{
			if ((broken[temp] - broken[i] + 1) <= L)
			{
				temp_cnt++;
				temp += 1;
				if (temp == N)
					break;
			}
			else
				break;

		}
		i = i + temp_cnt;
		cnt++;

	}
	cout << cnt;
	delete[]broken;
	return 0;
}
