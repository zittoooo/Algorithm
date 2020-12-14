#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	int push;
	string str;
	stack<int> s;

	cin >> N;
	while (N--)
	{
		cin >> str;
		if (str.compare("push") == 0)
		{
			cin >> push;
			s.push(push);
		}
		else if (str.compare("top") == 0)
		{
			if (s.empty())
			{
				cout << "-1" << '\n';
				continue ;
			}
			cout << s.top() << '\n';
		}
		else if (str.compare("size") == 0)
			cout << s.size() << '\n';
		else if (str.compare("empty") == 0)
			cout << s.empty() << '\n';
		else if (str.compare("pop") == 0)
		{
			if (s.empty())
			{
				cout << "-1" << '\n';
				continue ;
			}
			cout << s.top() << '\n';
			s.pop();
		}
	}
}
