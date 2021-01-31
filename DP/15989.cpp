// 1, 2, 3 더하기 4
#include <iostream>
using namespace std;
int T, n;
int d[10005][4];

int main()
{
    cin >> T;
    d[1][1] = 1;
    d[2][1] = 1;
    d[2][2] = 1;
    d[3][1] = 1;
    d[3][2] = 1;
    d[3][3] = 1;
    for (int i = 4; i <= 10000 ; i++)
    {
        d[i][1] = 1;
        d[i][2] = d[i-2][1] + d[i-2][2];
        d[i][3] = d[i-3][1] + d[i-3][2] + d[i-3][3];
    }
    while (T--)
    {
        cin >> n;
        printf("%d\n", d[n][1] + d[n][2] + d[n][3]);
    }
}