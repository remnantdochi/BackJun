#include <iostream>
#include <string>
#include<cstring>
#include<algorithm>
using namespace std;

typedef struct resrv {
	int start;
	int end;
}Reserv;

bool cmp(const Reserv& a, const Reserv& b)
{
	if (a.end != b.end)
		return a.end < b.end;
	else 
		return a.start < b.start;
}

int main()
{
	int N;
	cin >> N;
	Reserv* res = new Reserv[N];
	for (int i = 0; i < N; i++)
	{
		cin >> res[i].start >> res[i].end;
	}
		
	sort(res, res + N, cmp);
	
	int end = res[0].end;
	int cnt = 1;
	for (int i = 1; i < N; i++)
	{
		if (res[i].start >= end)
		{
			cnt++;
			end = res[i].end;
		}
	}

	cout << cnt;
	delete[]res;
	return 0;
}
