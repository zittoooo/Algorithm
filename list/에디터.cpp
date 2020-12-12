#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
 	cin.tie(0);

	list<char> L;
	string str;
	int count;

	cin >> str;
	cin >> count;

	for (auto c : str) L.push_back(c);
	auto cursor = L.end();

	while (count--)
	{
		char op;
		cin >> op;
		if (op == 'L')
		{
			if (cursor != L.begin())
				cursor--;
		}
		else if (op == 'D')
		{
			if (cursor != L.end())
				cursor++;
		}
		else if (op == 'B')
		{
			if (cursor != L.begin())
			{
				cursor--;
				cursor = L.erase(cursor);
			}

		}
		else {  // P
			char ch;
			cin >> ch;
			L.insert(cursor, ch);
		}
	}

	for(auto e : L)
		cout << e;
}
