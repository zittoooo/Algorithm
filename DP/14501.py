# 뒤쪽 날짜부터 거꾸로 확인하는 방식으로 접근하기
n = int(input())
t = [] # 상담 기간
p = [] # 상담 금액
d = [0] * (n+1)
mx = 0

for _ in range(n):
    x, y = map(int, input().split())
    t.append(x)
    p.append(y)
    
for i in range(n-1, -1, -1): 
    # i - 현재 상담 / time - 현재 상담 끝나고
    time = t[i] + i
    
    # 상담이 기간 안에 끝나는 경우
    if time <= n:
        d[i] = max(p[i] + d[time], mx)
        mx = d[i]
    else:
        d[i] = mx
# print(d)
print(mx)
