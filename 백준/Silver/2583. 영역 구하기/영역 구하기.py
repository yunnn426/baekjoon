from collections import deque
import sys
input = sys.stdin.readline

m, n, k = list(map(int, input().split()))
visited = [[0 for _ in range(m)] for _ in range(n)]
rect = set()

def bfs(i, j):
    dx = [-1, 1, 0, 0]
    dy = [0, 0 , -1, 1]

    q = deque()
    q.append((i, j))
    visited[i][j] = 1
    count = 0

    while q:
        x, y = q.popleft()
        count += 1

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if not 0 <= nx < n or not 0 <= ny < m:
                continue
            if visited[nx][ny] != 0 or (nx, ny) in rect:
                continue

            q.append((nx, ny))
            visited[nx][ny] = 1
    
    return count

# 좌표에 해당하는 사각형 위치 찾기
for _ in range(k):
    x1, y1, x2, y2 = list(map(int, input().split()))

    for i in range(x1, x2):
        for j in range(y1, y2):
            rect.add((i, j))
    
count = 0
areas = []
for i in range(n):
    for j in range(m):
        if visited[i][j] != 0 or (i, j) in rect:
            continue

        count += 1
        area = bfs(i, j)
        areas.append(area)

print(count)
areas = sorted(areas)
print(*areas)