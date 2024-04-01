import sys
from collections import deque

n, m, k, x = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(n + 1)]
visited = [0 for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)

answer = []
q = deque()
visited[x] = 1
q.append((x, 0))
while q:
    node, cnt = q.popleft()
    if cnt == k:
        answer.append(node)
    
    for i in graph[node]:
        if visited[i] != 0:
            continue
        visited[i] = 1
        q.append((i, cnt + 1))

answer.sort()
if len(answer) != 0:
    for i in answer:
        print(i)
else:
    print(-1)