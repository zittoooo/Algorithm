//양   .빈곳 # 울타리 o양 v 늑대
#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
string field[250];
int vis[250][250];
int sh1, wo1, sh2, wo2;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int R, C;
int cnt;
queue<pair<int ,int>> Q;
void    bfs(int i, int j)
{
    cnt++;
    vis[i][j] = 1;
    Q.push({i ,j});
    sh1 = 0; wo1 = 0;
    while (!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        if (field[cur.first][cur.second] == 'v')
            wo1++;
        else if (field[cur.first][cur.second] == 'o')
            sh1++;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0|| nx >= R || ny < 0 || ny >= C) continue ;
            if (vis[nx][ny] || field[nx][ny] == '#') continue ;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
    if (sh1 > wo1) sh2 += sh1;
    else wo2 += wo1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++)
        cin >> field[i];
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (vis[i][j] == 0 && field[i][j] != '#')
                bfs(i,j);
        }
    }
    cout << sh2 << " " << wo2 ;
}