// 0/1 배낭 문제(Knapsack Problem)
#include <iostream>
using namespace std;
#define W first
#define V second
int n , w, mx = 0;
int d[105][10005];
pair<int,int> a[105];  // (w, v)

int main()
{
    cin >> n >> w;
    for (int i = 1 ; i <= n ; i++)
        cin >> a[i].W >> a[i].V;
    for (int j = 0 ; j <= w; j++)
        d[0][j] = 0;
    for (int i = 1 ;i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (a[i].first > j) d[i][j] = d[i-1][j];
            else
                d[i][j] = max(d[i-1][j], a[i].V + d[i-1][j - a[i].W]);
        }
    }
    cout << d[n][w];
}