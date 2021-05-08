#include <iostream>
#include <algorithm>
using namespace std;
int n, tri[500][500];
int d[500][500], mx;

int main()
{
	cin >> n;
	for (int i = 0 ; i < n; i++)
		for (int j = 0; j <= i ; j++)
			cin >> tri[i][j];

	d[0][0] = tri[0][0];
	for (int i = 1; i < n ; i++)
	{
		for (int j = 0 ; j <= i ; j++)
		{
			if (j == 0)
				d[i][j] = d[i-1][j] + tri[i][j];
			else if (i == j)
				d[i][j] = d[i-1][j-1] + tri[i][j];
			else
				d[i][j] = max(d[i-1][j-1] , d[i-1][j]) + tri[i][j];
			if (i == n-1)
				mx = max(mx, d[i][j]);
		}
	}
	cout << mx;
}
