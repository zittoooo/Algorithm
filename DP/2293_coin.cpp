#include <iostream>
using namespace std;
int n, k, coins[101];
int d[10001];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> coins[i];

    d[0] = 1;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j >= coins[i])
            {
                d[j] += d[j-coins[i]];
            }
        }
    }
    cout << d[k];
    return (0);
}
// i-1번째 경우의 수 배열에 i 번째 경우의 수 배열을 덮어 씌운다.