#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <limits.h>
#include <algorithm>
using namespace std;
int n, m; // n : 연구소 크기, m : 바이스러 개수
int map[51][51]; // 0 빈칸, 1 벽, 2 바이러스
int dist[51][51];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0 ,1, 0};
vector<pair<int ,int> > virus;
vector<pair<int, int> > selected;
int ans = INT_MAX;
bool used[10];
queue<pair<int ,int> > q;

void spread()
{
    while(!q.empty())
        q.pop();
    memset(dist, 0 , sizeof(dist));
    int mx = 1;

    for(int i = 0; i < selected.size(); i++)
    {
        q.push(selected[i]);
        dist[selected[i].first][selected[i].second] = 1;
    }
    while(!q.empty())
    {
        pair<int ,int> cur = q.front();
        q.pop();

        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue ;
            if(dist[nx][ny] || map[nx][ny] == 1) continue ;
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            if(map[nx][ny] == 0)
                mx = max(mx, dist[nx][ny]);
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(map[i][j] == 0 && dist[i][j] == 0)
                return ;
    ans = min(ans, mx-1);
}

void DFS(int depth)
{
    if(selected.size() == m)
    {
        spread();
        return ;
    }

    for(int i = depth; i < virus.size(); i++)
    {
        if(!used[i])
        {
            selected.push_back(virus[i]);
            used[i] = 1;
            DFS(i + 1);
            used[i] = 0;
            selected.pop_back();
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n ;i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 2)
                virus.push_back({i,j});
        }
    }
    DFS(0);
    if(ans == INT_MAX)
        cout << -1;
    else
        cout << ans;
}