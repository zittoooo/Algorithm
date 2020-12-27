//탈출 
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int R, C;
string map[50];
int dist1[50][50]; // 물의 전파 시간
int dist2[50][50]; // 고슴도치의 이동시간
queue<pair<int, int>> Q1;
queue<pair<int, int>> Q2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        cin >> map[i];
        fill(dist1[i], dist1[i] + C, -1);
        fill(dist2[i], dist2[i] + C, -1);
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (map[i][j] == '*')
            {
                dist1[i][j] = 0;
                dist2[i][j] = 0;
                Q1.push({i,j});
            }
            if (map[i][j] == 'S')
            {
                dist2[i][j] = 0;
                Q2.push({i,j});
            }
        }
    }
    while (!Q1.empty()) // 물
    {
        auto cur = Q1.front(); Q1.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0|| nx>= R|| ny < 0 || ny >= C) continue;
            if (dist1[nx][ny] >= 0 || map[nx][ny] == 'X' || map[nx][ny] == 'D') continue;
            Q1.push({nx,ny});
            dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
        }
    }
    while (!Q2.empty())
    {
        auto cur = Q2.front(); Q2.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0|| nx>= R|| ny < 0 || ny >= C) continue;
            if (dist2[nx][ny] == -1 && map[nx][ny] == 'D') // 탈출 
            {
                cout << dist2[cur.X][cur.Y]+1;
                return (0);
            }
            if (dist2[nx][ny] >= 0 || map[nx][ny] == 'X' || map[nx][ny] == '*'){continue;}
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) {continue;}
            Q2.push({nx,ny});
            dist2[nx][ny]  = dist2[cur.X][cur.Y] + 1;
        }
    }
    cout << "KAKTUS";
}