//아기상어 2
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int N, M;
int board[50][50];
int dist[50][50];
int mx;
queue<pair<int, int>> Q;

int     main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N ; i++)
        for (int j = 0; j < M; j++){
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                dist[i][j] = 0;
                Q.push({i,j});
            
            }
            else 
                dist[i][j] = -1;
        }

    while (!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 8; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx<0 || nx >= N|| ny < 0 ||ny >= M || dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }

    for (int i = 0; i < N ; i++)
        for (int j = 0; j < M; j++)
            mx = max(mx, dist[i][j]);
    cout << mx;
}