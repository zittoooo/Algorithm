import sys
from itertools import combinations

N = int(sys.stdin.readline().rstrip())
arr = []    #  전체 화단
flower = [] # 꽃 심을 수 있는 x,y

MIN = int(1e9)
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

for i in range(N):
    arr.append(list(map(int, input().split())))

for i in range(1, N-1):
    for j in range(1, N-1):
        flower.append((i, j))

for flower_comb in combinations(flower, 3):
    temp = 0
    flag = 0
    vis = [[0] * N for _ in range(N)]
    
    for flo in flower_comb:
        if vis[flo[0]][flo[1]] == 0:
            vis[flo[0]][flo[1]] = 1
            temp += arr[flo[0]][flo[1]]
        else:
            flag = 1
            break
        for dir in range(4):  # 씨앗 3개 다 뿌림
            nx = flo[0] + dx[dir]
            ny = flo[1] + dy[dir]
            if vis[nx][ny] == 0:
                vis[nx][ny] = 1
                temp += arr[nx][ny]
            else:
                flag = 1
                break
    if not flag:
        MIN = min(MIN, temp)
print(MIN)
    
