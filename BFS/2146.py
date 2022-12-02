import sys
from collections import deque

input = sys.stdin.readline
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

# 섬을  구분하는  bfs
def bfsIsland(i, j):
    global count
    q = deque([[i, j]])
    vis[i][j] = 1
    Map[i][j] = count
    
    while q:
        x, y = q.popleft()
        for dir in range(4):
            nx, ny = x + dx[dir], y + dy[dir]
            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            # 바다거나 이미 방문 했으면
            if Map[nx][ny] == 0 or vis[nx][ny]:
                continue
            q.append([nx, ny])
            vis[nx][ny] = 1
            Map[nx][ny] = count

# 섬마다 각각 가장 짧은 다리 찾기
def bfs(cnt):
    global answer
    dist = [[-1]*n for _ in range(n)]
    q = deque()
    
    for i in range(n):
        for j in range(n):
            if Map[i][j] == cnt:
                q.append([i,j])
                dist[i][j] = 0
    while q:
        x, y = q.popleft()
        for dir in range(4):
            nx, ny = x + dx[dir], y + dy[dir]
            
            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            # 다른 땅을 만나면
            if Map[nx][ny] > 0 and Map[nx][ny] != cnt:
                answer = min(answer, dist[x][y])
                return
            # 방문한 적 없고 바다를 만나면
            if Map[nx][ny] == 0 and dist[nx][ny] == -1:
                q.append([nx, ny])
                dist[nx][ny] = dist[x][y] + 1
                

n = int(input())
Map = [list(map(int, input().split())) for _ in range(n)]
vis = [[0]*n for _ in range(n)]
count = 1
answer = sys.maxsize

for i in range(n):
    for j in range(n):
        # 방문한적 없는 땅일 때
        if not vis[i][j] and Map[i][j] == 1:
            bfsIsland(i, j);
            count += 1
for i in range(1, count):
    bfs(i)
print(answer)
