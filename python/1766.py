import heapq
q = []

n, m = map(int, input().split())

indegree = [0] * (n+1)
graph = [[] * (n+1) for _ in range(n+1)] # 각 노드에 연결된 간선 정보를 담기 위한 연결 리스트 초기화

for _ in range(m):
    a,b = map(int, input().split())
    graph[a].append(b)  # a -> b 순서
    indegree[b] += 1  # b의 진입차수 1 증가
    
for i in range(1, n+1):
    if indegree[i] == 0:  # 진입차수가 0인 노드 힙에 삽입
        heapq.heappush(q, i)

res = []  # 결과를 저장할 리스트

while q:
    now = heapq.heappop(q)
    res.append(now)
    
    for node in graph[now]:
        indegree[node] -= 1  # 해당 노드와 연결된 노드들의 진입차수 1 빼기
        if indegree[node] == 0:  # 새롭게 진입차수가 0이 되는 노드를 힙에 삽입
            heapq.heappush(q, node)
    

for i in res:
    print(i, end=' ')
