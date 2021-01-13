// 안전 영역
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[100][100];
int vis[100][100];
int n, rain = 0, safe, board_max, res;
queue<pair<int, int>> Q;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            board_max = max(board_max, board[i][j]);
        }
    while (rain <= board_max)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] > rain && vis[i][j] == 0)
                {
                    safe++; // 안전 영역 찾음
                    Q.push({i, j});
                    vis[i][j] = 1;
                    while (!Q.empty())
                    {
                        pair<int, int> cur = Q.front(); Q.pop();
                        for (int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                            if (vis[nx][ny] || board[nx][ny] <= rain) continue;
                            Q.push({nx, ny});
                            vis[nx][ny] = 1;
                        }
                    }
                }
            }
        }
        res = max(res, safe);
        rain++;
        safe = 0;
        for(int i = 0; i < n; i++)
            fill(vis[i], vis[i]+n, 0);
    }
    cout << res;
}