n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
dp = [[0] * m for _ in range(n)]

dp[0][0] = board[0][0]

for i in range(n):
    for j in range(m):
        if i == 0 and j == 0:
            continue
        if i == 0 and j - 1 > 0:
            dp[i][j] = dp[i][j-1] + board[i][j]
        elif j == 0 and i - 1 > 0:
            dp[i][j] = dp[i-1][j] + board[i][j]
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + board[i][j]
ans = max(map(max, dp))
print(ans)
