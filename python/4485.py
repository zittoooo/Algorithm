from collections import deque
import sys
INF = int(1e9)

q = deque()
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
cnt = 0        # 테스트 케이스 반복 횟수
while True:
    n = int(input())  # N * N 칸
    if n == 0:
        break
    cnt += 1
    board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    dist = [[INF] * (n) for _ in range(n)]  # 최단 거리 테이블 모두 무한으로 초기화
    dist[0][0] = board[0][0]  
    q.append([0, 0])  # 시작 위치 큐에 삽입

    while q:
        curX, curY = q.popleft()
    
        for dir in range(4):
            nx = curX + dx[dir]
            ny = curY + dy[dir]
            if 0 <= nx < n and 0 <= ny < n:  # 맵의 범위를 벗어나지 않는 경우
                # 현재 노드를 거쳐 다음 노드로 이동하는 거리가 더 짧은 경우
                if dist[nx][ny] > dist[curX][curY] + board[nx][ny]:
                    dist[nx][ny] = dist[curX][curY] + board[nx][ny]
                    q.append([nx, ny])
                    
    print('Problem {}: {}'.format(cnt, dist[n-1][n-1]))
