#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <memory.h>
using namespace std;
int N, map[100][100], vis[100][100], mx, ans;
int dx[4] = {-1, 0 ,1 ,0};
int dy[4] = {0, -1, 0 ,1};
int water;

void solve(int water)
{
    queue<pair<int, int> > Q;
    int safe = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] > water && vis[i][j] == 0) // 안전영역
            {
                safe++;
                Q.push({i, j});
                vis[i][j] = 1;
                while (!Q.empty())
                {
                    pair<int, int> cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue ;
                        if (map[nx][ny] <= water || vis[nx][ny] == 1) continue;
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
    }
    ans = max(ans, safe);
}

int main()
{
    cin >> N;
    for (int i =0 ; i< N; i++)
        for (int j = 0 ; j < N; j++)
        {
            cin >> map[i][j];
            mx = max(mx, map[i][j]);
        }
    for (water = 1; water < mx ; water++)
    {
        memset(vis, 0, sizeof(vis));
        solve(water);
    }
    if (ans == 0)  // 아무  지역도 물에 잠기지 않을 때
        cout << 1;
    else
        cout << ans;
}