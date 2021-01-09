// 캔디팡
#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second
int res;
int cnt;
int cur_num;
int board[7][7];
int vis[7][7];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            cin >> board[i][j];

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            queue<pair<int, int>> Q;
            cnt = 1;
            Q.push({i,j});
            cur_num = board[i][j];
            vis[i][j] = 1;
            while (!Q.empty())
            {
                auto cur = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= 7 || ny < 0 || ny >= 7) continue;
                    if (cur_num != board[nx][ny] || vis[nx][ny]) continue;
                    cnt++;
                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            if (cnt >= 3) res++;
        }
    }
    cout << res;
}