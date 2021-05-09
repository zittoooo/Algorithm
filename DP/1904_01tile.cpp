#include <iostream>
using namespace std;
int N;
int d[1000005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= 3; i++)
		d[i] = i;
	for (int i = 4; i <= N; i++)
			d[i] = (d[i-1] + d[i-2]) % 15746;
	cout << d[N] % 15746;
}
