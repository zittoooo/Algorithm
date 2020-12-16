#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> dq;
	int N, num;
	string input;

	cin >> N;
	while (N--)
	{
		cin >> input;
		if (input == "push_front")
		{
			cin >> num;
			dq.push_front(num);
		}
		else if (input == "push_back")
		{
			cin >> num;
			dq.push_back(num);
		}
		else if (input == "pop_front")
		{
			if (dq.empty())
				cout << "-1" << '\n';
			else
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (input == "pop_back")
		{
			if (dq.empty())
				cout << "-1" << '\n';
			else
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (input == "size")
			cout << dq.size() << '\n';
		else if (input == "empty")
			cout << dq.empty() << '\n';
		else if (input == "front")
		{
			if (dq.empty())
				cout << "-1" << '\n';
			else
				cout << dq.front() << '\n';
		}
		else if (input == "back")
		{
			if (dq.empty())
				cout << "-1" << '\n';
			else
				cout << dq.back() << '\n';
		}
	}
}
