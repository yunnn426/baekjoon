import sys

# 부모 찾기
def find(parent, node):
    if parent[node] == node: 
        return node
    
    return find(parent, parent[node]) # 재귀로 부모 찾기

# 부모 합치기
def union(parent, node1, node2):
    root1 = find(parent, node1)
    root2 = find(parent, node2)
    if root1 > root2:
        parent[root1] = root2
    elif root1 < root2:
        parent[root2] = root1

v, e = map(int, sys.stdin.readline().split())
edges = []
parents = [i for i in range(v + 1)] # 초기 부모: 자기 자신
for _ in range(e):
    a, b, c = map(int, sys.stdin.readline().split())
    edges.append((c, a, b))

edges.sort()

answer = 0
# 크루스칼
for edge in edges:
    w, a, b = edge
    if find(parents, a) != find(parents, b): # 부모가 같지 않으면
        union(parents, a, b) # 합침
        answer += w

print(answer)
