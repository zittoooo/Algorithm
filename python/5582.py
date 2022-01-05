answer = 0
s1, s2 = input(), input()

dp = [[0] * (len(s2) + 1) for _ in range(len(s1) + 1)]

for i in range(1, len(s1) + 1):
    for j in range(1, len(s2) + 1):
        if s1[i - 1] == s2[j - 1]:   # 같은 문자를 만나면 이전까지의 공통 부분 문자열 길이 + 1을 저장한다
            dp[i][j] = dp[i-1][j-1] + 1
            answer = max(dp[i][j], answer)
            
print(answer)
