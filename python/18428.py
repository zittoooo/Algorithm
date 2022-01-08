from collections import deque
from itertools import combinations
import copy
dx = [-1, 0, 1, 0]
dy = [0, 1, 0 ,-1]

n = int(input())
board = [list(input().split()) for _ in range(n)]
teacher =[]
empty = []

def bfs():
    test = copy.deepcopy(board)
    q = deque(teacher)
    
    while q:
        curX, curY = q.popleft()
        for dir in range(4):
            tmp_x, tmp_y = curX, curY
            while True:  # 한 방향으로 쭉
                nx = tmp_x + dx[dir]
                ny = tmp_y + dy[dir]
                if 0 <= nx < n and 0 <= ny < n:
                    if test[nx][ny] == 'X':
                        test[nx][ny] == 'T'
                    elif test[nx][ny] == 'O':
                        break
                    elif test[nx][ny] == 'S':  # 학생을 찾았다
                        return False
                    tmp_x, tmp_y = nx, ny
                else:     # test를 벗어남, 방향을 바꾸자
                    break
    return True  # 학생을 못찾았다

for i in range(n):
    for j in range(n):
        if board[i][j] == 'T':
            teacher.append([i,j])
        elif board[i][j] == 'X':
            empty.append([i,j])

check = False
for wall in list(combinations(empty, 3)):
    for x, y in wall:
        board[x][y] = 'O'
    if bfs() == True:  # 학생을 찾았다
        check = True
        break
    for x, y in wall:
        board[x][y] = 'X'

if check:
    print("YES")
else:
    print("NO")
