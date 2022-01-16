from collections import deque
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def solution(places):
    answer = []
    for place in places:
        map = [list(p) for p in place]
        
        flag = True
        for i in range(5):
            for j in range(5):
                if map[i][j] == 'P' and flag:
                    q = deque()
                    q.append([i,j])
                    dist = [[-1] * 5 for _ in range(5)]
                    dist[i][j] = 0
        
                    while q and flag:
                        x, y = q.popleft()
                        for dir in range(4):
                            nx, ny = x + dx[dir], y + dy[dir]
                            if nx < 0 or nx >= 5 or ny < 0 or ny >= 5:
                                continue
                            if map[nx][ny] == 'X' or dist[x][y] >= 2 or dist[nx][ny] >= 0:
                                continue
                            if map[nx][ny] == 'O':
                                q.append([nx,ny])
                                dist[nx][ny] = dist[x][y] + 1
                            if map[nx][ny] == 'P':
                                flag = False
                                answer.append(0)
                                break
        
        if flag:
            answer.append(1)
    return answer
