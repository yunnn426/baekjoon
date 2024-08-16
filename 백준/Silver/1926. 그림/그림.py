from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
paper = [list(map(int, input().split())) for _ in range(n)]
visited = [[0 for _ in range(m)] for _ in range(n)]

def bfs(i, j):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

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
            if visited[nx][ny] != 0 or paper[nx][ny] != 1:
                continue

            q.append((nx, ny))
            visited[nx][ny] = 1
    
    return count

count = 0
answer = 0
for i in range(n):
    for j in range(m):
        if visited[i][j] != 0 or paper[i][j] != 1:
            continue
        
        count += 1
        answer = max(answer, bfs(i, j))
    
print(count, answer, sep="\n")