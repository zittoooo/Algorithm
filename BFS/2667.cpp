// 단지번호붙이기
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string board[25];
int vis[25][25];
int arr[25];
int cnt;
queue<pair<int,int>> Q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k = 0;
    cin >> n;
    for (int i = 0; i < n ; i++)
        cin >> board[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '1' && vis[i][j] == 0)
            {
                cnt = 1;
                Q.push({i,j});
                vis[i][j] = 1;
                while (!Q.empty())
                {
                    pair<int,int> cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (board[nx][ny] == '0' || vis[nx][ny]) continue;
                        cnt++;
                        Q.push({nx,ny});
                        vis[nx][ny] = 1;
                    }
                }
                arr[k] = cnt;
                k++;
            }
        }
    }
    sort(arr, arr + k);
    cout << k << '\n';   
    for (int i = 0; i < k; i++)
        cout << arr[i] << '\n';
}