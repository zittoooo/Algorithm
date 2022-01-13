#include <bits/stdc++.h>
using namespace std;

int dist[101][101];
string m[101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int w, h;
queue<pair<int, int> > q;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> w >> h;
    for (int i = 0; i < h; i++)
    {
        cin >> m[i];
        fill(dist[i], dist[i] + w, -1);
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (m[i][j] == 'C')
            {
                q.push({i,j});
                dist[i][j] = 0;
                break;
            }
        }
        if (q.size() == 1)
            break;
    }
    
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            
            while (nx >= 0 && nx < h && ny >= 0 && ny < w)
            {
                if (m[nx][ny] == '*') break;
                if (dist[nx][ny] == -1)
                {
                    q.push({nx,ny});
                    dist[nx][ny] = dist[cur.first][cur.second] + 1;
                }
                nx += dx[dir];
                ny += dy[dir];
            }
        }
    }
    
    int ans = 0;
    for (int i = 0 ; i < h; i++)
    {
        for (int j = 0 ; j < w ; j++)
        {
//             cout << dist[i][j] << " ";
            if (m[i][j] == 'C')
                ans = max(ans, dist[i][j]);
        }
//         cout << "\n";
    }
    cout << ans-1;
}
