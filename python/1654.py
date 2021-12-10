import sys

input = sys.stdin.readline
k, n = map(int, input().split())
lenCable = []
for _ in range(k):
    lenCable.append(int(input()))
lenCable.sort()

start = 1  # 최소 길이
end = max(lenCable)  # 최대 길이

while start <= end:
    cnt = 0
    mid = (start + end) // 2   # 몫
    
    for cable in lenCable:
        cnt += cable // mid
    if cnt >= n: # 목표 n개 보다 많이 잘라지면 자르는 최소 길이를 증가시킴
        start = mid + 1
    else:
        end = mid - 1
print(end)
