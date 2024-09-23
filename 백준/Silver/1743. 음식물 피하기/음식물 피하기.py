from collections import deque
import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())
food = {tuple(map(int, input().split())) for _ in range(k)}
visited = [[0 for _ in range(m + 1)] for _ in range(n + 1)]

def bfs(i, j):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    q = deque()
    q.append((i, j))
    visited[i][j] = 1
    answer = 0

    while q:
        x, y = q.popleft()
        answer += 1

        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            
            if not 0 < nx <= n or not 0 < ny <= m:
                continue
            if visited[nx][ny] != 0 or (nx, ny) not in food:
                continue
            
            q.append((nx, ny))
            visited[nx][ny] = 1
    
    return answer

answer = 0
for i in range(1, n + 1):
    for j in range(1, m + 1):
        if visited[i][j] != 0 or (i, j) not in food:
            continue

        answer = max(answer, bfs(i, j))

print(answer)