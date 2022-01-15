from collections import deque
INF = (1e9)
q = deque()


n = int(input())
graph = [[0]*(n+1) for _ in range(n+1)]
time = [0] * (n+1)
indegree = [0] * (n+1)
d = [0] * (n+1)

for node in range(1, n+1):
    line = list(map(int, input().split()))

    time[node] = line[0]
    for element in line[1:-1]:
        graph[element].append(node)
        indegree[node] += 1
        
for node in range(1, n+1):
    if indegree[node] == 0:
        q.append(node)
        d[node] = time[node]
        
while q:
    n = q.popleft()
    
    for node in graph[n]:
        d[node] = max(d[node], d[n] + time[node])
        indegree[node] -= 1
        if indegree[node] == 0:
            q.append(node)
    
for i in range(1, len(d)):
    print(d[i])
