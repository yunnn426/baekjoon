from collections import deque
import sys
input = sys.stdin.readline

n, l, r = map(int, input().split())
population = [list(map(int, input().split())) for _ in range(n)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# 인구 이동 조건
# - 땅 간의 차이가 L 이상 R 이하

def bfs(grid, i, j, color):
    q = deque()
    q.append((i, j))
    grid[i][j] = color

    move = False

    while q:
        x, y = q.popleft()

        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]

            if not 0 <= nx < n or not 0 <= ny < n:
                continue
            if not l <= abs(population[x][y] - population[nx][ny]) <= r:
                continue
            if grid[nx][ny] != 0:
                continue

            move = True
            q.append((nx, ny))
            grid[nx][ny] = color
    
    return move

def update(q, new):
    while q:
        x, y = q.popleft()
        population[x][y] = new

def recalculate(visited, grid, i, j):
    q = deque()
    q.append((i, j))
    color = grid[i][j]
    visited[i][j] = 1

    sum = population[i][j]
    cnt = 1
    dq = deque()
    dq.append((i, j))

    while q:
        x, y = q.popleft()

        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]

            if not 0 <= nx < n or not 0 <= ny < n:
                continue
            if visited[nx][ny] != 0 or grid[nx][ny] != color:
                continue
            
            sum += population[nx][ny]
            cnt += 1
            q.append((nx, ny))
            visited[nx][ny] = 1
            dq.append((nx, ny))
    
    if len(dq) != 1:
        update(dq, sum // cnt)

answer = 0
while True:
    # 이동 가능한 땅 찾기     
    color = 1
    grid = [[0 for _ in range(n)] for _ in range(n)]
    move = False
    for i in range(n):
        for j in range(n):
            if grid[i][j] != 0:
                continue
            can = bfs(grid, i, j, color)
            if can:
                move = True
            color += 1

    if not move:
        break

    # 인구 이동 계산
    visited = [[0 for _ in range(n)] for _ in range(n)]
    if move:
        for i in range(n):
            for j in range(n):
                if visited[i][j] != 0:
                    continue
                recalculate(visited, grid, i, j)
    answer += 1

print(answer)