// 놀이공원
#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dist[1000][1000];
int map[1000][1000];
int n, m;
queue<pair<int,int>> Q;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n ; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            dist[i][j] = -1;
        }
    Q.push({0,0});
    dist[0][0] = 0;
    while (!Q.empty())
    {
        pair<int,int> cur  = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || dist[nx][ny] >= 0) continue ;
            if (map[nx][ny] > map[cur.X][cur.Y] + 1 || map[nx][ny] < map[cur.X][cur.Y] - 1 ) continue ;
            Q.push({nx,ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }
    if (dist[n-1][m-1] == -1){
        cout << '0';
        return (0);
    }
    cout << dist[n-1][m-1] + 1;
    return (0);
}