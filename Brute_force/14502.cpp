#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
int N, M, wall; // 세로 가로 벽
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int map[10][10];
int wallmap[10][10];
int vis[10][10];
int cnt, mx;

void printMap()
{
    for (int i =  0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << wallmap[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    return ;
}

void virus()
{
    pair<int ,int> cur = Q.front(); Q.pop();
    while (!Q.empty())
    {
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
            if (wallmap[nx][ny] == 0 && vis[nx][ny] == 0)
            {
                wallmap[nx][ny] = 3;
                Q.push({nx,ny});
                vis[nx][ny] = 1;
            }
        }
    }
    for (int i =  0; i < N; i++)  // 안전영역 구하기
    {
        for (int j = 0; j < M; j++)
        {
            if (wallmap[i][j] == 0)
                cnt++;
            if (wallmap[i][j] == 3)
                wallmap[i][j] = 0;
        }
    }
    for (int i =  0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (wallmap[i][j] == 3)
                wallmap[i][j] = 0;
        }
    }
    mx = max(mx, cnt);
}

void makewall(int y, int x)
{
    if (wall == 3)
    {
        // virus();
        cnt = 0;
        return ;
    }
    for (int i =  y; i < N; i++)
    {
        for (int j = x; j < M; j++)
        {
            if (wallmap[i][j] == 0 && wall < 3)
            {
                wallmap[i][j] = 1;
                ++wall;
                makewall(i, j);
                wallmap[i][j] = 0;
                --wall;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    queue<pair<int ,int> > Q;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                Q.push({i,j});
                
            }
        }
    }
    memcpy(wallmap, map, sizeof(map));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (wallmap[i][j] == 0)
            {
                wallmap[i][j] = 1;
                ++wall;
                makewall(i, j);
                wallmap[i][j] = 0;
                --wall;
            }
        }
    }
    cout << mx;
}