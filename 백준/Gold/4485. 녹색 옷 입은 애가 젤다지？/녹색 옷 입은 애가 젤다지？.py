from collections import deque
import sys
input = sys.stdin.readline

def bfs(n, cave, visited):
    dx = [1, -1, 0, 0]
    dy = [0, 0, -1, 1]

    q = deque()
    q.append((0, 0)) # x, y

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if not 0 <= nx < n or not 0 <= ny < n:
                continue
            # 이미 해당 칸에 도착할 수 있는 더 짧은 경로가 있으면 패스
            # = 안하면 메모리 초과
            if visited[nx][ny] <= visited[x][y] + cave[nx][ny]:
                continue

            q.append((nx, ny))
            visited[nx][ny] = visited[x][y] + cave[nx][ny]

idx = 0
while True:
    idx += 1
    n = int(input())
    if n == 0: break

    cave = [list(map(int, input().split())) for _ in range(n)]
    visited = [[1e9 for _ in range(n)] for _ in range(n)]
    visited[0][0] = cave[0][0]

    answer = bfs(n, cave, visited)

    print('Problem ', idx, ': ', visited[n - 1][n - 1], sep='')
