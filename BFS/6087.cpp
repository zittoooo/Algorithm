//레이저 통신   
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int dist[101][101];
string map[101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int w, h;
queue<pair<int,int>> Q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> h;
    for (int i = 0; i < h; i++)
        cin >> map[i];
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if (map[i][j] == 'C')
            {
                dist[i][j] = 0;
                Q.push({i,j});
                break ;
            }
        }
        if (Q.size()== 1)
            break;
    }
    for (int i = 0; i < h; i++)
        fill(dist[i], dist[i] + w, -1);
    while (!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            while (nx >= 0 && nx < h && ny >= 0 && ny < w)
            {
                if (map[nx][ny] == '*') break;
                if (dist[nx][ny] == -1)
                {
                    dist[nx][ny] = dist[cur.first][cur.second] + 1;
                    Q.push({nx,ny});
                }
                nx += dx[dir];
                ny += dy[dir];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (map[i][j] == 'C')
                ans = max(ans, dist[i][j]);
    cout << ans << '\n';
}
