import sys

n, m = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(n + 1)]
visited = [0 for _ in range(n + 1)]
for _ in range(m):
    u, v = map(int, sys.stdin.readline().split())
    graph[u].append(v)
    graph[v].append(u)

def dfs(x):
    for i in graph[x]:
        if visited[i] != 0:
            continue
        visited[i] = 1
        dfs(i)

answer = 0
for i in range(1, n + 1):
    if visited[i] != 0:
        continue
    answer += 1
    visited[i] = 1
    dfs(i)

print(answer)