// 학급 편성 (Medium) 
#include <iostream>
using namespace std;
long long n, m, res;
long long d[1301][1301];

int main()
{
    cin >> n >> m;
    d[1][1] = 1;
    d[2][1] = 1;
    d[2][2] = 1;
    d[3][1] = 1;
    d[3][2] = 1;
    d[3][3] = 1;
    for (int i = 4; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i == j)
                d[i][j] = 1;
            else
            {
                for (int k = 1; k <= j; k++)
                    d[i][j] += (d[i-j][k] % 123456789);
                d[i][j] %= 123456789;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        res += (d[n][i] % 123456789);
    }
    cout << res % 123456789;
}