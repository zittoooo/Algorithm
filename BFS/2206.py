import sys
from collections import deque

# 행, 열
N, M =  map(int, sys.stdin.readline().split())
board = [list(map(int, input())) for _ in range(N)]
# print(board)
vis = [[[0] * 2 for _ in range(M)] for _ in range(N)]
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

q = deque([[0,0,0]])
vis[0][0][0] = 1

while q:
    x, y, wall = q.popleft()
    if x == N-1 and y == M-1:
        print(vis[x][y][wall])
        exit(0)
    for dir in range(4):
        nx, ny = x + dx[dir], y + dy[dir]
        if  0 <= nx < N and 0 <= ny < M and vis[nx][ny][wall] == 0:
            if board[nx][ny] == 0:
                q.append([nx, ny, wall])
                vis[nx][ny][wall] = vis[x][y][wall] + 1
            elif wall == 0 and board[nx][ny] == 1:
                q.append([nx, ny, 1])
                vis[nx][ny][1] = vis[x][y][wall] + 1
                
print(-1)
