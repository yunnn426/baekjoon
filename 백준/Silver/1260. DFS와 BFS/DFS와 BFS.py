import sys
from collections import deque

n, m, v = map(int, sys.stdin.readline().split())
graph = [[] for i in range(n + 1)]

# 각 노드에 연결된 정점 배열
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

for i in graph:
    i.sort()

# DFS
def dfs(x):
    print(x, end=" ")
    for i in graph[x]:
        if visited[i] != 0:
            continue
        visited[i] = 1
        dfs(i)

# BFS
def bfs(x):
    while q:
        x = q.popleft()
        print(x, end=" ")
        for i in graph[x]:
            if visited[i] != 0:
                continue
            visited[i] = 1
            q.append(i)

# print dfs
visited = [0 for _ in range(n + 1)]
visited[v] = 1
dfs(v)

print()

# print bfs
visited = [0 for _ in range(n + 1)]
q = deque()
visited[v] = 1
q.append(v)
bfs(v)