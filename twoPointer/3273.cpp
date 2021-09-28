#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, x, num, res;
vector<int> v;
int main()
{
	cin >> n;
	for (int i = 0 ; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	cin >> x;
	sort(v.begin(), v.end());

	int i = 0;
	int j = v.size() -1;
	while (i < j)
	{
		if (v[i] + v[j] == x)
		{
			res++;
			i++;
			j--;
		}
		else if (v[i] + v[j] > x)
			j--;
		else if (v[i] + v[j] < x)
			i++;
	}
	cout << res;
}