from collections import deque
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

# 빙산 덩어리 개수 세기 BFS
def BFS(i, j, iceBoard, vis):
    q = deque()
    q.append([i,j])
    vis[i][j] = 1
    
    while q:
        x, y = q.popleft()
        for dir in range(4):
            nx, ny = x + dx[dir], y + dy[dir]
            if nx < 0 or nx >= h or ny < 0 or ny >= w:
                continue
            if iceBoard[nx][ny] == 0 or vis[nx][ny]:
                continue
            q.append([nx,ny])
            vis[nx][ny] = 1

h, w = map(int, input().split())
iceBoard = [list(map(int, input().split())) for _ in range(h)]
year = 0
meltBoard = [[0]*w for _ in range(h)]
       
while True:
    ice = 0
    year += 1

    for i in range(h):
        for j in range(w):
            if iceBoard[i][j] != 0: # 빙산이면 상하좌우 물일때 녹이기
                for dir in range(4):
                    nx, ny = i + dx[dir], j + dy[dir]
                    if nx < 0 or nx >= h or ny < 0 or ny >= w:
                        continue
                    if iceBoard[nx][ny] == 0:
                        meltBoard[i][j] += 1
    # 빙산 녹이기
    for i in range(h):
        for j in range(w):
            iceBoard[i][j] -= min(meltBoard[i][j], iceBoard[i][j])
            meltBoard[i][j] = 0

    vis = [[0]*w for _ in range(h)]                    
    for i in range(h):
        for j in range(w):
            if iceBoard[i][j] > 0 and vis[i][j] == 0: # 빙하면
                BFS(i, j, iceBoard, vis)
                ice += 1
    # 빙산이 분리되면
    if ice >= 2: 
        print(year)
        exit(0)
    
    cnt = 0
    for i in range(h):
        for j in range(w):
            if iceBoard[i][j] == 0:
                cnt += 1
            if cnt == w * h: # 빙산이 다 녹을 때까지 분리되지 않으면
                print(0)
                exit(0)
