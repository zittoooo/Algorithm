#include <iostream>

using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int freq[26] = {0};
	string s;

	cin >> s;
	for (auto e : s)
	{
		freq[e - 'a']++;
	}
	for (auto c : freq)
		cout << c << ' ';
}
