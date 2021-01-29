// 점프
#include <iostream>
using namespace std;
int n, res;
int board[105][105];
long long dp[105][105];  // 경로의 수 저장

int main()
{
    cin >> n;
    for (int i = 0 ;i  < n ; i++)
        for (int j = 0; j < n ;j++)
            cin >> board[i][j];
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] != 0)
            {
                if (board[i][j] == 0) continue;
                if (j+board[i][j] < n) dp[i][j+board[i][j]] += dp[i][j]; // 오른쪽
                if (i+board[i][j] < n) dp[i+board[i][j]][j] += dp[i][j]; // 아래쪽
            }
        }
    }
    cout << dp[n-1][n-1];
}