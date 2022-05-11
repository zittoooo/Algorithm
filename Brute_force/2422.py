n, m = map(int, input().split())

combi = [[False] * (210) for _ in range(210)]

for _ in range(m):
    a, b = map(int, input().split())
    combi[a][b] = True
    combi[b][a] = True

ans = 0
for i in range(1, n+1):
    for j in range(i + 1, n+1):
        for k in range(j + 1, n+1):
            if combi[i][j] or combi[i][k] or combi[j][k]:
                continue
            # print(i, j, k)
            ans += 1
print(ans)
