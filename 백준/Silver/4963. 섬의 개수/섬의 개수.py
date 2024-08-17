from collections import deque
import sys
input = sys.stdin.readline

def bfs(world, visited, i, j, w, h):
    q = deque()
    q.append((i, j))
    visited[i][j] = 1

    dx = [-1, 1, 0, 0, -1, -1, 1, 1] # 가로, 세로, 대각선 8방향
    dy = [0, 0, -1, 1, -1, 1, -1, 1]

    while q:
        x, y = q.popleft()

        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]

            if not 0 <= nx < h or not 0 <= ny < w:
                continue
            if visited[nx][ny] != 0 or world[nx][ny] != 1:
                continue

            q.append((nx, ny))
            visited[nx][ny] = 1
    
while True:
    w, h = map(int, input().split())

    if w == 0 and h == 0:
        break

    world = [list(map(int, input().split())) for _ in range(h)]
    visited = [[0 for _ in range(w)] for _ in range(h)]

    count = 0
    for i in range(h):
        for j in range(w):
            if visited[i][j] != 0 or world[i][j] != 1:
                continue

            count += 1
            bfs(world, visited, i, j, w, h)
    
    print(count)