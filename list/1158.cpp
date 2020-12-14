#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	list <int> l;

	for (int i = 0; i < n; i++)
		l.push_back(i + 1);
	cout << "<";
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < k - 1; j++)
		{
			l.push_back(l.front());
			l.pop_front();
		}
		cout << l.front() << ", ";
		l.pop_front();
	}
	cout << l.front() << ">";

	return 0;
}
