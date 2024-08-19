from collections import deque
import sys
input = sys.stdin.readline

m, n = map(int, input().split())
grid = [list(map(int, input().strip())) for _ in range(m)]
visited = [[0 for _ in range(n)] for _ in range(m)]

def bfs(i):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    q = deque()
    q.append((0, i))
    visited[0][i] = 2

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if not 0 <= nx < m or not 0 <= ny < n:
                continue
            if visited[nx][ny] != 0 or grid[nx][ny] != 0:
                continue

            q.append((nx, ny))
            visited[nx][ny] = 2 # 전류가 흐르면 2로

# outer side에서 bfs 수행
for i in range(n):
    if visited[0][i] != 0 or grid[0][i] != 0:
        continue

    bfs(i)

elec = False
for i in range(n):
    if visited[m - 1][i] == 2:
        elec = True

if elec:
    print('YES')
else:
    print('NO')