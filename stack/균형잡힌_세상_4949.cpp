#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	int flag = 0;

	while (1)
	{
		flag = 0;
		stack<char> s;
		getline(cin, str);
		if (str.at(0) == '.')
			break;

		for (int i = 0; i < str.length(); i++)
		{
			if (i == 1)
				if (str.at(i) == '.')
					break;
			if (str.at(i) == '(' || str.at(i) == '[')
				s.push(str.at(i));
			else if (str.at(i) == ')')
			{
				if (s.size() && s.top() == '(')
					s.pop();
				else
				{
					flag = 1;
					break;
				}
			}
			else if (str.at(i) == ']')
			{
				if (s.size() && s.top() == '[')
					s.pop();
				else
				{
					flag = 1;
					break;
				}
			}
		}
		if (s.empty() && flag == 0)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}
}
