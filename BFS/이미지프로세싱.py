from collections import deque
q = deque()
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


h, w = map(int, input().split())

board = []

for i in range(h):
    board.append(list(map(int, input().split())))
# print(board)

Q = int(input())
for _ in range(Q):
    i, j, c = map(int, input().split())
    i -= 1
    j -= 1
    
    vis = [[0] * (w) for _ in range(h)]
    vis[i][j] = 1
    q.append([i,j])
    
    while q:
        curX, curY = q.popleft()
        for dir in range(4):
            nx = curX + dx[dir]
            ny = curY + dy[dir]
            
            if nx < 0 or nx >= h or ny < 0 or ny >= w:
                continue
            if board[nx][ny] != board[i][j] or vis[nx][ny]:
                continue
            vis[nx][ny] = 1
            board[nx][ny] = c
            q.append([nx, ny])
    board[i][j] = c
    
for i in range(h):
    for j in range(w):
        print(board[i][j], end = " ")
    print()
