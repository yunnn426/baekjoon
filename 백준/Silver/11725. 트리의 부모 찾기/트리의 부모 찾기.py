import sys
n = int(sys.stdin.readline())
sys.setrecursionlimit(10**6)
graph = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

answer = [0 for _ in range(n + 1)]
visited = [0 for _ in range(n + 1)]

def dfs(x):
    for i in graph[x]:
        if visited[i] != 0:
            continue
        answer[i] = x
        visited[i] = 1
        dfs(i)

dfs(1)

for i in range(2, n + 1):
    print(answer[i])