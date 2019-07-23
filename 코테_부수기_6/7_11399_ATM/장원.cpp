#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int* seq = new int[N];
	for (int i = 0; i < N; i++)
		cin >> seq[i];

	sort(seq, seq + N);

	int* dp = new int[N];
	dp[0] = seq[0];
	for (int i = 1; i < N; i++)
	{
		dp[i] = dp[i - 1] + seq[i];
	}
	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += dp[i];

	cout << sum;

	delete[]seq;
	return 0;
}
