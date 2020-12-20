#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int loop, N, M, importance;
	cin >> loop;
	while (loop--)
	{
		int count = 1;
		cin >> N; // 문서의 개수  4
		cin >> M; // 궁금한 파일이 큐에 몇번째에 놓여 있는지 2
		queue<pair<int, int>> Q;
		priority_queue<int> pq; // 우선순위 큐  3 2 1
		for (int i = 0; i < N; i++){
			cin >> importance;  // 4
			Q.push({i, importance});  //  {1,2}  {2,3} {3, 4}  {0,1}
			pq.push(importance); //4 3 2 1
		}
		while (!Q.empty()){
			pair<int, int> cur = Q.front();  // cur == {0, 1}
			int x = cur.first;   // 0
			int y = cur.second;  // 1
			if (y != pq.top()) //
			{
				Q.push(cur);
				Q.pop();
			}
			else if (y == pq.top() && x != M){
				Q.pop();
				pq.pop();
				count++;
			}
			else if (x == M){
				cout << count << '\n';
				break ;
			}
		}
	}
}
