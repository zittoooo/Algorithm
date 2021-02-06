/*
메모리를 많이 잡아 먹는다.
4 x (101 + 101 x 10001) = 4,040,808Bytes = 약 3.85 MB + @
*/

#include <iostream>
using namespace std;
int n, k, a[101];
int d[101][10001];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1 ; i <= n ; i++)
    {
        d[i][0] = 1;
        for (int j = 1; j <= k; j++)
        {
            if (j >= a[i])
                d[i][j] = d[i-1][j] + d[i][j-a[i]];
            else
                d[i][j] = d[i-1][j];
        }
    }
    cout << d[n][k];
    return (0);
}

