dx = [-1, 0, 1, 0]  # 북동남서
dy = [0, 1, 0, -1]

def turn_left():
    global d
    d -= 1
    if d == -1:
        d = 3

n, m = map(int, input().split())
x, y, d = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
vis = [[0]*m for _ in range(n)]
vis[x][y] = 1

step = 1
turn = 0
while True:
    turn_left()
    nx = x + dx[d]
    ny = y + dy[d]
    if board[nx][ny] == 0 and vis[nx][ny] == 0:
        x = nx
        y = ny
        vis[x][y] = 1
        step += 1
        turn = 0
        continue
    else:
        turn += 1
    if turn == 4:  # 뒤로 1칸
        nx = x - dx[d]
        ny = y - dy[d]
        if board[nx][ny] == 0:  # 뒤로 갈 수 있다
            x = nx
            y = ny
            turn = 0
        else:                   # 뒤로도 못간다
            break
print(step)
