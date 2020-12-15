#include <iostream>
#include <queue>

using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num, push;
	string input;
	queue<int> Q;

	cin >> num;

	while (num--)
	{
		cin >> input;
		if (input == "push")
		{
			cin >> push;
			Q.push(push);
		}
		else if (input == "pop")
		{
			if (Q.empty() == 0)
			{
				cout << Q.front() << '\n';
				Q.pop();
			}
			else
			{
				cout << -1 << '\n';
			}
		}
		else if (input == "size")
			cout << Q.size() << '\n';
		else if (input == "empty")
		{
			if (Q.empty())
				cout << "1" << '\n';
			else
				cout << "0" << '\n';

		}
		else if (input == "front")
		{
			if (Q.empty())
				cout << "-1" << '\n';
			else
				cout << Q.front() << '\n';
		}
		else if (input == "back")
		{
			if (Q.empty())
				cout << "-1" << '\n';
			else
				cout << Q.back() << '\n';
		}
	}
}
