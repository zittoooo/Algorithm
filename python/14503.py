dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def turn_left():
    global d
    d -= 1
    if d == -1:
         d = 3

n, m = map(int, input().split())     # 행, 열 크기 입력
r, c, d = map(int, input().split())  # 처음 x, y, 방향 좌표
board =[list(map(int, input().split())) for _ in range(n)]
vis = [[0] * m for _ in range(n)]          # 청소했는지 표시하는 용도
vis[r][c] = 1

res = 1
turn = 0
x, y = r, c
while True:
    turn_left()
    turn += 1

    nx, ny = x + dx[d] , y + dy[d]
    if 0 <= nx < n and 0 <= ny < m:
        if vis[nx][ny] == 0 and board[nx][ny] == 0: # 청소할 공간 존재
            x, y = nx, ny
            vis[nx][ny] = 1
            res += 1
            turn = 0
    if turn == 4 :   # 4번 회전함
        nx = x - dx[d]  # 후진했을 때 x 좌표
        ny = y - dy[d]  # 후진했을 때 y 좌표
        if board[nx][ny] == 0:  # 후진 가능, 현재좌표 후진한좌표로 바꾸고 turn 초기화
            x = nx
            y = ny
            turn = 0
        else:  # 후진 불가능, 동작 멈춤
            break

print(res)
