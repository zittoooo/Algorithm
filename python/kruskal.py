# 특정 원소가 속한 집합 찾기
def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

# 두 원소가 속합 집합 합치기
def union(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

# 노드의 개수와 간선의 개수 입력받기
v, e = map(int, input().split())
parent = [0] * (v+1)
edges = []  # 모든 간선을 담을 리스트
res = 0     # 최소 비용

# 부모 테이블에서 부모를 자기 자신으로 초기화
for i in range(v+1):
    parent[i] = i

# 모든 간선에 대한 정보 입력받기
for _ in range(e):
    a, b, cost = map(int, input().split())
    edges.append([cost, a, b]) # 비용 순으로 오름차순 정렬 하기 위해 비용을 첫번째 원소로 설정 
edges.sort() # 간선을 비용 순으로 오름차순 정렬

for edge in edges:
    cost, a, b = edge
    if find_parent(parent, a) != find_parent(parent, b): # 사이클이 없을 때 집합에 포함
        union(parent, a, b)    
        res += cost
        
print(res)
