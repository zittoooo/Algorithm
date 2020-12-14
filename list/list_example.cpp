#include <bits/stdc++.h>
using namespace std;

int main()
{
	list<int> L = {1, 2};
	list<int>::iterator t = L.begin();

	L.push_front(10);  // 10 1 2
	cout << *t << '\n';
	L.push_back(5); // 10 1 2 5
	L.insert(t, 6); // t가 가리키는 곳 앞에 6 삽입, 10 6 1 2 5
	t++;  // t가 가리키는 값은 2
	t = L.erase(t); // 10 6 1 5, t가 가리키는 곳은 5
	cout << *t << '\n';  // 5
	for(auto i : L) cout << i << ' ';
	cout << '\n';
	for(list<int>::iterator it = L.begin(); it != L. end(); it++)
		cout << *it << ' ';
	cout << '\n';
}
