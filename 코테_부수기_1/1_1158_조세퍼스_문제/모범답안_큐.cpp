#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	//n명 k번째
	int N, K;	cin >> N >> K; int k = 0;
	deque<int> q;
	for (int i = 1; i <= N; i++)
		q.push_front(i);
	cout << "<";
	while (!q.empty())
	{
		if (k != 0 && !q.empty())
		{
			cout << ", ";
		}
		k = 1;
		for (int i = 0; i < K - 1; i++)
		{
			q.push_front(q.back());//뒤에있는걸 앞으로 넣는다.
			q.pop_back();
		}
		cout << q.back();
		q.pop_back();
	}
	cout << ">";
	return 0;
}
