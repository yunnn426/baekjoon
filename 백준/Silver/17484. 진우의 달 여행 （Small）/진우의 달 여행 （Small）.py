from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
fuel = [[0 for _ in range(m)] for _ in range(n + 1)]

for i in range(n):
    lst = list(map(int, input().split()))
    for j in range(m):
        fuel[i][j] = lst[j]

min_fuel = 1e9
# 최상단 첫 줄 아무 곳에서나 출발 가능
for i in range(m):
    q = deque()
    q.append((3, 0, i, fuel[0][i])) # 직전 움직임 방향, x, y, cost

    visited = [[0 for _ in range(m)] for _ in range(n + 1)]
    visited[0][i] = 1

    # 대각선 아래, 바로 아래로 이동 가능
    dx = [1, 1, 1]
    dy = [-1, 0, 1]

    while q:
        before, x, y, cost = q.popleft()

        # 달에 도착
        if x == n:
            min_fuel = min(min_fuel, cost)
    
        for k in range(3):
            if before == k:
                continue

            nx = x + dx[k]
            ny = y + dy[k]

            if not 0 <= nx <= n or not 0 <= ny < m:
                continue
            
            q.append((k, nx, ny, cost + fuel[nx][ny]))

print(min_fuel)