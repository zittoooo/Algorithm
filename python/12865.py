n, k = map(int, input().split())
thing = [[0,0]]
for _ in range(n):
    thing.append(list(map(int, input().split())))
dp = [[0 for _ in range(k+1)] for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, k+1):
        weight = thing[i][0]
        value = thing[i][1]
        
        if j < weight:  # 배낭의 허용 무게보다 넣을 물건의 무게가 더 크다면 넣지 않는다.
            dp[i][j] = dp[i-1][j]

				# 1) 새로 넣을 물건의 무게만큼 배낭에서 뺀다. 그리고 현재 물건을 넣는다.
			  # 2) 물건을 넣지않고 이전 배낭 그대로 가지고 간다.
        else:
            dp[i][j] = max(dp[i-1][j - weight] + value, dp[i-1][j])

print(dp[n][k])
