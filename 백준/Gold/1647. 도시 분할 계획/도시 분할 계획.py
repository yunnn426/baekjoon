import sys, heapq

n, m = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(n + 1)]
q = []
visited = [0 for _ in range(n + 1)]

for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    graph[a].append((c, b))
    graph[b].append((c, a))
    
# 1부터 힙에 추가
for i in graph[1]:
    cost, node = i
    heapq.heappush(q, i)
visited[1] = 1

# prim
answer = 0
maxw = 0
while q:
    cost, node = heapq.heappop(q)
    if visited[node] != 0:
        continue

    visited[node] = 1
    answer += cost
    maxw = max(maxw, cost)

    for i in graph[node]:
        c, n = i
        if visited[n] != 0:
            continue
        heapq.heappush(q, i)

print(answer - maxw)
