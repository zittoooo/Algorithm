from collections import deque
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
def BFSFire(q, visFire, building):
    while q:
        x,y = q.popleft()
        for dir in range(4):
            nx, ny = x + dx[dir], y + dy[dir]
        
            if nx < 0 or nx >= h or ny < 0 or ny >= w:
                continue
            if building[nx][ny] == '#' or visFire[nx][ny]:
                continue
            q.append([nx, ny])
            visFire[nx][ny] = visFire[x][y] + 1

def BFS(i, j, vis, building, visFire):
    q = deque([[i,j]])
    vis[i][j] = 1
    while q:
        x, y = q.popleft()
        
        for dir in range(4):
            nx, ny = x + dx[dir], y + dy[dir]
            
            if nx < 0 or nx >= h or ny < 0 or ny >= w:
                print(vis[x][y])
                return True
            if building[nx][ny] == '#' or vis[nx][ny]:
                continue
            if visFire[nx][ny] != 0 and visFire[nx][ny] <= vis[x][y] + 1:
                continue
            q.append([nx,ny])
            vis[nx][ny] = vis[x][y] + 1
    
    return False

T = int(input())
while T:
    T -= 1
    q = deque()
    w, h = map(int, input().split())
    building = [input() for _ in range(h)]
    visFire = [[0]*w for _ in range(h)]
    vis = [[0]*w for _ in range(h)]
    
    for i in range(h):
        for j in range(w):
            if building[i][j] == '*':
                q.append([i,j])
                visFire[i][j] = 1
    if q:
        BFSFire(q, visFire, building)
                
    for i in range(h):
        for j in range(w):
            if building[i][j] == '@':
                if not BFS(i, j, vis, building, visFire):
                    print("IMPOSSIBLE")
    
