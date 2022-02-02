from collections import deque

dx = [-1, 0, 1, 0]   
dy = [0, 1, 0, -1]

def bfs(board, cost, direction):
    n = len(board)
    dist = [[1e9] * n for _ in range(n)]
    dist[0][0] = 0
    q = deque()
    q.append([0,0, cost, direction])
    
    while q:
        x, y, c, d = q.popleft()
        
        for dir in range(4):
            nx, ny, ncost = x + dx[dir], y + dy[dir], c
            while 0 <= nx < n and 0 <= ny < n:
                if board[nx][ny] == 1:
                    break
                ncost += 100 if d == dir else 600
                if dist[nx][ny] > ncost:                    
                    dist[nx][ny] = ncost
                    q.append([nx,ny, ncost, dir])
                nx += dx[dir]
                ny += dy[dir]
    return dist[n-1][n-1]
    
def solution(board):
    answer = 0
    
    return min(bfs(board, 0, 1), bfs(board, 0, 2))  # 시작 방향 : 오른쪽, 아래쪽 
