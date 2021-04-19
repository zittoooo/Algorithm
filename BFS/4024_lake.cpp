#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
char board[102][102];
int vis[102][102];
int w, h;

int main()
{
    int num = 0;
    queue<pair<int ,int> > Q;
    cin >> w >> h;
    for (int i = 0 ; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> board[i][j];

    for (int i = 0 ; i < h; i++)
    {
        for (int j = 0 ; j < w; j++)
        {
            if (vis[i][j] || board[i][j] != 'L') continue ;
            num++;
            vis[i][j] = 1;
            Q.push({i, j});
            while (!Q.empty())
            {
                pair<int ,int> cur = Q.front(); Q.pop();
                for (int dir = 0; dir < 8; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue ;
                    if (vis[nx][ny] || board[nx][ny] == '.') continue ;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    cout << num;
}