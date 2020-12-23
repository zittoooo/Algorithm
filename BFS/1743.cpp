#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int vis[100][100];
int board[100][100];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int N, M, K, x, y;
int main()
{
	cin >> N >> M >> K;
	while (K--)
	{
		cin >> x >> y;
		board[x - 1][y - 1] = 1;
	}
	int mx = 0;
	int size = 0;
	queue<pair<int, int>> Q;
	for (int i = 0; i < N ; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (vis[i][j] == 0 && board[i][j] == 1)
			{
				size = 1;
				vis[i][j] = 1;
				Q.push({i,j});
				while (!Q.empty())
				{
					auto cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
						if (vis[nx][ny] || board[nx][ny] == 0) continue;
						vis[nx][ny] = 1;
						Q.push({nx, ny});
						size++;
					}
				}
				mx = max(mx, size);
			}
		}
	}
	cout << mx;
}
