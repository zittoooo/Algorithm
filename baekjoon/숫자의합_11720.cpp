#include <iostream>
#include <string>

using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, i = 0;
	string input;
	long long res = 0;

	cin >> N >> input;

	for (int i = 0; i < N; i++)
	{
		res += (input.at(i) - '0');
	}
	cout << res ;
}
