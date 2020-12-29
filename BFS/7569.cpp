// 토마토
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int w, h, H; // 가로 세로 쌓는 칸
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int map[100][100][100];
int dist[100][100][100];
queue<pair<pair<int, int>, int>> Q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> w >> h >> H;

    for (int i = 0; i < H; i++){
        for (int j = 0; j < h; j++){
            for (int k = 0; k < w; k++){
                cin >> map[i][j][k];
                if (map[i][j][k] == 1){  // 익은 토마토
                    Q.push({{j, k}, i});
                }
                if (map[i][j][k] == 0)  // 익지 않은 토마토
                    dist[i][j][k] = -1;
            }
        }
    }
    while (!Q.empty())
    {
        pair<pair<int,int>,int> cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 6; dir++)
        {
            int nx = cur.first.X + dx[dir];
            int ny = cur.first.Y + dy[dir];
            int nz = cur.second + dz[dir];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w || nz < 0 || nz >= H) continue;
            if (dist[nz][nx][ny] >= 0 || map[nz][nx][ny] == -1) continue ;  // 이미 익음 / 토마토가 들어있지 않음
            dist[nz][nx][ny] = dist[cur.second][cur.first.X][cur.first.Y] + 1;
            Q.push({{nx,ny}, nz});
   
        }
    }

    int mx = 0;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < h; j++){
            for (int k = 0; k < w; k++){
                if (dist[i][j][k] == -1)
                {
                    cout << "-1";
                    return (0);
                }
                mx = max(mx, dist[i][j][k]);
            }
        }
    }
    cout << mx;
}