import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
m = int(input())
city = [[] for _ in range(n + 1)]
indegree = [0 for _ in range(n + 1)]
distance = [0 for _ in range(n + 1)]
prev = [[] for _ in range(n + 1)]

# input
for _ in range(m):
    s, e, t = map(int, input().split())
    city[s].append((t, e)) # 비용 - 도착 도시
    indegree[e] += 1
srt, dst = map(int, input().split())

# topology sort
q = deque()
q.append(srt)
maxtime = 0
while q:
    node = q.popleft()
    
    # print("cost, node: ", cost, node)
    for i in city[node]:
        c, nd = i
        indegree[nd] -= 1
        if distance[nd] <= distance[node] + c:
            # 이전 노드 정보 갱신
            if distance[nd] < distance[node] + c:
                prev[nd] = [node]
            else:
                prev[nd].append(node)
            distance[nd] = distance[node] + c
            
        # 진입차수 0인 노드 추가
        if indegree[nd] == 0:
            q.append(nd)

# 경로 개수 찾기
max_route = set()
q = deque()
q.append(dst)
while q:
    idx = q.popleft()

    for i in prev[idx]:
        if (idx, i) not in max_route:
            max_route.add((idx, i))
            q.append(i)

print(distance[dst])
print(len(max_route))