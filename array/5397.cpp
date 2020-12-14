#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<char> L;
	list<char>::iterator it;
	int num;
	string str;
	int i = 0;

	cin >> num;
	while (num--)
	{
		cin >> str;
		L.clear();
		it = L.end();
		for (int i = 0; i < str.length() ; i++)
		{
			if (str[i] == '>')
			{
				if (it != L.end())
					it++;
			}
			else if (str[i] == '<')
			{
				if (it != L.begin())
					it--;
			}
			else if (str[i] == '-')
			{
				if (it != L.begin())
					it = L.erase(--it);
			}
			else
				L.insert(it,str[i]);
		}
		for (auto e : L)
			cout << e;
		cout << '\n';
	}
}
