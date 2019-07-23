#include <iostream>
#include<algorithm>
using namespace std;

bool cmp1(const int&a, const int&b)
{
	return a < b;
}

bool cmp2(const int&a, const int&b)
{
	return a > b;
}

int main()
{
	int N;
	cin >> N;
	int* A = new int[N];
	int* B = new int[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];
	sort(A, A + N, cmp2);
	sort(B, B + N, cmp1);
	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += A[i] * B[i];

	cout << sum;
	delete[]A;
	delete[]B;
	return 0;
}
