// 이동하기
#include <iostream>
#include <algorithm>
using namespace std;
int n , m;
int map[1005][1005];
int sum;
int d[1005][1005];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n ; i++)
        for (int j = 0; j < m; j ++)
            cin >> map[i][j];

    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0) d[i][j] = map[0][0];
            else if (i == 0) d[i][j] = d[i][j-1] + map[i][j];
            else if (j == 0) d[i][j] = d[i-1][j] + map[i][j];
            else
            {
                d[i][j] = max(d[i-1][j-1], d[i-1][j]);
                d[i][j] = max(d[i][j], d[i][j-1]) + map[i][j];
            }
        }
    }
    cout << d[n-1][m-1];
}