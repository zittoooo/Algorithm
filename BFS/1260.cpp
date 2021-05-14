#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int N, M, start, board[1005][1005], vis[1005];

void dfs(int start)
{
    cout << start << ' ';
    vis[start] = 1;
    for (int i = 1; i <= N; i++)
    {
        if (vis[i] || board[start][i] == 0) continue ;
        dfs(i);
    }
}

void bfs(int start)
{
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(start);
    vis[start] = 1;
    while(!Q.empty())
    {
        start = Q.front();
        cout << start << ' ';
        Q.pop();
        for (int i = 1; i <= N ; i++)
        {
            if (board[start][i] == 0 || vis[i]) continue ;
            Q.push(i);
            vis[i] = 1;
        }
    }
}

int main()
{
    int x, y;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> start;
    for (int i = 1 ;i <= M; i++)
    {
        cin >> x >> y;
        board[x][y] = board[y][x] = 1;
    }
    dfs(start);
    cout << "\n";
    bfs(start);
}