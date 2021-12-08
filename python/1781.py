# 컵라면
import sys
import heapq   # min heap
cups = []
problem = []

n = int(input())
for _ in range(n):
    cups.append(list(map(int, sys.stdin.readline().split())))
cups.sort(key=lambda x:(x[0], -x[1])) # 첫 번째 요소로 오름차순/ 두 번째 요소로 내림차순 정렬
# print(cups)

ans = 0
problem =[]
for cup in cups:
    heapq.heappush(problem, cup[1])
    if cup[0] < len(problem) :
        heapq.heappop(problem)

print(sum(problem))
