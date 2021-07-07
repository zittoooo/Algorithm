#include <iostream>
#include <string>
#include <utility>
#include <queue>
using namespace std;

int vis[8][8];
int dx[9] = {0, -1, 0, 1, 1, 1, 0, -1, -1};
int dy[9] = {0, -1, -1, -1, 0, 1, 1, 1, 0};
int flag;
string map[8];  // 0~7

int main()
{
    int flag = false;
    for (int i = 0; i < 8; i++)
        cin >> map[i];
    queue<pair<int,int> > Q;
    Q.push({7,0});
    Q.push({10,10});
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        if (cur.first == 0 && cur.second == 7)
        {
            flag = true;
            break;
        }
        for (int dir = 0; dir < 9; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue ;
            if (map[nx][ny] == '#') continue ;
            if (nx > 0 && map[nx-1][ny] == '#') continue ;
            Q.push({nx,ny});
        }
        if (Q.front().first == 10 && Q.front().second == 10)
        {
            Q.pop();
            Q.push({10,10});
            for (int i = 7; i >= 1; i--)  // 맵 갱신
                map[i] = map[i-1];
            map[0] = "........";
        }
    }
    if (flag == true)
        cout << 1;
    else
        cout << 0;
}