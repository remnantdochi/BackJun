#include <iostream>
#include<map>
#include <string>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int N, M;
	int cnt = 0;
	cin >> N >> M;
	string* n_str = new string[N];
	bool* temp_store = new bool[N];
	memset(temp_store, false, N * sizeof(bool));
	map<string, int> m_str;
	for (int i = 0; i < N; i++)
		cin >> n_str[i];
	sort(n_str, n_str + N);
	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;
		pair<string, int>p(temp, i);
		m_str.insert(p);
	}
	map<string, int>::iterator iter;
	for (int i = 0; i < N; i++)
	{
		iter = m_str.find(n_str[i]);
		if (iter != m_str.end()) {
			cnt++;
			temp_store[i] = true;
		}
	}
	cout << cnt << '\n';
	for (int i = 0; i < N; i++)
	{
		if (temp_store[i] == true) 
			cout << n_str[i] << '\n';	
	}

	delete[]temp_store;
	delete[]n_str;
	m_str.clear();
	return 0;
}
