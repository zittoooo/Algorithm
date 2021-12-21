from collections import deque
import sys
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
sq = deque()
q = deque()

R, C = map(int, input().split())
svis = [[0 for _ in range(C)] for _ in range(R)]
vis = [[0 for _ in range(C)] for _ in range(R)]
board = [sys.stdin.readline().strip() for _ in range(R)]
for i in range(R):
    for j in range(C):
        if board[i][j] == '*':
            q.append([i,j])
            vis[i][j] = 1
        elif board[i][j] == 'S':
            sq.append([i,j])
            svis[i][j] = 1

# 물 먼저
while q:
    curX, curY = q.popleft()
    for dir in range(4):
        nx = curX + dx[dir]
        ny = curY + dy[dir]
        if nx < 0 or nx >= R or ny < 0 or ny >= C:
            continue
        if board[nx][ny] == 'X' or board[nx][ny] == 'D' or vis[nx][ny] :
            continue
        q.append([nx, ny])
        vis[nx][ny] = vis[curX][curY] + 1
while sq:
    curX, curY = sq.popleft()
    for dir in range(4):
        nx = curX+dx[dir]
        ny = curY+dy[dir]
        if nx < 0 or nx >= R or ny < 0 or ny >= C:
            continue
        if board[nx][ny] == 'D':
            print(svis[curX][curY])
            exit(0)
        if board[nx][ny] == 'X' or board[nx][ny] == '*' or svis[nx][ny]:
            continue
        if vis[nx][ny] != 0 and vis[nx][ny] <= svis[curX][curY] + 1:  #물이 더 빨리 지나간곳
            continue
        sq.append([nx,ny])
        svis[nx][ny] = svis[curX][curY] + 1

print('KAKTUS')
        
