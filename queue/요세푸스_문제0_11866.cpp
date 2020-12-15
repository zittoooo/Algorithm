#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> Q;
	int N, K;
	cin >> N;
	cin >> K;

	for (int i = 0; i < N; i++)
		Q.push(i + 1);
	cout << '<';
	while (N--)
	{
		for (int j = 0; j < K -1; j++)
		{
			Q.push(Q.front());
			Q.pop();
		}
		if (Q.size() != 1)
			cout << Q.front() << ", " ;
		else
			cout << Q.front();
		Q.pop();
	}
	cout << '>' << '\n';
}
