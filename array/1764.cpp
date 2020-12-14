#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<string> v1, v2, v3;

	int N, M;
	string name;

	cin >> N;
	cin >> M;
	while (N--)
	{
		cin >> name;
		v1.push_back(name);
	}
	while (M--)
	{
		cin >> name;
		v2.push_back(name);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	if (N <= M)
	{
		for (int i = 0;i < N;i++)
		{
			if (v1[i] == v2[i])
			{
				v3.push_back(v1[i]);
			}
		}

	}
	else
	{
		for (int i = 0;i < M; i++)
		{
			if (v2[i] == v1[i])
				v3.push_back(v2[i]);
		}
	}

	cout << v3.size() << "\n";
	for (auto e : v3)
		cout << e << "\n";

}
