#include <bits/stdc++.h>
using namespace std;

void circularNext(list<int> &li, list<int>::iterator &iter)
{
	iter =  std::next(iter) == li.end() ? li.begin() : std::next(iter);
}
list<int> lst;
list<int>::iterator iter;
int N, K;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		lst.push_back(i + 1);
	}
	iter = lst.begin();
	cin >> K;
	cout << '<';
	for (int i = 0; i < N; i++)
	{
		for (int i = 0; i < K-1; i++)
		{
			circularNext(lst, iter);
		}
		cout << *iter;
		if (i < N - 1)
			cout << ", ";
		iter = lst.erase(iter);
		if (iter == lst.end())
			iter = lst.begin();
	}
	cout << '>';
}
