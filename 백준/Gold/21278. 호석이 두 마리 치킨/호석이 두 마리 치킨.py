from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
road = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    road[a].append(b)    
    road[b].append(a)

def bfs(k, i, j):
    visited = [0 for _ in range(n + 1)]
    q = deque()
    q.append((k, 0))
    visited[k] = 1

    while q:
        x, time = q.popleft()

        if x == i or x == j:
          return time  

        for i in road[x]:
            if visited[i] != 0:
                continue

            q.append((i, time + 1))
            visited[i] = 1

answer = 1e9
a = 0
b = 0
for i in range(1, n + 1):
    for j in range(i + 1, n + 1):
        # 건물 i, j에 치킨집
        sum = 0

        # 건물 k로부터 i, j까지의 거리 구하기
        for k in range(1, n + 1):
            if k == i or k == j:
                continue
                
            sum += 2 * bfs(k, i, j)
        
        if sum < answer:
            a = i
            b = j
            answer = sum

print(a, b, answer)