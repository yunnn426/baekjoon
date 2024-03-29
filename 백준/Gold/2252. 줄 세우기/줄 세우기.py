import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
arr = [[] for _ in range(n + 1)]
indegree = [0 for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    arr[a].append(b)
    indegree[b] += 1 # b노드의 진입차수 ++

q = deque()
for i in range(1, n + 1):
    if indegree[i] == 0:
        q.append(i)

while q:
    v = q.popleft()
    print(v, end=" ")
    # 간선 삭제
    for i in arr[v]:
        indegree[i] -= 1 # 진입차수 --
        if indegree[i] == 0: # 진입차수가 0이 되면 큐에 추가
            q.append(i) 