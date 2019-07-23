#include <iostream>
#include<cstring>
using namespace std;

typedef struct item {
	int consent_i;
	int cnt;
}Item;

int main()
{
	int N, K;
	int count = 0;
	cin >> N>>K;
	int* app = new int[K];
	int* consent = new int[N];
	memset(consent, 0, N * sizeof(int));
	
	for (int i = 0; i < K; i++)
		cin >> app[i];
	if (N >= K) {
		cout << '0';
		return 0;
	}
	
	int app_ptr = 0;
	for (int i = 0; ;) 
	{
		if (app_ptr >= K)
			break;
		if (i >= N)
			break;

		if (i == 0)
		{
			consent[i] = app[app_ptr];
			app_ptr++;
			i++;
			continue;
		}

		int flag = 0;
		for (int j = 0; j < i; j++)
		{
			if (consent[j] == app[app_ptr])
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			app_ptr++;
		else
		{
			consent[i] = app[app_ptr];
			app_ptr++;
			i++;
		}
	}
	while (app_ptr<K)
	{
		Item chosen;
		chosen.cnt = 0;
		for (int i = 0; i < N; i++)
		{
			int cnt = 0;
			for (int j = app_ptr; j < K; j++)
			{
				if (app[j] == consent[i])
					break;
				else
					cnt++;
			}
			if (cnt >= chosen.cnt)
			{
				chosen.cnt = cnt;
				chosen.consent_i = i;
			}
		}
		int flag = 0;
		for (int i = 0; i < N; i++)
		{
			if (consent[i] == app[app_ptr])
			{
				flag = 1;
				break;
			}
		}
		if (!flag) {
			consent[chosen.consent_i] = app[app_ptr];
			count++;
			app_ptr++;
		}
		else
		{
			app_ptr++;
		}
	}
	cout << count;
	delete[]app;
	delete[]consent;
	return 0;
}
