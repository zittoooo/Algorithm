import sys
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
s = set()  # 집합, 중복 제거

board = [list(map(str, sys.stdin.readline().split())) for _ in range(5)]

def func(i , j, str):
    if len(str) == 6:   # 문자열 길이가 6이되면 집합에 넣고 return
        s.add(str)
        return

    for dir in range(4):
        nx = i + dx[dir]
        ny = j + dy[dir]
        
        if nx < 0 or nx >= 5 or ny < 0 or ny >= 5:
            continue
        func(nx, ny, str+board[nx][ny])
        
for i in range(5):
    for j in range(5):
        str = ""
        func(i,j, str+board[i][j])

print(len(s))
