import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
maze = [[] for _ in range(n)]
visited = [[0 for _ in range(m)] for _ in range(n)]
for i in range(n):
    row = sys.stdin.readline().strip()
    for j in range(m):
        maze[i].append(int(row[j]))

q = deque()
q.append((0, 0, 1)) # x - y - step
visited[0][0] = 1
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
answer = 0

while q:
    x, y, cnt = q.popleft()
    if x == n - 1 and y == m - 1:
        answer = cnt
        break

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue
        if visited[nx][ny] != 0:
            continue
        if maze[nx][ny] == 0:
            continue
        visited[nx][ny] = 1
        q.append((nx, ny, cnt + 1))

print(answer)