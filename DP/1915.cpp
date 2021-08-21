#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int d[1005][1005];
string map[10005];

int main()
{
    int n, m, mx = 0;
    cin >> n >> m;
    for (int i = 0; i < n ; i++)
            cin >> map[i];

    for (int i = 0; i < n ; i++)
        d[i][0] = map[i][0] - '0';
    for (int i = 0; i < m; i++)
        d[0][i] = map[0][i] - '0';

    for (int i = 1; i < n ; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (map[i][j] == '1')
            {
                if (d[i-1][j-1] != 0 && d[i-1][j] != 0 && d[i][j-1] != 0)
                    d[i][j] = min(min(d[i-1][j-1], d[i-1][j]), d[i][j-1]) + 1;
                else
                    d[i][j] = 1;
            }
            else
                d[i][j] = 0;
        }
    }

    for (int i = 0; i < n ; i++)
        for (int j = 0; j < m; j++)
            mx = max(mx, d[i][j]);
    
    cout << mx * mx;
    return (0);
}