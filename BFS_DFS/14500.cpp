#include <iostream>
#include <algorithm>
using namespace std;

int map[501][501];
bool vis[501][501];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N ,M, MAX;

// ***
//  *
void findException(int i , int j)
{
    int sum = 0;
    // ㅜ
    if (i >= 0 && i + 1 < N && j >= 0 && j + 2 < M){
        sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+1];
        MAX = max(MAX, sum);
    }
    // ㅏ
    if (i >= 0 && i+2 < N && j >= 0 && j+1 < M) {
        sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+1][j+1];
        MAX = max(MAX, sum);
    }
    // ㅗ
    if (i - 1 >= 0 && i < N && j >= 0 && j + 2 < M) {
        sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i-1][j+1];
        MAX = max(MAX, sum);
    }
    // ㅓ
    if (i - 1 >= 0 && i + 1 < N && j >= 0 && j + 1 < M) {
        sum = map[i][j] + map[i][j+1] + map[i-1][j+1] + map[i+1][j+1];
            MAX = max(MAX, sum);
    }
}

void findNormal(int size, int sum, int i, int j)
{
    if (size == 3)
    {
        MAX = max(MAX, sum);
        return ;
    }
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
        if (vis[nx][ny]) continue ;
        vis[nx][ny] = true;
        findNormal(size + 1, sum + map[nx][ny], nx, ny);
        vis[nx][ny] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0 ; i < N ; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            findException(i, j);
            vis[i][j] = true;
            findNormal(0, map[i][j], i, j);
            vis[i][j] = false;
        }
    }
    cout << MAX;
}

/*

***
 *
이 모양은 예외

*/