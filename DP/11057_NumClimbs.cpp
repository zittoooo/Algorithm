// 오르막 수
#include <iostream>
using namespace std;
long long d[1001][10], res;
int n;

int main()
{
    cin >> n;
    for (int i = 0; i <= 9; i++)
        d[1][i] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9 ; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                d[i][j] += d[i-1][k];
                //d[i][j] %= 10007;  // 여기도 상관없음
            }
            d[i][j] %= 10007;
        }
    }
    for (int i = 0 ; i <= 9 ; i++)
        res += d[n][i];
    cout << res % 10007;
}