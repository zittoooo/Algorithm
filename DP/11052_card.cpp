#include <iostream>
using namespace std;
int n;
int a[10001];
int d[1001][10001];

int main()
{
    cin >> n;
    for (int i = 1; i <= n ; i++)
        cin >> a[i];
    for (int i = 1; i <= n ; i++)
    {
        d[i][1] = a[1];
        for (int j = 2; j <= n; j++)
        {
            if (j >= i)
            {
                d[i][j] = max(d[i-1][j], d[i][j-i] + a[i]);
//               cout << d[i][j] << ' ';
            }
            else 
            {
                d[i][j] = d[i-1][j];
//                cout << d[i][j] << ' ';
            }
        }
//        cout << "\n";
    }
    cout << d[n][n];
}