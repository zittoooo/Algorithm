#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <string.h>
using namespace std;
int N, M, wall; // 세로 가로 벽
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int map[10][10];
int wallmap[10][10];
int vis[10][10];  // 바이러스 퍼질때
int wallvis[10][10]; // 벽세울때
int cnt, mx;
queue<pair<int ,int> > Q;

void virus()
{
    while (!Q.empty())
    {
        pair<int ,int> cur = Q.front(); Q.pop();
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
        }
    }
    for (int i =  0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            vis[i][j] = 0;          // vis초기화
            if (wallmap[i][j] == 3)
                wallmap[i][j] = 0;  // 바이러스 퍼진부분 초기화
            if (wallmap[i][j] == 2)  // 실제 바이러스 다시 큐에 넣기
                Q.push({i,j});
        }
    }
    mx = max(mx, cnt);
    return ;
}

void makewall(int y, int x)
{
    if (wall == 3)
    {
        virus();
        cnt = 0;
        return ;
    }
    
    for (int i =  0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (wallmap[i][j] == 0 && wallvis[i][j] == 0)
            {
                wallmap[i][j] = 1;
                wallvis[i][j] = 1;
                ++wall;
                makewall(i, j);
                wallmap[i][j] = 0;
                wallvis[i][j] = 0;
                --wall;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
                Q.push({i,j});
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
                wallvis[i][j] = 1;
                makewall(i, j);
                wallmap[i][j] = 0;
                wallvis[i][j] = 0;
                --wall;
            }
        }
    }
    cout << mx;
}