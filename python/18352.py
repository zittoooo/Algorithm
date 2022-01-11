import sys
import heapq
INF = int(1e9)

n, m, k, x = map(int, input().split())  # 도시, 도로, 거리, 출발 도시

dist = [INF] * (n+1)  # 최단 거리 저장
graph = [[]*(n+1) for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())  # a -> b 단방향 도로 존재 
    graph[a].append([1, b])

heap = []
def dijkstra(start):
    heapq.heappush(heap, [0, start])
    dist[start] = 0
    
    while heap:
        cost, node = heapq.heappop(heap) # 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
        
        if dist[node] < cost:
            continue
        
        for c, n in graph[node]:  # 현재 노드와 연결된 모든 노드
            if cost + c < dist[n]:
                dist[n] = cost + c
                heapq.heappush(heap, [cost+c, n])
    
dijkstra(x)

flag = 0
for i in range(1, n+1):
    if dist[i] == k:
        print(i)
        flag = 1
if flag == 0:
    print(-1)
