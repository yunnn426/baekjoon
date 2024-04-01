import sys
from collections import deque

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
graph = [[] for _ in range(n + 1)]
visited = [0 for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

answer = 0
q = deque()
visited[1] = 1
q.append(1)
while q:
    node = q.popleft()
    answer += 1
    
    for i in graph[node]:
        if visited[i] != 0:
            continue
        visited[i] = 1
        q.append(i)

print(answer - 1)