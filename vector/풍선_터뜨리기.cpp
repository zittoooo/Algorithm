#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int , int>> v;
	int N;
	int num;
	int i= 1;

	cin >> N;
	while (N--)
	{
		cin >> num;
		v.push_back({i++, num});
	}

	while (!v.empty())
	{
		cout << v.front().first << ' ';
		num = v.front().second;
		v.erase(v.begin());
		if (num > 0)
		{
			for (int i = 0;i < num - 1;i++)
			{
				v.push_back(v.front());
				v.erase(v.begin());
			}
		}
		else
		{
			for (int i = 0; i < -num; i++)
			{
				v.insert(v.begin(), v.back());
				v.pop_back();
			}
		}
	}

}

