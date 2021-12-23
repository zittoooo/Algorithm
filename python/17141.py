import sys
from collections import deque
from itertools import combinations

virus_list = []
used = [0] * 10
selected = []
dx = [0, 1 ,0 ,-1]
dy = [-1, 0, 1, 0]
mx = 0
res = 2147483647

n, m = map(int, input().split())
board =[list(map(int, sys.stdin.readline().split())) for _ in range(n)]

for i in range(n):
    for j in range(n):
        if board[i][j] == 2:
            virus_list.append([i,j])  # 바이러스를 놓을 수 있는 곳 저장


def spread(virus):
    global res
    mx = 1
    q = deque()
    dist = [[0] * n for _ in range(n)]
    for selected in virus:
        q.append(selected)
        dist[selected[0]][selected[1]] = 1
        
    while q:
        curX, curY = q.popleft();
        for dir in range(4):
            nx = curX + dx[dir]
            ny = curY + dy[dir]
            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            if board[nx][ny] == 1 or dist[nx][ny] :
                continue
            q.append([nx,ny])
            dist[nx][ny] = dist[curX][curY] + 1
            mx = max(dist[nx][ny], mx)
    for i in range(n):
        for j in range(n):
            if board[i][j] == 0 and dist[i][j] == 0:  # 빈칸인데 바이러스를 퍼뜨리지 못한 경우 그냥 return
                return
    res = min(res, mx-1)


def DFS(depth):
    for virus in list(combinations(virus_list, m)):  # 바이러스 리스트에서 m개를 뽑아 바이러스를 퍼뜨리기
        spread(virus)

DFS(0)

if res == 2147483647:   # res가 한번도 갱신된적없이 그대로이면 어떤 경우에도 바이러스를 퍼뜨릴 수 없다는 뜻이다.
    print(-1)
else:
    print(res)
