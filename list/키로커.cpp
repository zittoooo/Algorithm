#include <bits/stdc++.h>
using namespace std;
using namespace std;
list<char> L;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;

	cin >> num;
	while (num--)
	{
		list<char>::iterator it = L.end();
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '<')
			{
				if (it == L.begin())
					continue;
				it--;
			}
			else if (str[i] == '>')
			{
				if (it == L.end())
					continue;
				it++;
			}
			else if (str[i] == '-')
			{
				if (it == L.begin())
					continue;
				it = L.erase(--it);
			}
			else
				L.insert(it, str[i]);
		}
		for (auto e : L)
			cout << e;
		cout << '\n';
		L.clear();
	}
}
