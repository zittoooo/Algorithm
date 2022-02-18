import heapq
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
INF = int(1e9)
cnt = 0

while True:
    n = int(input())
    if n == 0:
        exit()
    cnt += 1
    cave = [[INF]*(n) for _ in range(n)]
    board = [list(map(int, input().split())) for _ in range(n)]
    
    heap = []
    heapq.heappush(heap, (board[0][0], (0,0)))
    cave[0][0] = board[0][0]
    
    while heap:
        cost, xy = heapq.heappop(heap)
        x, y = xy
        if cave[x][y] < cost:
            continue
        for dir in range(4):
            nx, ny = x + dx[dir], y + dy[dir]
            if 0 <= nx < n and  0 <=  ny < n:
                if cost + board[nx][ny] < cave[nx][ny]:
                    cave[nx][ny] = cost + board[nx][ny]
                    heapq.heappush(heap, (cost+board[nx][ny], (nx, ny)))
    print("Problem " + str(cnt) + ": " + str(cave[n-1][n-1]))
