#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
int n, res = 0;
char map[7][7];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
vector<pair<int, int> > teacher;
vector<pair<int ,int> > obstacle;

void print_map()
{
    cout << "\n";
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < n ; j++)
        { 
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    return ;
}

int gamsi()
{
    for(pair<int ,int> t : teacher)
    {
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = t.first;
            int ny = t.second;
            while (1)
            {
                nx += dx[dir];
                ny += dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] == 'O') break ;
                if(map[nx][ny] == 'S')
                {
                    return 0; // 감시 피할 수 없음
                }
            }
        }
    }
    return 1; // 감시 피함
}

void make_obstacle(int cur, int cnt)
{
    if(cnt == 3)
    {
        res += gamsi();
        return ;
    }

    for(int i = cur; i < obstacle.size(); i++)
    {
        int x = obstacle[i].first;
        int y = obstacle[i].second;

        map[x][y] = 'O';
        make_obstacle(i+1, cnt+1);
        map[x][y] = 'X';
    }

}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 'T')
                teacher.push_back({i,j});
            else if(map[i][j] == 'X')
                obstacle.push_back({i,j});
        }
    }
    make_obstacle(0,0);

    if(res == 0)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}