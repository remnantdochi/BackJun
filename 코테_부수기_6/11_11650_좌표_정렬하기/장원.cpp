#include <iostream>
#include<algorithm>
using namespace std;

typedef struct point {
	int x;
	int y;
}Point;

bool cmp(const Point& a, const Point& b)
{
	if (a.x != b.x)
		return a.x < b.x;
	else
		return a.y < b.y;
}

int main()
{
	int N;
	cin >> N;
	Point* point = new Point[N];
	for (int i = 0; i < N; i++)
		cin >> point[i].x >> point[i].y;

	sort(point, point + N, cmp);

	for (int i = 0; i < N; i++)
		cout << point[i].x << ' ' << point[i].y << '\n';
		

	return 0;
}
