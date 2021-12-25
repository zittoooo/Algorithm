from collections import deque
import sys
empty = []
virusList = []

used = [False] * 64
queue = deque()
res = 0

dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]

def virus():
    global n,m, res
    cboard = [line[:] for line in board]  # board 복사

    for v in virusList:  # 바이러스위치 큐에 넣기
        queue.append(v)
    while queue:
        curX, curY = queue.popleft()
        for dir in range(4):
            nx = curX + dx[dir]
            ny = curY + dy[dir]
            if nx >= 0 and nx < n and ny >= 0 and ny < m:
                if cboard[nx][ny] == 0:   # 바이러스가 빈 공간으로 갈수 있다
                    queue.append([nx,ny])
                    cboard[nx][ny] = 2
            
    cnt = 0
    for line in cboard:
        cnt += line.count(0)  # 빈공간 개수 세기
    res = max(res, cnt)


def make_wall(depth, i):
    global res
    if depth == 3:
        virus()
        return
    for wall in range(i, len(empty)):
        if not used[wall]:
            curX, curY = empty[wall]
            used[wall] = 1
            board[curX][curY] = 1
            make_wall(depth+1, wall)
            used[wall] = 0
            board[curX][curY] = 0
         
        
n, m = map(int, input().split())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

vis = [[0] * m for _ in range(n)]
for i in range(n):
    for j in range(m):
        if board[i][j] == 0:
            empty.append([i,j])
        elif board[i][j] == 2:
            virusList.append([i,j])

make_wall(0, 0)
print(res)
