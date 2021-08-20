#include <iostream>
#include <algorithm>
using namespace std;

int d[2][100000];
int map[2][100000];
int T, n;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0 ; i < 2; i++)
            for (int j = 0; j < n; j++)
                cin >> map[i][j];
            
        d[0][0] = map[0][0];
        d[1][0] = map[1][0];
        d[0][1] = map[1][0] + map[0][1];
        d[1][1] = map[0][0] + map[1][1];
        for (int i = 2; i < n ; i++)
        {
            d[0][i] = max(d[1][i-1], d[1][i-2]) + map[0][i];
            d[1][i] = max(d[0][i-1], d[0][i-2]) + map[1][i];
        }
        cout << max(d[0][n-1], d[1][n-1]) << "\n";
    }
}