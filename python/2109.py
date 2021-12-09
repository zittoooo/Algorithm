import sys
import heapq
lecture = []

n = int(input())
for _ in range(n):
    lecture.append(list(map(int, sys.stdin.readline().split())))
    
lecture.sort(key=lambda x:(x[1]))
lst = []

for i in lecture:
    heapq.heappush(lst, i[0])
    if len(lst) > i[1]:
        heapq.heappop(lst)
print(sum(lst))
