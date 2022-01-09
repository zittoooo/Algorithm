import heapq

def dijkstra(start, dist, graph):
    dist[start] = 0
    heap = []
    heapq.heappush(heap, (0, start))
    
    while heap:
        cost, node = heapq.heappop(heap)
        if dist[node] < cost:
            continue
        for c, n in graph[node]:
            if cost + c < dist[n]:
                dist[n] = cost + c  # 최소 비용으로 갱신
                heapq.heappush(heap, (cost+c, n))
            
def solution(N, road, K):
    INF = int(1e9)
    dist = [INF] * (N+1)  # 1번 마을과 떨어진 거리 저장 리스트
    graph = [[] for _ in range(N+1)]
    
    for r in road:
        a,b,c = r  # a,b = 마을 / c = 시간
        graph[a].append([c,b])
        graph[b].append([c,a])
    dijkstra(1, dist, graph)  # 1번에서 시작
    
    return len([d for d in dist if d <= K])
