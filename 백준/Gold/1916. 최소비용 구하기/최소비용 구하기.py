import sys, heapq
INF = 1e8

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    graph[a].append((c, b)) # 비용 - 도착지
start, end = map(int, sys.stdin.readline().split())

distance = [INF for _ in range(n + 1)]
q = []
heapq.heappush(q, (0, start))
# 다익스트라
while q:
    cost, srt = heapq.heappop(q)

    # 도착하면 종료
    if srt == end:
        print(cost)
        break

    for i in graph[srt]:
        c, s = i
        if cost + c < distance[s]: # 갱신
            distance[s] = cost + c
            heapq.heappush(q, (distance[s], s))
