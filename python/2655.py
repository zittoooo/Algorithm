n = int(input())
bricks = [[0,0,0,0]]  # index를 1부터 시작하기 위한 의미없는 0번째 리스트

for i in range(1, n+1):
    area, height, weight = map(int, input().split())
    bricks.append([i,area, height, weight])
bricks.sort(key = lambda x:x[1])  # 밑면 기준 오른차순 정렬

dp = [0] * (n+1)  # 현재 벽돌까지 최대 높이 저장

for i in range(1, n+1):  # i 현재 벽돌
    for j in range(i):   # j 이전 벽돌들
        if bricks[i][3] > bricks[j][3]:  # 현재 벽돌이 이전 벽돌보다 무거우면
            dp[i] = max(dp[j] + bricks[i][2], dp[i])  # 최대 높이 저장 
max_height = max(dp)
idx = dp.index(max_height)

result = []  # 결과를 담을 리스트

while idx != 0:
    if max_height == dp[idx]:
        result.append(bricks[idx][0])
        max_height -= bricks[idx][2]
    idx -= 1
    
print(len(result))
[print(i) for i in result[::-1]]
