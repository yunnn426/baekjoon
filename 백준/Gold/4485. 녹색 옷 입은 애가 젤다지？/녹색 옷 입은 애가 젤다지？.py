from collections import deque
import sys
input = sys.stdin.readline

def bfs(n, cave):
    dx = [1, -1, 0, 0]
    dy = [0, 0, -1, 1]

    q = deque()
    q.append((0, 0, cave[0][0])) # x, y, cost
    visited = [[1e9 for _ in range(n)] for _ in range(n)]
    visited[0][0] = cave[0][0]
    answer = 1e9

    while q:
        x, y, cost = q.popleft()

        # 출구 도착
        if x == n - 1 and y == n - 1:   
            answer = min(answer, cost)
            continue

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if not 0 <= nx < n or not 0 <= ny < n:
                continue
            # 이미 해당 칸에 도착할 수 있는 더 짧은 경로가 있으면 패스
            if visited[nx][ny] <= cost + cave[nx][ny]:
                continue

            q.append((nx, ny, cost + cave[nx][ny]))
            visited[nx][ny] = cost + cave[nx][ny]

    return answer

idx = 0
while True:
    idx += 1
    n = int(input())
    if n == 0: break

    cave = [list(map(int, input().split())) for _ in range(n)]

    answer = bfs(n, cave)

    print('Problem ', idx, ': ', answer, sep='')
