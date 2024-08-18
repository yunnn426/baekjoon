from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
world = [list(input().strip()) for _ in range(n)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(visited, i, j):
    q = deque()
    q.append((i, j))
    visited[i][j] = 1
    now = world[i][j]

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if not 0 <= nx < n or not 0 <= ny < n:
                continue
            if visited[nx][ny] != 0 or world[nx][ny] != now:
                continue
                
            q.append((nx, ny))
            visited[nx][ny] = 1

def blind_bfs(visited, i, j):
    q = deque()
    q.append((i, j))
    visited[i][j] = 1
    now = world[i][j]

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if not 0 <= nx < n or not 0 <= ny < n:
                continue
            if visited[nx][ny] != 0:
                continue
            if (now == 'R' or now == 'G') and world[nx][ny] == 'B':
                continue
            if now == 'B' and world[nx][ny] != 'B':
                continue
                
            q.append((nx, ny))
            visited[nx][ny] = 1

# 적록색약이 아닌 사람이 봤을 때 구역의 수
visited = [[0 for _ in range(n)] for _ in range(n)]
count1 = 0
for i in range(n):
    for j in range(n):
        if visited[i][j] != 0:
            continue
        
        count1 += 1
        bfs(visited, i, j)

# 적록색약인 사람이 봤을 때 구역의 수
visited = [[0 for _ in range(n)] for _ in range(n)]
count2 = 0
for i in range(n):
    for j in range(n):
        if visited[i][j] != 0:
            continue
        
        count2 += 1
        blind_bfs(visited, i, j)

print(count1, count2)