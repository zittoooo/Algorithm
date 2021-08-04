#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int n, m;
int r, c, d;
int cnt;
int map[51][51];  // 1 - 벽, 2 - 청소함
int lx[4] = {0, -1, 0, 1};
int ly[4] = {-1, 0, 1, 0};
int bx[4] = {1, 0, -1, 0};
int by[4] = {0, -1, 0, 1};


int is_wall(int r, int c)
{
    for (int i = 0; i < 4; i++)
    {
        if (map[r + lx[i]][c + ly[i]] == 0)
            return (0);
    }
    return (1);
}
void change_d(int *d)
{
    (*d)--;
    if (*d < 0)
        *d = 3;
}

int main()
{
    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i < n ; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    map[r][c] = 2;
    cnt++;
    while (1)
    {
        if (is_wall(r, c) == 1) // 상하좌우 갈곳이 없음
        {
            if (map[r + bx[d]][c + by[d]] == 1) // 후진하면 벽
                break ;
            else
            {
                r += bx[d];
                c += by[d];
            }
        }
        else
        {
            if (map[r + lx[d]][c + ly[d]] == 0)
            {
                r += lx[d];
                c += ly[d];
                map[r][c] = 2;
                cnt++;
            }
            change_d(&d); 
        }
    }
    cout << cnt;
    return (0);
}
