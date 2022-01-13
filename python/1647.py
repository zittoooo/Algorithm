# https://www.acmicpc.net/problem/1647

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]
    
def union(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

n, m = map(int, input().split())
parent = [0] * (n+1)

for i in range(1,n+1):
    parent[i] = i

edges = []  # 간선들을 담을 리스트

for _ in range(m):
    a, b, c = map(int, input().split())
    edges.append([c,a,b])
edges.sort() # 비용순으로 오름차순 정렬

big = 0
total = 0
for edge in edges:
    cost, a, b = edge
    if find_parent(parent, a) != find_parent(parent, b):
        union(parent, a,b)
        total += cost
        big = max(big, cost)
    
print(total - big)
