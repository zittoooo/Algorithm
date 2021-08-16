#include <iostream>
#include <string>
#include <queue>

using namespace std;
int N, M;
int dis[1002][1002][2];
string map[1002];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

typedef struct pos
{
    int x;
    int y;
    int wall;
} pos;

queue<pos> q;

int bfs(void)
{
    dis[0][0][0] = 1;
    q.push({0,0,0});
    while (!q.empty())
    {
        pos cur = q.front();
        q.pop();

        if (cur.x == N-1 && cur.y == M-1) return dis[N-1][M-1][cur.wall];
        
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            int nwall = cur.wall;

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
            if (dis[nx][ny][cur.wall]) continue ; // 이미 방문한곳 건너뛰기

            if (map[nx][ny] == '0')
            {
                dis[nx][ny][cur.wall] = dis[cur.x][cur.y][cur.wall] + 1;
                q.push({nx, ny, cur.wall});
            } 
            if (map[nx][ny] == '1' && cur.wall == 0)  // 벽인데 이전까지 벽을 부신적이 없다면
            {
                dis[nx][ny][1] = dis[cur.x][cur.y][cur.wall] + 1; // 벽을 부시고 지나간다
                q.push({nx, ny, 1});
            }
        }
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N ; i++)
            cin >> map[i];
    
    cout << bfs();
}
