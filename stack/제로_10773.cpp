#include <iostream>
#include <stack>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int K, num, ans;
	ans = 0;
	stack<int> s;

	cin >> K;
	while (K--)
	{
		cin >> num;
		if (num == 0)
			s.pop();
		else
			s.push(num);
	}
	while (!s.empty())
	{
		ans += s.top();
		s.pop();
	}
	cout << ans << '\n';
}
