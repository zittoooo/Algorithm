// 미로 탐색
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0 , -1, 0};
int N, M;
string board[100];
int dist[100][100];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> Q;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> board[i];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            dist[i][j] = -1;

    dist[0][0] = 0;
    Q.push({0,0});
    while (!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= N|| ny < 0 || ny >= M) continue;
            if (dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;
            Q.push({nx,ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }
    cout << dist[N-1][M-1] + 1;
}