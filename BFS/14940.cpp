// 쉬운 최단거리
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int map[1000][1000];
int dist[1000][1000];
int n, m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> Q;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + m, -1);
    for (int i = 0; i< n; i++)
    {
        for (int j = 0; j < m; j++){
            cin >>map[i][j];
            if (map[i][j] == 2){
                Q.push({i,j});
                dist[i][j] = 0;
            }
            if (map[i][j] == 0)
                dist[i][j] = 0;
        }
    }
    while (!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4;dir ++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y +dy[dir];
            if (nx < 0 || nx >= n || ny <0 || ny >= m) continue;
            if (dist[nx][ny] >= 0 || map[nx][ny] == 0) continue;
            Q.push({nx,ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;       
        }
    }
    for (int i = 0; i< n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << dist[i][j] << " ";
        cout << "\n";
    }
}